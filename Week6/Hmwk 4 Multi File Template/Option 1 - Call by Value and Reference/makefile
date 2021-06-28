all: processEmp.exe

processEmp.exe: main.o getHours.o printEmp.o
	gcc -o processEmp.exe main.o getHours.o printEmp.o

main.o: main.c
	gcc -c main.c

getHours.o: getHours.c
	gcc -c getHours.c

printEmp.o: printEmp.c
	gcc -c printEmp.c

clean:
	rm -rf *o processEmp.exe