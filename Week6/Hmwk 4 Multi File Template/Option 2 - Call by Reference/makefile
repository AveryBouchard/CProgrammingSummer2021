all: processEmp.exe

processEmp.exe: main.o getHours.o
	gcc -o processEmp.exe main.o getHours.o

main.o: main.c
	gcc -c main.c

getHours.o: getHours.c
	gcc -c getHours.c

clean:
	rm -rf *o processEmp.exe