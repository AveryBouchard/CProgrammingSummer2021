all: processDate.exe

processDate.exe: main.o
	gcc -o processDate.exe main.o

main.o: main.c date_time.h
	gcc -c main.c

clean:
	rm -rf *.o processDate.exe