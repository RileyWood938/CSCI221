CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g

all: floats_testing

floats_testing: floats.o
	$(CC) $(CFLAGS) -o floats_testing floats_testing.c floats.o

floats.o: floats.c floats.h
	$(CC) $(CFLAGS) -c floats.c

clean:
	rm *.o floats_testing