.PHONY:all clean
CC=gcc
FLAGS=-Wall -Werror
TESTFLAGS=-I thirdparty -I src
SD=src/
OD=build/src/
ODT=build/test/
EXECUTABLE=bin/geom.exe
EXE=bin/test.exe
all: build/src $(EXECUTABLE)

build/src:
	mkdir build/src -p

$(EXECUTABLE): $(OD)geom.o $(OD)perpl.o $(OD)pl.o $(OD)pr.o
	$(CC) -g $(FLAGS) -o $(EXECUTABLE) $(OD)geom.o $(OD)perpl.o $(OD)pl.o $(OD)pr.o -lm
$(OD)geom.o: $(SD)geom.cpp
	$(CC) $(FLAGS) -c -o $(OD)geom.o $(SD)geom.cpp -lm
$(OD)perpl.o: $(SD)perpl.cpp
	$(CC) $(FLAGS) -c -o $(OD)perpl.o $(SD)perpl.cpp -lm
$(OD)pl.o: $(SD)pl.cpp
	$(CC) $(FLAGS) -c -o $(OD)pl.o $(SD)pl.cpp -lm
$(OD)pr.o: $(SD)pr.cpp
	$(CC) $(FLAGS) -c -o $(OD)pr.o $(SD)pr.cpp -lm
	


test: build/test $(EXE)

build/test:
	mkdir build/test -p

$(EXE): $(ODT)main.o $(ODT)perpl.o $(ODT)pl.o $(ODT)pr.o
	$(CC) $(FLAGS) -o $(EXE) $(ODT)main.o $(ODT)perpl.o $(ODT)pl.o $(ODT)pr.o -lm
$(ODT)main.o: test/main.c
	$(CC) $(CFLAGS) $(TESTFLAGS) -c test/main.c -o $(ODT)main.o
$(ODT)perpl.o: $(SD)perpl.cpp $(SD)ppl.h
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $(SD)perpl.cpp -o $(ODT)perpl.o
$(ODT)pl.o: $(SD)pl.cpp $(SD)ppl.h
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $(SD)pl.cpp -o $(ODT)pl.o
$(ODT)pr.o: $(SD)pr.cpp $(SD)ppl.h
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $(SD)pr.cpp -o $(ODT)pr.o



clean:
	rm -rf $(EXECUTABLE) $(EXE) $(OD)*.o $(ODT)*.o


