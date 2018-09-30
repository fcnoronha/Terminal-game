#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

Lista *criaL()
{
	Lista *l = NULL; /* ponteiro pra lista */
	l = malloc(sizeof(Lista));
	if (l == NULL) return NULL; /* checando alocacao */
	l->tamanho=0;

	return l;
}

void destroiL(Lista *l)
{
	
	EloL *atual, *aux;

	atual = l->Lista; /* atual recebe primeiro elemento */

	while(atual->prox!= NULL) /* percorre a lista ate o final */
	{
		aux = atual->prox;

		free(atual->valor);
		free(atual);

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

	if (buscaL(l, val) != NULL) return val; /* se o elemento ja estiver na lista ele mesmo eh retornado */

	while ( atual != NULL && atual->prox != NULL)  /* percorre a lista ate o final */
	{
		atual = atual->prox;
	}

	l->tamanho++; /* atualiza tamanho da lista */
	atual->prox = aux; /* insere novo elo */
	return aux->valor;

}

Elemento *buscaL(Lista *l, char *n)
{
	EloL *atual = l->Lista;
	while(atual->prox != NULL)
	{
		if (!strcmp(atual->valor->desc, n))
			return atual->valor;
		atual = atual->prox;
	}

	if (!strcmp(atual->valor->desc, n))
			return atual->valor;
	return NULL;
}

Elemento *retiraL(Lista *l, Elemento *val)
{
	EloL *atual;
	EloL *anterior = l->Lista;
	Elemento *valor = buscaL(l, val);

	atual=anterior->prox;

	if(valor == NULL) return NULL;

	while(anterior->valor != val)
		anterior=anterior->prox;
		atual=atual->prox;

	anterior->prox=atual->prox;

	return (atual->valor);

}