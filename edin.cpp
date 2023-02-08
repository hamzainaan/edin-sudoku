#include <functional>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <limits>

//Main sudoku vector
//9x9 sudoku bulmacalarını depolayacak vektör.
//IMPORTANT: If you want to use with higher performance, does not change anything.
//IMPORTANT: For slower performance, activate the std::vector instead.

//std::vector<std::vector<int>> su(9, std::vector<int>(9));
int su[9][9];

//Variables
static int current_puzzle = 0, solutions = 1;

//Jump to the specific line in multiple sudoku puzzle entry cases.
//Dosyadan birçok sudoku bulmacası çözmek istenildiğinde bu kod,
//belirtilen satıra atlar.

std::fstream& jump(std::fstream& file, unsigned int line) {
    std::string buffer;
    file.seekg(std::ios::beg);
    for (unsigned int i = 1; i < line; ++i) {
        std::getline(file, buffer);
        if (file.eof()) {
            file.clear();
            break;
        }
    }
    return file;
}

//Determine the mid square of the 3x3 matrix.
//Sudokuyu 3x3'lük matrislere bölersek, her bir matrisin
//ortasındaki kareyi işaret eden bir fonksiyon.
//Örn: [1][1], sol üstteki 3x3 karenin orta karesidir.

int mid_square(int d) {
    
    return ((d / 3) * 3);
}

//Check if the number already exists in entire column or row.
//Belirtilen sayı aynı satın ya da sütunda mevcut mu?

int check(int r, int c, int d) {
    
    for(int i=0; i<9; i++) {
        if(su[r][i] == d || su[i][c] == d) {
            return 0;
        }
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(su[mid_square(r) + i][mid_square(c) + j] == d) {
                return 0;
            }
        }
    }
    
    //Eğer bu fonksiyon yukarıdaki döngülerden sonra 0 dönmediyse, belirtilen sayı o kareye uygundur.
    return 1;
}

//Print the result.
//Sonucu ekrana yazdırır.

void print() {

    std::cout << solutions << ".solution:\n\n";

    for (const auto& p : su) {
        for (const auto& pr : p) {
            std::cout << pr << " ";
        }

    std::cout << std::endl;
  }

    solutions++;
    std::cout << std::endl;
}

//Main evaluation. Using backtracking algorithm.
//Çözücü fonksiyonumuz budur. Backtracking algoritması kullanıyoruz.
//Yani birden ona kadar olan sayıları tek tek check() ettirip uygun olanı koyar.

void eval() {
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(!su[i][j]) {
                for(int k=1; k<10; k++) {
                    if(check(i, j, k)) {
                        
                        //Assign first.
                        su[i][j] = k;
                        
                        //Backtracking.
                        eval();
                        
                        //If any number fits, then assign back to zero.
                        su[i][j] = 0;
                        
                    }
                }
                
                return;
            }
        }
    }

    print();
}

//Check the arguments.
//Program konsol tabanlı olduğundan, parametre olarak kaç adet bulmacanın girilmesi gerektiği bulmalıyız.

void check_args(int a, char* b[]) {

    if(a != 3 || std::string(b[1]).find_first_not_of("0123456789") != std::string::npos) {
        std::cerr << "Wrong argument. Program ends.\nHatalı giriş." << std::endl;
    }

    //argv[2] is the path of the puzzle file.
    std::fstream sudoku(b[2], std::ios::in);
    sudoku.seekg(0, std::ios::end);

    if(!sudoku || !sudoku.tellg()) {
        sudoku.close();
        std::cerr << "File or puzzles not found. Program ends." << std::endl;
    }
}

//Count time.
//Bulmacaları toplamda kaç ms'de çözdüğünü sapta.
void magic(std::function<void()> s) {

    auto f = std::chrono::high_resolution_clock::now();

    s();

    auto l = std::chrono::high_resolution_clock::now();

    //Find difference.
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(l - f);

    //Print each puzzle's solve time.
    std::cout << "This puzzle has been solved in "
              << diff.count()
              << "ms."
              << std::endl;

}

int main(int argc, char* argv[]) {


    //Check if everything's okey.
    check_args(argc, argv);

    //Solve.
    for(int i=1; i<std::stoi(argv[1]) + 1; i++) {

        //Read from file.
        std::fstream sudoku(argv[2], std::ios::in);

        //Reset.
        solutions = 1;

        //Jump to the specific line.
        jump(sudoku, (10 * i) - 9);

        //Fill vector with the current puzzle.
        for(int j=0; j<9; j++) {
            for(int k=0; k<9; k++) {
                sudoku >> su[j][k];
            }
        }

        //To know which puzzle we are in, we must increase this value after each solution.
        current_puzzle++;

        //Evaluate.
        std::cout << "\n\nPuzzle " 
                  << current_puzzle 
                  << "\n----------\n";
        magic(eval);
    }

    return 0;
}
