#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"hashTable.h" // Usando meu cabeçalho


int hashFun(char *n, int tam){
	// Retorna a chave, valor hash, da string dada.
	int chave, lst, i = 0;
	while (n[i] != '\0'){
		chave += (int)n[i]; // Soma todos valores ASCII
		lst = n[i];
		i++;
	}
	chave /= lst; // Divide pelo valor ASCII do ultimo caractere
	chave %= tam; // Modulo tamanho da tabela
	return chave;
}

TabSim *criaS(int tam){
	TabSim *t;	// Ponteiro que representara a tabela;
	t = malloc(sizeof(TabSim));

	t->tamanho = tam;
	t->Tabela = calloc((size_t)tam, sizeof(Elo)); // Calocc inicializa com NULL

	return t;
}

void destroiS(TabSim *t){

	for (int i = 0; i < t->tamanho; i++){	// Percorre todas as chaves da lista
		Elo *del = t->Tabela[i];

		while (del->prox != NULL){	// Percorre todos os elos daquele valor
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
	Elo *aux;
	aux->chave = h;
	aux->valor = val;
	aux->nome = n;
	aux->prox = NULL;

	Elo *sec = t.Tabela[h];	// Pego a lista que vai conter todos os elos dql valor

	if (sec == NULL){ // Caso ainda nao tenha nenhum elo nql valor
		sec = aux;
		return 1; // Inserçao bem sucedida
	}

	while (sec->prox != NULL)
		sec = sec->prox;

	sec->prox = aux;

	return 1; // Inserçao bem sucedida
}

Elemento *buscaS(TabSim t, char *n){

	int h = hashFun(n, t.tamanho);

	Elo *sec = t.Tabela[h]; // Pegando a lista linkada dql valor

	if (sec == NULL) return NULL; // Caso nao tenha elos com o valor

	while (sec != NULL && strcmp(n, sec->nome) > 0) 
		sec = sec->prox; // Compara ate achar na lista encadeada

	return sec->valor;

}

int retiraS(TabSim t, char *n){

	int h = hashFun(n, t.tamanho);

	Elo *pr, *ant, *at;

	at = t.Tabela[h]; // Primeiro elo da lista encadeada daql valor

	if (at == NULL)
		return 0; // Erro

	if (at != NULL && strcmp(at->nome, n) == 0){
		t.Tabela[h] = at->prox;
		free(at->nome);
		free(at->valor);
		// free(at->prox);
		free(at);

		return 1; // Sucesso
	}

	while (at != NULL && strcmp(at->nome, n) > 0){ // Caso nao seja oq estou procurando
		ant = at; 
		at = at->prox;
		pr = at->prox;
	}

	if (strcmp(at->nome, n) == 0){ // Checando se eu achei o coiso
		free(at->nome);
		free(at->valor);
		// free(at->prox);
		free(at);

		ant->prox = pr;

		return 1; // Sucesso
	}

	return 0; // Erro
}
