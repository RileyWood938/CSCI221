CC = gcc
CFLAGS = -Wall  -Wextra -pedantic -g

all: linked_list_testing

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

%_testing: %_testing.o %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o *_testing