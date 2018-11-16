# Listing projects files. ONLY UPDATE HERE while changing stuff.
OBJECTS = hashTable.o ListaValores.o game.o acoes.o 
HEADERS = hashTable.h Estruturas.h ListaValores.h game.h acoes.h
EXES = testador game

# Setting default compiler and flags
CC = gcc
CFLAGS = -Wall 	

# Compile file to test and verify the code.
testador: testador3000.o ListaValores.o hashTable.o
	$(CC) $(CFLAGS) testador3000.o ListaValores.o hashTable.o -o testador 

# Compile the game itself.
game: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o game 

# Compiles all objects files on demand.
%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

# Phony clean target. Run after pushing to github.
clean:
	@rm -f all $(OBJECTS) $(EXES) testador3000.o

# Use like this on terminal: make testador or make clean