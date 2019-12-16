main:	main.o	Assembler.o
	gcc main.o Assembler.o -o main

main.o: main.c
	gcc -c main.c

Assembler.o:	Assembler.c		Assembler.h
	gcc -c Assembler.c

clean:
	rm *.o