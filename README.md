# Edin Sudoku Solver

  

Edin is a sudoku puzzle solving program in C++ based on the Backtracking algorithm. Using Edin, you can solve a given sudoku puzzle in milliseconds. Multiple puzzle solving support is available. Edin can solve multiple puzzles at the same time, very fast. It can also find all correct variations of each puzzle.

  

# How can we compile Edin?

  

To use Edin, you first need to compile the program. If you already have the gcc compiler on your system, you can use the following line of code to quickly compile Edin and make it ready to use.

  

```

make edin && make all

```

  

# Usage

  

Once you have successfully compiled Edin, you need to create a text file and place the sudoku puzzle you want to solve in it.

  

When writing your Sudoku puzzles to a text file, you should pay attention to the following. Otherwise Edin will show an error message on the screen.

  

> The format of the sudoku puzzle you have should be such thatthere is a space between each element. Also, since the sudoku board is a square matrix, you must provide a 9x9 matrix input.

> If more than one puzzle is to be entered, each puzzle should be separated by *1 line*.

# Approved Input Type
```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 0 1 9 0 0 5
0 0 0 0 0 0 0 0 0

9 0 3 5 6 0 4 0 0
0 0 0 0 0 1 0 6 0
0 5 0 0 0 2 0 0 0
4 0 0 0 0 0 0 0 7
0 9 0 3 8 0 0 2 0
0 0 0 0 0 5 0 0 0
0 0 8 0 0 0 2 0 0
0 0 0 0 1 0 0 0 0
0 3 0 6 9 0 0 8 0
```

Once you have correctly wrote your Sudoku puzzles into your text file, you can save and close the file. After that, start a terminal at the location of Edin and your text file. Enter the following command into the terminal and you will get the solutions.
```
./edin <number_of_puzzles> <path_to_the_text_file>
```

# Screenshot(s)
![](https://dl.inanweb.ml/edin.png)
