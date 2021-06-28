all: processEmp.exe

processEmp.exe: main.o getHours.o calcOvertimeHours.o calcGrossPay.o printTableHeader.o printEmployeeTable.o printTotalsAndAverages.o
	gcc -o processEmp.exe main.o getHours.o calcOvertimeHours.o calcGrossPay.o printTableHeader.o printEmployeeTable.o printTotalsAndAverages.o

main.o: main.c
	gcc -c main.c

getHours.o: getHours.c
	gcc -c getHours.c

calcOvertimeHours.o: calcOvertimeHours.c
	gcc -c calcOvertimeHours.c

calcGrossPay.o: calcGrossPay.c
	gcc -c calcGrossPay.c

printTableHeader.o: printTableHeader.c
	gcc -c printTableHeader.c

printEmployeeTable.o: printEmployeeTable.c
	gcc -c printEmployeeTable.c

printTotalsAndAverages.o: printTotalsAndAverages.c
	gcc -c printTotalsAndAverages.c

clean:
	rm -rf *o processEmp.exe