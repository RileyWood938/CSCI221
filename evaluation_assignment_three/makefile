CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic -g -o0

all: exponentials.o
	$(CC) $(CFLAGS) -o test_exponentials exponential_testing.c exponentials.o

%.o : %.h %.C
	$(CC) $(CFLAGS) $@ $^

clean: 
	rm *.o test_exponentials