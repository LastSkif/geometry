.PHONY:all clean
CC=gcc
FLAGS=-Wall -Werror
SD=~/geometry/src
OD=~/geometry/build
EXECUTABLE=~/geometry/bin/geometry.exe
all: $(EXECUTABLE)


$(EXECUTABLE): $(OD) perpl.o $(main.o)
	$(CC) -g $(FLAGS) -o $(EXECUTABLE) $(OD)perpl.o $(OD)main.o -lm
$(OD)perpl.o: $(SD)perpl.cpp
	$(CC) $(FLAGS) -c -o $(OD)perpl.o $(SD)perpl.cpp -lm
$(OD)main.o: $(SD)main.cpp
	$(CC) $(FLAGS) -c -o $(OD)main.o $(SD)main.cpp -lm
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o
