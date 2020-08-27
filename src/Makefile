CC = gcc
CFLAGS = -c -g -Wall -std=c99 -I $(INC)
OBJ = linked_list.o hashtable.o main.o
INC = ../include

.c.o:
	$(CC) $(CFLAGS) $<

adt_lib: $(OBJ)
	$(CC) $^ -o $@

linked_list.o: $(INC)/linked_list.h
hashtable.o: $(INC)/hashtable.h
main.o: $(INC)/hashtable.h $(INC)/linked_list.h

clean:
	rm -f *.o
