.PHONY:all clean
CC=gcc
FLAGS=-Wall -Werror
SD=~/geometry/src/
OD=~/geometry/build/
EXECUTABLE=~/geometry/bin/geom.exe
all: $(EXECUTABLE)


$(EXECUTABLE): $(OD)geom.o $(OD)perpl.o
	$(CC) -g $(FLAGS) -o $(EXECUTABLE) $(OD)geom.o $(OD)perpl.o -lm
$(OD)geom.o: $(SD)geom.cpp
	$(CC) $(FLAGS) -c -o $(OD)geom.o $(SD)geom.cpp -lm
$(OD)perpl.o: $(SD)perpl.cpp
	$(CC) $(FLAGS) -c -o $(OD)perpl.o $(SD)perpl.cpp -lm
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o
