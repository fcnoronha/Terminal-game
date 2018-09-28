#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

Lista criaL(int tam)
{
	Lista *l = NULL; /* ponteiro pra lista */
	l = malloc(sizeof(Lista));
	l->tamanho=malloc(sizeof(int));
	l->tamanho=tam;
	l->Lista=malloc(tam * sizeof(Elol*));

	return l;
}

void destroiL(Lista l)
{
	
	EloL atual;

	atual->prox = l->Lista

	while(atual->prox!= NULL)
	{
		free(atual->valor);
		free(atual->prox);

		atual = atual->prox;
	}

	free(l->tam);
	free(l->Lista);
	free(l);
}


Elemento * insereL(Lista l, Elemento *val);
{

	/* cria EloL */
	EloL *aux = malloc(sizeof(EloL));
	EloL atual = l;
	aux->valor = val;
	aux->prox = NULL;

	while ( atual != NULL && atual->prox != NULL) 
	{
		atual = atual->prox;
	}

	l->tam++;
	atual->prox = aux;
	return aux;

}

Elemento *buscaL(Lista l, Elemento *val)
{
	EloL atual = l->Lista;
	while(atual != NULL)
	{
		if (atual->val == n)
			return atual;
	}
	return 0;
}

Elemento *retiraL(Lista l, Elemento *val)
{
	EloL atual = buscaL(l, val);
	EloL anterior = l->Lista;

	while(anterior->prox != atual)
		anterior=anterior->prox;

	anterior->prox=atual->prox;

	free(atual->valor);
	free(atual->prox);
	free(atual);

}