all: processPines.exe

processPines.exe: main.o printPines.o
	gcc -o processPines.exe main.o printPines.o

main.o: main.c
	gcc -c main.c

printPines.o: printPines.c
	gcc -c printPines.c

clean:
	rm -rf *.o processPines.exe