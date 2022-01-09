CC = gcc -g

all: stos.o funkcja.o main2.o
	$(CC) stos.o funkcja.o main2.o -o rpn

stos.o: stos.c naglowek.h
	$(CC) stos.c -c -o stos.o

funkcja.o: funkcja.c naglowek.h
	$(CC) funkcja.c -c -o funkcja.o

main2.o: main2.c naglowek.h
	$(CC) main2.c -c -o main2.o

clean:
	rm -f *.o rpn