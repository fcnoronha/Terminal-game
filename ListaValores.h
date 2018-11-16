# ifndef _ListaValores_h // Avoiding conflict errors
# define _ListaValores_h 

#include "Estruturas.h"

/*
 Create-allocate memory for the list, returning it.
*/
Lista * criaL();

/*
 Free all the memory used in the list.
*/
void destroiL(Lista *l);

/*
 Insert element in the list, returning the inserted value.
*/
Elemento * insereL(Lista *l, Elemento *val);

/*
 Search an Element in the list, returning it if found, and NULL otherwise.
*/
Elemento * buscaL(Lista *l, char *n);

/*
 Remove element from the list.
*/
Elemento * retiraL(Lista *l, Elemento *val);

/*
 Insert Element in the list, returning 1 if it was sucessfull and
 0 otherwise.
*/
int insereElol(Lista *l, EloL *val);

/*
 Find and return Elol associated with the given tag. Return NULL
 if couldn't find.
*/
EloL *buscaElol(Lista *l, char *tag);

/*
 Find and return Elol associated with the given element. Return NULL
 if couldn't find.
*/
EloL *buscaEle(Lista *l, Elemento *s);

/*
 Given a tag, removes its EloL from the list, returning 1 if it was 
 sucessfull and 0 otherwise.
*/
int retiraElol(Lista *l, char *tag);


# endif
