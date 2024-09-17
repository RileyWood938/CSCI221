CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

all: array_initializer hello_world.o
	$(CC) $(CFLAGS) -o hello_world hello_world.o array_initializer.o

hello_world.o: hello_world.h hello_world.c
	$(CC) $(CFLAGS) -c hello_world.c

array_initializer : array_initializer.h array_initializer.c 
	$(CC) $(CFLAGS) -c array_initializer.c

clean:
	rm array_initializer.o array_initializer