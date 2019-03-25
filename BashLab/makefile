CC=gcc
CFLAGS=-I.
DEPS=./functions/cd.h ./functions/clear.h ./functions/parser.h ./functions/pwd.h ./functions/time.h
OBJ=./functions/cd.o ./functions/clear.o ./functions/parser.o ./functions/pwd.o ./functions/time.o shell.o

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

# Makefile prompt
shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make clean
	clear
		
clean:
	rm -f cli $(OBJ) *~
	rm -f $(OBJ) *.o
