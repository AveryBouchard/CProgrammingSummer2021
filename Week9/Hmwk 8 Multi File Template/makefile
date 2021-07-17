all: processEmp.exe

processEmp.exe: main.o print_list.o employees.h
        gcc -o processEmp.exe main.o print_list.o

main.o: main.c
        gcc -c main.c

print_list.o: print_list.c
        gcc -c print_list.c

clean:
        rm -rf *o processEmp.exe