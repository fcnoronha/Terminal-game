#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"hashTable.h" // Usando meu cabeçalho

int hashFun(char *n, int tam)
{
	int chave = 0, lst, i = 0;
	while (n[i] != '\0'){
		chave += (int)n[i]; // Soma todos valores ASCII
		lst = n[i];
		i++;
	}
	chave /= lst; // Divide pelo valor ASCII do ultimo caractere
	chave %= tam; // Modulo tamanho da tabela
	return chave;
}

TabSim *criaS(int tam)
{
	TabSim *t = NULL;	// Ponteiro que representara a tabela;
	t = malloc(sizeof(TabSim));
	if (t == NULL) return NULL; // Erro

	t->tamanho = tam;
	t->Tabela = malloc(tam * sizeof(Elo*));
	if (t->Tabela == NULL) return NULL; // Erro

	for (int i = 0; i < tam; i++){
		t->Tabela[i] = NULL; // Inicializando valores com NULL
	}

	return t;
}

void destroiS(TabSim *t)
{
	// Percorre todas as chaves da lista
	for (int i = 0; i < t->tamanho; i++){

		Elo *del = t->Tabela[i];
		while (del != NULL && 0){	// Percorre todos os elos daquele valor
			// free(del->valor);
			// free(del->chave);
			free(del->nome);
			Elo *aux = del;
			del = del->prox;
			free(aux);
		}
		free(t->Tabela[i]);
	}
	free(t->Tabela);
	free(t);
}

int insereS(TabSim *t, char *n, Elemento *val)
{
	int h = hashFun(n, t->tamanho);

	// Nao foi possivel inserir pq o elemento ja existe
	if (buscaS(t, n) != NULL) return 0;

	// Criando um Elo com as informaçoes passadas
	Elo *aux = malloc(sizeof(Elo));
	aux->chave = h;
	aux->valor = val;
	aux->nome = n;
	aux->prox = NULL;

	// Pego a lista que vai conter todos os elos dql valor
	Elo *sec = t->Tabela[h];

	// Caso ainda nao tenha nenhum elo nql valor
	if (sec == NULL){
		t->Tabela[h] = aux;
		return 1; // Inserçao bem sucedida
	}

	// Percorrendo lista linkada ate chegar no final
	while (sec->prox != NULL)
		sec = sec->prox;

	// Adicionando elo no final
	sec->prox = aux;

	// Inserçao bem sucedida
	return 1;
}

Elemento *buscaS(TabSim *t, char *n)
{
	int h = hashFun(n, t->tamanho);

	Elo *sec = t->Tabela[h]; // Pegando a lista linkada dql valor
	if (sec == NULL) return NULL; // Caso nao tenha elos com o valor

	while (sec->prox != NULL && strcmp(n, sec->nome) != 0){
		sec = sec->prox; // Compara ate achar na lista encadeada
	}

	// Caso eu tenha chegado noq eu quero
	if (strcmp(n, sec->nome) == 0)
		return sec->valor;

	return NULL; // Nao achei
}

int retiraS(TabSim *t, char *n)
{
	int h = hashFun(n, t->tamanho);

	// Ponteiros auxiliares, usados para religar elos da lista linkada
	Elo *proximo, *anterior, *atual;

	// Primeiro elo da lista encadeada daql valor
	atual = t->Tabela[h];

	if (atual == NULL)
		return 0; // Erro

	// Usando a busca para ver se o dado elemento esta na minha lista
	if (buscaS(t, n) == NULL) return 0;

	// Caso o primeiro elo da lista seja o que deva ser excluido
	if (atual != NULL && strcmp(atual->nome, n) == 0){

		t->Tabela[h] = atual->prox;
		//free(atual->nome);
		//free(atual->valor);
		//free(atual->prox);
		free(atual);

		return 1; // Sucesso
	}

	// Percorre a lista ate chegar no elo desejado
	while (atual->prox != NULL && strcmp(atual->nome, n) != 0){ // Caso nao seja oq estou procurando
		anterior = atual;
		atual = atual->prox;
		proximo = atual->prox;
	}

	// Checando se eu achei o coiso
	if (strcmp(atual->nome, n) == 0){
		// free(atual->nome);
		// free(atual->valor);
		// free(atual->prox);
		free(atual);

		anterior->prox = proximo; // Religando elo anterior e posterior ao excluido

		return 1; // Sucesso
	}

	return 0; // Erro
}
