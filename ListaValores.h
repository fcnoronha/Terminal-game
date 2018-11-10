# ifndef _ListaValores_h // Avoiding conflicts errors
# define _ListaValores_h 

#include "Estruturas.h"

Lista * criaL();

void destroiL(Lista *l);

Elemento * insereL(Lista *l, Elemento *val);

Elemento * buscaL(Lista *l, char *n);

Elemento * retiraL(Lista *l, Elemento *val);

int insereElol(Lista *l, EloL *val);

EloL *buscaElol(Lista *l, char *tag);

int retiraElol(Lista *l, char *tag);

# endif