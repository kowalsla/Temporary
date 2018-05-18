CXXFLAGS=-g -std=c++11 -Wall -pedantic -c
CC=g++
SRC=./Sources
INC=./Headers
TESTS=./Tests

all: build

rebuild: clean build

build: TaskManager.o FileManager.o MainApp.o AllTasks.o
	mkdir -p Output
	$(CC) TaskManager.o FileManager.o tests_MainApp.o AllTasks.o -o ./Output/exec.exe 

TaskManager.o: 
	$(CC) $(CXXFLAGS) $(SRC)/TaskManager.cpp

FileManager.o:
	$(CC) $(CXXFLAGS) $(SRC)/FileManager.cpp

MainApp.o:
	$(CC) $(CXXFLAGS) $(TESTS)/tests_MainApp.cpp

AllTasks.o:
	$(CC) $(CXXFLAGS) $(SRC)/AllTasks.cpp

clean:
	rm *.o
	rm -r ./Output