#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ListaValores.h"

Lista *criaL()
{
	// Create-allocate memory for the list
	Lista *l = malloc(sizeof(Lista));
	if (l == NULL) return NULL; // If allocation went well
	l->tamanho = 0;
	l->Lista = NULL; // O FELIPE E MUITO FODA, NAMORAL
					 // AINDA POR CIMA, E GATO DEMAISSSS

	return l;
}

void destroiL(Lista *l)
{
	// Free all the memory used in the list
	EloL *atual, *aux;
	atual = l->Lista; 

	while(atual->prox!= NULL){ // Goes until the end of the list

		aux = atual->prox; // Keeping track of the list
		free(atual->valor);
		free(atual);
		atual = aux;
	}

	free(l->Lista);
	free(l);
}

Elemento *insereL(Lista *l, Elemento *val){
	// Insert eleent in the list
	EloL *aux = malloc(sizeof(EloL));
	EloL *atual = l->Lista;

	if (atual == NULL){
		aux->valor = val;
		aux->prox = NULL;
		l->tamanho++;
		l->Lista = aux;
		return val;
	}

	aux->valor = val;
	aux->prox = NULL;

	//if (buscaL(l, val->desc) != NULL) return val; /* se o elemento ja estiver na lista ele mesmo eh retornado */

	while ( atual != NULL && atual->prox != NULL){ /* percorre a lista ate o final */
		atual = atual->prox;
	}
	l->tamanho++; /* atualiza tamanho da lista */
	atual->prox = aux; /* insere novo elo */
	return aux->valor;
}

int insereElol(Lista *l, EloL *val){
	// Insert whole Elol in the list, if everything goes ok, return 1 and 0 otherwise
	EloL *atual = l->Lista;

	if (atual == NULL){
		l->tamanho++;
		l->Lista = val;
		return 1;
	}

	while (atual != NULL && atual->prox != NULL) // Going thru the list until the end
		atual = atual->prox;
	
	l->tamanho++; // Updating size
	atual->prox = val; // adding to the end of the list

	if (atual->prox == val)
		return 1;

	return 0;
}

Elemento *buscaL(Lista *l, char *n)
{
	EloL *atual = l->Lista;
	while(atual != NULL) /* percorre a lista ate o final */
	{
		if (strcmp(atual->valor->desc, n) == 0) /* compara elemento com n */
		{
			return atual->valor;
		}
		atual = atual->prox;
	}
	/*if (strcmp(atual->valor->desc, n) == 0) // checa se nao estava no ultimo 
	{
		return atual->valor;
	}
	*/

	return NULL;
}

EloL *buscaElol(Lista *l, char *tag)
{
	// Finds and return pointer to a elo of the list
	EloL *atual = l->Lista;

	while(atual != NULL){
		if (strcmp(atual->info, tag) == 0)		
			return atual;
		
		atual = atual->prox;
	}

	return NULL; // If don't find
}


Elemento *retiraL(Lista *l, Elemento *val)
{
	EloL *atual = l->Lista;
	EloL *anterior;
	Elemento *valor = buscaL(l, val->desc); /* busca o elemento na linha */

	if (atual == NULL || valor == NULL) return NULL; /* se elemento nao estiver na lista, retorna NULL */

	if (atual->valor == val){
		l->Lista = atual->prox;
		return val;
	}

	anterior = atual;
	atual = atual->prox;

	while(atual->valor != val) /* encontra elo anterior ao do elemento */
	{
		anterior = anterior->prox;
		atual = atual->prox;
	}

	anterior->prox = atual->prox; /* atualiza os elos */

	return val;
}

int retiraElol(Lista *l, char *tag)
{
	// Given a tag, removes its elo from the list
	EloL *atual = l->Lista;
	EloL *anterior;

	if (atual == NULL) return 0; // There is nothing on the list

	if (strcmp(atual->info, tag) == 0){
		l->Lista = atual->prox;
		// Doens't free because this elo may go to another list
		return 1;
	}

	anterior = atual;
	atual = atual->prox;

	while(atual != NULL && strcmp(atual->info, tag) == 0)
	{
		anterior = anterior->prox;
		atual = atual->prox;
	}

	anterior->prox = atual->prox; // Update elos

	return 1;
}
