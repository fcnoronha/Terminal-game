#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

Lista criaL(int tam)
{
	Lista *l = NULL; /* ponteiro pra tabela */
	l = malloc(sizeof(Lista));
	l->tamanho=tam;
	l->Lista=malloc(tam * sizeof(Elol*));

	return l;
}

void destroiL(Lista l)
{
	free(l);
	l = NULL;
}


Elemento * insereL(Lista l, Elemento *val);
{

	/* cria EloL */
	EloL *aux = malloc(sizeof(EloL));
	aux->valor = val;
	aux->prox = NULL;

}

Elemento *buscaL(Lista l, char *n)

Elemento *retiraL(Lista l, Elemento *val)