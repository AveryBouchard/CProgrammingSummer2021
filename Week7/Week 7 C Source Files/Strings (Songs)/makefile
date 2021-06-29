all: processSong.exe

processSong.exe: main.o printLyrics.o
	gcc -o processSong.exe main.o printLyrics.o

main.o: main.c songs.h
	gcc -c main.c

printLyrics.o: printLyrics.c songs.h
	gcc -c printLyrics.c

clean:
	rm -rf *.o processSong.exe