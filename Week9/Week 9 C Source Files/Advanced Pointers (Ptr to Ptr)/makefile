all: processPointer.exe

processPointer.exe: main.o no_update_ptr.o somefunc.o update_ptr.o
	gcc -o processPointer.exe main.o no_update_ptr.o somefunc.o update_ptr.o

main.o: main.c myFunctions.h
	gcc -c main.c

no_update_ptr.o: no_update_ptr.c
	gcc -c no_update_ptr.c

somefunc.o: somefunc.c
	gcc -c somefunc.c

update_ptr.o: update_ptr.c
	gcc -c update_ptr.c

clean:
	rm -rf *.o processPointer.exe