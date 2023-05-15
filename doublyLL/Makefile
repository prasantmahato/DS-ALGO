# HEADERS = main.h headers.h

default: main

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o
	gcc main.o -o main

main.asm: main.asm
	gcc main.o -S main.asm
run: 
	gcc -c main.c -o main.o -O0 -Wall
	gcc main.o -o main
	./main

clean:
	-rm -f main.o
	-rm -f main
