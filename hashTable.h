# ifndef _hashTable_h // Avoiding conflicts errors
# define _hashTable_h 

#include "Estruturas.h"

TabSim *criaS(int);

void destroiS(TabSim*);

int insereS(TabSim*, char*, Elemento*);

Elemento *buscaS(TabSim*, char*);

int retiraS(TabSim*, char*);

# endif