# -*- makefile -*-

CC = g++
CFLAGS = -o

all: main

main: main.o quaternion.o
	$(CC) main.o quaternion.o -o main
	
main.o: main.cpp quaternion.h
	$(CC) -c main.cpp

quaternion.o: quaternion.cpp quaternion.h
	$(CC) -c quaternion.cpp

	
clean:
	rm -f *.o main quaternion