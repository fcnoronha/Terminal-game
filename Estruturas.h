#pragma once 

struct ele;

struct tb; // Declarando antees, pois ha um uso circular;

typedef char Bool;

#define True 1;
#define False 0;

typedef struct ele{
	char *desc; // So pro tetador continuar funcioando
	char *nome;
	char *curta;
	char *longa;
	Bool ativo;
	Bool visivel;
	struct ele **conteudo;
	/*
	fun *açoes -> lista de ponteiros para funçoes
	lista do genero: 
		typedef Elemento (* FPTR ) ( int ) ;
		FPTR *açoess
	*/
	//?? *animaçao -> ponteiro para funçao que ira fazer uma animaçao
	Bool isLugar;
	Bool isCoisa;

	union{
		// Se for uma coisa, importa atributo
		// Se for um lugar, importa saida
		struct ele *saidas;
		struct tb *atributos;
	} atrida;

} Elemento;

// Elos da minha HashTable, que formam uma lista linkada
typedef struct Elo{
	int chave;
	char *nome;
	Elemento *valor; // a ser definido
	struct Elo *prox;
} Elo;

// Hashtable em si
typedef struct tb{
	int tamanho;
	Elo **Tabela;
} TabSim;

// Elos da minha Lista, que formam uma lista linkada
typedef struct EloL{
	Elemento *valor; // a ser definido
	struct EloL *prox;
} EloL;


// Aponta pro primeiro elemento da lista
typedef struct{
	int tamanho;
	EloL *Lista;
} Lista;
