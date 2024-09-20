CC = gcc 
CFLAGS = -Wall -Werror -Wextra -pedantic

test_all: fibonacci.o find_divisor.o moving.o powers.o
	$(CC) $(CFLAGS) -o test_all test_all.c fibonacci.o find_divisor.o moving.o powers.o

%.o : %.c %.h
	$(CC) $(CFLAGS) -c $<

%_test: %.o %_testing.o
	$(CC) -o $@ $^

clean: 
	rm *.o test_all *_test