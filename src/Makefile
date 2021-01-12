CC = gcc
CFLAGS = -c -g -Wall -std=c99 -I $(INC)
OBJ = linked_list.o hashtable.o stack.o queue.o bst.o
INC = ../include
	
.c.o:
	$(CC) $(CFLAGS) $<

adt_lib: $(OBJ) main.o
	$(CC) $^ -o $@

lib: adt_lib
	ar rcs lib_adt.a $(OBJ)

bst.o: $(INC)/bst.h
linked_list.o: $(INC)/linked_list.h
hashtable.o: $(INC)/hashtable.h
stack.o: $(INC)/stack.h $(INC)/linked_list.h
queue.o: $(INC)/queue.h
main.o: $(INC)/hashtable.h $(INC)/linked_list.h $(INC)/stack.h $(INC)/queue.h $(INC)/bst.h

clean:
	rm -f *.o
	rm lib_adt.a
