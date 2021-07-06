all: processEmployee.exe

processEmployee.exe: main.o getHours.o printData.o
	gcc -o processEmployee.exe main.o getHours.o printData.o

main.o: main.c
	gcc -c main.c employees.h

getHours.o: getHours.c
	gcc -c getHours.c employees.h

printData.o: printData.c
	gcc -c printData.c employees.h

clean:
	rm -rf *.o processEmployee.exe