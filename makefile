CXXFLAGS=-g -std=c++1y -Wall -pthread -c 
CC=g++
SRC=./Sources
INC=./Headers
TESTS=./Tests
OBJ=./Output/Objects

all: build

rebuild: clean build

build: Output FileManager.o ThreadPool.o AllTasks.o testMain.o
	$(CC) $(OBJ)/* -o ./Output/exec.exe 
Output:
	mkdir -p ./Output/Objects

FileManager.o:
	$(CC) $(CXXFLAGS) $(SRC)/FileManager.cpp -o $(OBJ)/FileManager.o

testMain.o:
	$(CC) $(CXXFLAGS) $(TESTS)/tests_MainApp.cpp -o $(OBJ)/testMain.o

AllTasks.o:
	$(CC) $(CXXFLAGS) $(SRC)/AllTasks.cpp -o $(OBJ)/AllTasks.o

ThreadPool.o:
	$(CC) $(CXXFLAGS) $(SRC)/ThreadPool.cpp -o $(OBJ)/ThreadPool.o

clean:
	rm -p *.o
	rm -r ./Output