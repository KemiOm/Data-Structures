CC = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

Blotto: blotto.o gmap.o string_key.o entry.o gmap.h entry.h string_key.h
	$(CC) $(CFLAGS) -o $@ $^

GmapUnit: gmap.o gmap_test_functions.o string_key.o entry.o gmap_unit.o gmap.h gmap_test_functions.h entry.h string_key.h
	$(CC) $(CFLAGS) -o $@ $^



clean: 
	rm -f *.o Blotto GmapUnit