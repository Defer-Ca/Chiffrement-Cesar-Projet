all : cesar main

main: Cesar.o
	gcc Cesar.o main.c -o main

cesar: Cesar.h 
	gcc -c Cesar.c 

clean : Cesar.h
	rm main Cesar.o