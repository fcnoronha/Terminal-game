# Listing projects files. ONLY UPDATE HERE while changing stuff.
OBJECTS = hashTable.o ListaValores.o 
HEADERS = hashTable.h Estruturas.h ListaValores.h game.h
EXES = testador3000 game

# Setting default compiler and flags
CC = gcc
CFLAGS = -Wall 	

# Compile file to test and verify the code.
testador: $(OBJECTS) testador3000.o
	$(CC) $(CFLAGS) $(OBJECTS) testador3000.o -o testador3000 

# Compile the game itself.
game: $(OBJECTS) game.o
	$(CC) $(CFLAGS) $(OBJECTS) game.o -o game 

# Compiles all objects files on demand.
%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

# Phony clean target. Run after pushing to github.
clean:
	@rm -f all $(OBJECTS) $(EXES) testador3000.o game.o

# Use like this on terminal: make testador or make clean