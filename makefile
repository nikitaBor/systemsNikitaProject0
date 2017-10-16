all: main.o tunez.o
	gcc main.o tunez.o -o test_tunez

main.o: main.c tunez.h
	gcc -c main.c
tunez.o: tunez.c tunez.h
	gcc -c tunez.c
run: all
	./test_tunez
clean:
	rm *.o
