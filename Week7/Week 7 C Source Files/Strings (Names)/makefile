all: processEmp.exe

processEmp.exe: main.o printNames.o
	gcc -o processEmp.exe main.o printNames.o

main.o: main.c employees.h
	gcc -c main.c

printNames.o: printNames.c employees.h
	gcc -c printNames.c

clean:
	rm -rf *.o processEmp.exe