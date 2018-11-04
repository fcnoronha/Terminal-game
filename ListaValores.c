#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

//#define NULL ((void*)0)

Lista *criaL()
{
	Lista *l = NULL; /* ponteiro pra lista */
	l = malloc(sizeof(Lista));
	if (l == NULL) return NULL; /* checando alocacao */
	l->tamanho=0;
	l->Lista = NULL; // O FELIPE E MUITO FODA, NAMORAL
					 // AINDA POR CIMA, E GATO DEMAISSSS

	return l;
}

void destroiL(Lista *l)
{

	EloL *atual, *aux;

	atual = l->Lista; /* atual recebe primeiro elemento */

	while(atual->prox!= NULL){ /* percorre a lista ate o final */

		aux = atual->prox;

		free(atual->valor);
		free(atual);

		atual = aux;
	}

	free(l->Lista);
	free(l);
}


Elemento * insereL(Lista *l, Elemento *val){
	/* cria EloL */
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
