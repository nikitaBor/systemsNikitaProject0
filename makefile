all: A.o tunez.o tunezLIB.o
	gcc A.o tunez.o tunezLIB.o -o test_tunez

A.o: A.c tunez.h tunezLIB.h
	gcc -c A.c
tunez.o: tunez.c tunez.h
	gcc -c tunez.c
tunezLIB.o: tunezLIB.c tunezLIB.h tunez.h
	gcc -c tunezLIB.c
run: all
	./test_tunez
clean:
	rm *.o
