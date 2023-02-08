OBJS	= edin.o
SOURCE	= edin.cpp
OUT		= edin
CC	 	= g++
FLAGS 	= -g -c -Wall -Wextra -pedantic -O3

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

edin: edin.cpp
	$(CC) $(FLAGS) edin.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)