CC = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

Life: main.o helpers.o life.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm Life