all: processPres.exe

processPres.exe: main.o
	gcc -o processPres.exe main.o

main.o: main.c presidents.h
	gcc -c main.c

clean:
	rm -rf *.o processPres.exe