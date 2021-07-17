all: processPointer.exe

processPointer.exe: main.o sum.o
	gcc -o processPointer.exe main.o sum.o

main.o: main.c
	gcc -c main.c

sum.o: sum.c
	gcc -c sum.c

clean:
	rm -rf *.o processPointer.exe