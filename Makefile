CC = gcc
CFLAGS = -I.

main: main.o
	$(CC) -o main main.o -lpthread

st: singlethreaded.o
	$(CC) -o st singlethreaded.o -lpthread

clean:
	rm main st *.o
