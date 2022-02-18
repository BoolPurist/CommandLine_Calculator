CC=g++

INC=inc
CCF=-Wall -I$(INC)
OBJ=obj/
SRC=src/
BIN=bin/

OBJS=$(OBJ)main.o $(OBJ)process.o $(OBJ)math_utility.o

ARGS=25 45 78

.PHONY: all

$(BIN)main.out: $(OBJS)
	$(CC) $(CCF) $^ -o $@

$(OBJ)main.o: $(SRC)main.cpp $(INC)/process.hpp $(INC)/math_utility.hpp
	$(CC) $(CCF) -c $< -o $@

$(OBJ)process.o: $(SRC)process.cpp $(INC)/process.hpp
	$(CC) $(CCF) -c $< -o $@

$(OBJ)math_utility.o: $(SRC)math_utility.cpp $(INC)/math_utility.hpp
	$(CC) $(CCF) -c $< -o $@

run:
	$(BIN)main.out $(ARGS)