CC=gcc
OBJECTS=$(SOURSES:.c=.o)
CFLAGS=-Wall -Wextra -Werror
TARGET=../build/Quest_1
TARGET_LIST=../build/Quest_2
TARGET_STACK=../build/Quest_3

all: clean list_test stack_test

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

listTESTS.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -DTESTS

listSTACK.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -DSTACK

list_test.o: list_test.c list.h
	$(CC) $(CFLAGS) -c list_test.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c 

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) -c stack_test.c 

list_test: listTESTS.o list_test.o
	$(CC) list.o list_test.o -o $(TARGET_LIST)

stack_test: listSTACK.o stack.o stack_test.o
	$(CC) list.o stack.o stack_test.o -o $(TARGET_STACK)

clean:
	rm -rf *.o ../build/*