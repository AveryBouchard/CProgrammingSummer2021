all: testPointer.exe

testPointer.exe: main.o pointerTest.o
	gcc -o testPointer.exe main.o pointerTest.o

main.o: main.c
	gcc -c main.c

pointerTest.o: pointerTest.c
	gcc -c pointerTest.c

clean:
	rm -rf *.o testPointer.exe