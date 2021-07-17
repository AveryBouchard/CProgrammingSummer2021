all: processList.exe

processList.exe: main.o print_list.o findEntry.o
	gcc -o processList.exe main.o print_list.o findEntry.o

main.o: main.c employees.h
	gcc -c main.c

print_list.o: print_list.c employees.h
	gcc -c print_list.c

findEntry.o: findEntry.c employees.h
	gcc -c findEntry.c

clean:
	rm -rf *.o processList.exe