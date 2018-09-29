#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

Lista criaL()
{
	Lista *l = NULL; /* ponteiro pra lista */
	l = malloc(sizeof(Lista));
	l->tamanho=0;

	return *l;
}

void destroiL(Lista *l)
{
	
	EloL *atual, *aux;

	atual = l->Lista;

	while(atual->prox!= NULL)
	{
		aux = atual->prox;

		free(atual->valor);
		free(atual->prox);

		atual=aux;

	}

	free(l->Lista);
	free(l);
}


Elemento * insereL(Lista *l, Elemento *val)
{

	/* cria EloL */
	EloL *aux = malloc(sizeof(EloL));
	EloL *atual = l->Lista;
	aux->valor = val;
	aux->prox = NULL;

	if (buscaL(l, val) != NULL) return NULL; 

	while ( atual != NULL && atual->prox != NULL) 
	{
		atual = atual->prox;
	}

	l->tamanho++;
	atual->prox = aux;
	return aux->valor;

}

Elemento *buscaL(Lista *l, Elemento *val)
{
	EloL *atual = l->Lista;
	while(atual->prox != NULL)
	{
		if (atual->valor == val)
			return atual->valor;
		atual = atual->prox;
	}

	if (atual->valor == val)
			return atual->valor;
	return NULL;
}

Elemento *retiraL(Lista *l, Elemento *val)
{
	EloL *atual;
	EloL *anterior = l->Lista;
	Elemento *valor = buscaL(l, val);

	if(!atual) return NULL;

	while(anterior->prox != atual)
		anterior=anterior->prox;

	anterior->prox=atual->prox;

	return (atual->valor);

}