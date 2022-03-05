CC=g++

INC=inc
CCF=-Wall -I$(INC)
OBJ=obj/
SRC=src/
BIN=bin/
EX=$(BIN)main.out
NAME:=command_line_caculator.bin

MAIN:=$(OBJ)main.o
PROC:=$(OBJ)process.o
MATH:=$(OBJ)math_utility.o
HELP:=$(OBJ)help.o
OBJS=$(MAIN) $(PROC) $(MATH) $(HELP)

ARGS=min 1 3 3 6 7 8 9
ARGS2=  median 4.78 2.5 5.45
ARGSN:=
ARGH:=-h
ARG1M:=median a

.PHONY: build

build: $(EX)

$(EX): $(OBJS)
	$(CC) $(CCF) $^ -o $@

$(MAIN): $(SRC)main.cpp $(INC)/process.hpp $(INC)/math_utility.hpp
	$(CC) $(CCF) -c $< -o $@

$(PROC): $(SRC)process.cpp $(INC)/process.hpp
	$(CC) $(CCF) -c $< -o $@

$(MATH): $(SRC)math_utility.cpp $(INC)/math_utility.hpp
	$(CC) $(CCF) -c $< -o $@

$(HELP): $(SRC)help.cpp $(INC)/help.hpp
	$(CC) $(CCF) -c $< -o $@

run:
	$(EX) $(ARG1M)

deploy: build serve

clear:
	rm $(EX) $(OBJS)

serve:
	cp $(EX) $(NAME)