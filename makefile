CXXFLAGS=-g -std=c++11
__CXXFLAGS=-g -std=c++11 -Wall -pedantic
CC=g++
SRC=./Sources
all: build

build: MainApp

MainApp:
	$(CC) $(CXXFLAGS) ./Tests/tests_MainApp.cpp $(SRC)/FileManager.cpp $(SRC)/TaskManager.cpp $(SRC)/MainApp.cpp -o exec