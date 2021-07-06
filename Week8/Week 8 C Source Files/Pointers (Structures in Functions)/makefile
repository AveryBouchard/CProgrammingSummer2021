all: processEmployee.exe

processEmployee.exe: main.o updateEmp.o printEmp.o
	gcc -o processEmployee.exe main.o updateEmp.o printEmp.o

main.o: main.c employees.h
	gcc -c main.c

updateEmp.o: updateEmp.c employees.h
	gcc -c updateEmp.c

printEmp.o: printEmp.c employees.h
	gcc -c printEmp.c

clean:
	rm -rf *.o processEmployee.exe