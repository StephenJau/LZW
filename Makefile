output: lzw.o
	gcc lzw.o -o output

lzw.o: lzw.c
	gcc -c -Wall lzw.c

clean:
	rm *.o