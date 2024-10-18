CC = gcc
CFLAGS = -Wall -Wextra -pedantic 

make_all: tiny_float_testing

tiny_float.o: tiny_float.c tiny_float.h
	$(CC) $(CFLAGS) -c tiny_float.c

tiny_float_testing: tiny_float.o tiny_float_testing.c
	$(CC) $(CFLAGS) -o tiny_float_testing tiny_float_testing.c tiny_float.o

clean:
	rm *.o tiny_float_testing