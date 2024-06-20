# KEMI OMONIYI PSET 3 10/20/2023 
CC = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

# TO STUDENT: You may add to this file, but there must remain a target named
#   "HookBook" that generates an executable named the same.

HookBook: hookbookb.o pirate.o pirate_list.o skills_list.o libhookbook.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o Hookbook