CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic -g

all: numbers_testing

numbers_testing: numbers.o numbers_test.c
	$(CC) $(CFLAGS) -o numbers_testing numbers_test.c numbers.o

numbers.o: numbers.c numbers.h
	$(CC) $(CFLAGS) -c numbers.c

clean:
	rm *.o *_testing