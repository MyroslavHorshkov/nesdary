CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99
SRC = src/calcilitir.c

all: main tests

main: main_code/calculator.c $(SRC)
	$(CC) $(CFLAGS) main_code/calculator.c $(SRC) -o main_code/calculator

tests: tests/tests.c $(SRC)
	$(CC) $(CFLAGS) tests/tests.c $(SRC) -o tests/tests

clean_tests:
	cmd /C del /Q tests\\tests.exe

clean_main:
	cmd /C del /Q main_code\\calculator.exe