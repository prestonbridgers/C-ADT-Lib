CC = gcc
CFLAGS = -c -g -Wall -std=c99 -I $(INC)
OBJ = linked_list.o hashtable.o stack.o main.o
INC = ../include

.c.o:
	$(CC) $(CFLAGS) $<

adt_lib: $(OBJ)
	$(CC) $^ -o $@

linked_list.o: $(INC)/linked_list.h
hashtable.o: $(INC)/hashtable.h
stack.o: $(INC)/stack.h $(INC)/linked_list.h
main.o: $(INC)/hashtable.h $(INC)/linked_list.h $(INC)/stack.h

clean:
	rm -f *.o
