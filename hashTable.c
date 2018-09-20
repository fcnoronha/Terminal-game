#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"hashTable.h" // Usando meu cabeçalho


int hashFun(char *n, int tam){
	// Retorna a chave, valor hash, da string dada.
	int chave, lst, i;
	while (n[i] != '\0'){
		chave += n[i]; // Soma todos valores ASCII
		lst = n[i];
	}
	chave /= lst; // Divide pelo valor ASCII do ultimo caractere
	chave %= tam; // Modulo tamanho da tabela
	return chave;
}

TabSim *criaS(int tam){
	TabSim *t;
	t = malloc(sizeof(TabSim));

	t->tamanho = tam;
	t->Tabela = calloc((size_t)tam, sizeof(Elo)); // Calocc inicializa com NULL

	return t;
}

void destroiS(TabSim *t){
	for (int i = 0; i < t->tamanho; i++){
		Elo *del = &(t->Tabela[i]);
		while (del->prox != NULL){
			free(del->valor);
			// free(del->chave);
			free(del->nome);
			Elo *aux = del->prox;
			free(del);
			del = aux;
		}
	}
	free(t->Tabela);
	free(t);
}

int insereS(TabSim t, char *n, Elemento *val){

	int h = hashFun(n, t.tamanho);

	// Criando um Elo com as informaçoes passadas
	Elo aux;
	aux.chave = h;
	aux.valor = val;
	aux.nome = n;
	aux.prox = NULL;

	Elo *sec = &(t.Tabela[h]);

	if (sec == NULL){
		sec = &aux;

		return 1; // Inserçao bem sucedida
	}

	while (sec->prox != NULL)
		sec = sec->prox;

	sec->prox = &aux;

	return 1; // Inserçao bem sucedida

}

Elemento *buscaS(TabSim t, char *n){

	int h = hashFun(n, t.tamanho);

	Elo *sec = &(t.Tabela[h]);

	while (sec != NULL && strcmp(n, sec->nome) > 0)
		sec = sec->prox;

	return sec->valor;

}

int retiraS(TabSim t, char *n){

	int h = hashFun(n, t.tamanho);

	Elo *pr, *ant, *at;

	at = &(t.Tabela[h]);
	while (strcmp(at->nome, n) > 0){
		at = at;
		at = at->prox;
		pr = at->prox;
	}

	free(at->nome);
	free(at->valor);
	free(at->prox);
	free(at);

	ant->prox = pr;

	// Pq esse caralhos e uma func int e nao uma void???????????
}
