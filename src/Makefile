prog: stack.o rules.o main.o
	gcc -o $@ stack.o rules.o main.o

stack.o: stack.c
	gcc -o $@ -c stack.c -Wall

rules.o: rules.c stack.h
	gcc -o $@ -c rules.c -Wall

main.o: main.c stack.h rules.h
	gcc -o $@ -c main.c -Wall