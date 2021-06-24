all: testRunTime.exe

testRunTime.exe: main.o printit.o
	gcc -o testRunTime.exe main.o printit.o

main.o: main.c
	gcc -c main.c

printit.o: printit.c
	gcc -c printit.c

clean:
	rm -rf *.o testRunTime.exe