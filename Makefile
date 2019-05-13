.PHONY:all clean
CC=gcc
FLAGS=-Wall -Werror
TESTFLAGS=-I thirdparty src
SD=src/
OD=build/src/
ODT=build/test/
EXECUTABLE=bin/geom.exe
EXE=bin/test.exe
all: build/src $(EXECUTABLE)

build/src:
	mkdir build/src -p

$(EXECUTABLE): $(OD)geom.o $(OD)perpl.o
	$(CC) -g $(FLAGS) -o $(EXECUTABLE) $(OD)geom.o $(OD)perpl.o -lm
$(OD)geom.o: $(SD)geom.cpp
	$(CC) $(FLAGS) -c -o $(OD)geom.o $(SD)geom.cpp -lm
$(OD)perpl.o: $(SD)perpl.cpp
	$(CC) $(FLAGS) -c -o $(OD)perpl.o $(SD)perpl.cpp -lm


test: build/test $(EXE)

build/test:
	mkdir build/test -p

$(EXE): $(ODT)main.o $(ODT)perpl.o
	$(CC) $(FLAGS) -o $(EXE) $(ODT)main.o $(ODT)perpl.o -lm
$(ODT)main.o: test/main.c
	$(CC) $(CFLAGS) $(TESTFLAGS) -c test/main.c -o $(ODT)main.o
$(ODT)perpl.o: src/perpl.cpp src/ppl.h
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $(SD)perpl.cpp $(ODT)perpl.o



clean:
	rm -rf $(EXECUTABLE) $(EXE) $(OD)*.o $(ODT)*.o


