CC = gcc
CFLAGS = -o

test_calc: calculations.c calculations.h
	$(CC) $(CFLAGS) test_calc.o test_calc.c

calculations.c: calculations.h
clean:
	/bin/rm test_calc calculations.o
