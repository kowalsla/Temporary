CXXFLAGS=-g -std=c++1y -Wall -pthread -c 
CC=g++
SRC=./Sources
INC=./Headers
TESTS=./Tests
OBJ=./Output/Objects

all: build

rebuild: clean build


build: Output FileManager.o AllTasks.o testMain.o ThreadManager.o
	$(CC) $(OBJ)/* -o ./exec.exe 
Output:
	mkdir -p ./Output/Objects

FileManager.o:
	$(CC) $(CXXFLAGS) $(SRC)/FileManager.cpp -o $(OBJ)/FileManager.o

testMain.o:
	$(CC) $(CXXFLAGS) $(TESTS)/tests_MainApp.cpp -o $(OBJ)/testMain.o

AllTasks.o:
	$(CC) $(CXXFLAGS) $(SRC)/AllTasks.cpp -o $(OBJ)/AllTasks.o

ThreadManager.o:
	$(CC) $(CXXFLAGS) $(SRC)/ThreadManager.cpp -o $(OBJ)/ThreadManager.o

clean:
	rm -p *.o
	rm -r ./Output