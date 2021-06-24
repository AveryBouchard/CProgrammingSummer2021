all: processDay.exe

processDay.exe: main.o nextDay.o
	gcc -o processDay.exe main.o nextDay.o

main.o: main.c employees.h
	gcc -c main.c

nextDay.o: nextDay.c employees.h
	gcc -c nextDay.c

clean:
	rm -rf *.o processDay.exe