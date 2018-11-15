# ifndef _hashTable_h // Avoiding conflicts errors
# define _hashTable_h 

#include "Estruturas.h"

/*
 Return hash value of a given string.
*/
int hashFun(char*, int);

/*
 Creates hashTable, allocating necessary memory and 
 defining relationships.
*/
TabSim *criaS(int);

/*
 Erase hashTable, freeing all used memory.
*/
void destroiS(TabSim*);

/*
 Insert value on the hashTable, return 1 if insertion was sucessfull
 and 0 otherwise.
*/
int insereS(TabSim*, char*, Elemento*);

/* 
 Search element in the hash table, returning it if found
 and returning NULL otherwise.
*/
Elemento *buscaS(TabSim*, char*);

/*
 Erases element of the hash table, returning 1 if sucess and 0
 otherwise.
*/
int retiraS(TabSim*, char*);

# endif