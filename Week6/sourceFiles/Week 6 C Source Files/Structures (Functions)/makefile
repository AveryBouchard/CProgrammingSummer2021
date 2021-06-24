all: testDay.exe

testDay.exe: main.o printNextDay.o
	gcc -o testDay.exe main.o printNextDay.o

main.o: main.c employees.h
	gcc -c main.c

printNextDay.o: printNextDay.c employees.h
	gcc -c printNextDay.c

clean:
	rm -rf *.o testDay.exe