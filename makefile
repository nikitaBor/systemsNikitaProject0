all: main.o tunez.o
	gcc main.o tunez.o -o test_tunez

A.o: A.c tunez.h
	gcc -c A.c
tunez.o: tunez.c tunez.h
	gcc -c tunez.c
run: all
	./test_tunez
clean:
	rm *.o
