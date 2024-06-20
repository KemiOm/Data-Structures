CC = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

HookBook: hookbook.o pirate.o pirate_list.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o Hookbook