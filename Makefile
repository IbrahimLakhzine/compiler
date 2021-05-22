compilation : main.o lexicalHeader.o synthaxicHeader.o
	gcc -o compilation main.o lexicalHeader.o synthaxicHeader.o  


main.o : main.c
	gcc -o main.o -c main.c

lexicalHeader.o : lexicalHeader.c
	gcc -o lexicalHeader.o -c lexicalHeader.c


synthaxicHeader.o : synthaxicHeader.c
	gcc -o synthaxicHeader.o -c synthaxicHeader.c		  