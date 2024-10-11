CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g

all: binary_tree_testing arrays_testing

arrays_testing: arrays_test.o binary_tree.o arrays.o
	$(CC) $(CFLAGS) -o arrays_testing arrays_test.o arrays.o binary_tree.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

%_testing: %_test.o %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o *_testing