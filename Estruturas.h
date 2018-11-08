# ifndef _Estruturas_h // Avoiding conflicts errors
# define _Estruturas_h 

struct ele;

struct tb; // Declaring before, because there is a circular use

typedef char Bool;

#define True 1;
#define False 0;

typedef struct ele{
	char *desc; // Only for testador3000 keep working
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
		// If it is an obj, uses atributo
		// If is ts an exit, uses saidas
		struct ele **saidas; // Remember to inittialize // [0] = N, [1] = L, [2] = S, [3] = O
		struct tb *atributos;
	} atrida;

} Elemento;

// Componentes of my hashTable
typedef struct Elo{
	int chave;
	char *nome;
	Elemento *valor; // to be defined
	struct Elo *prox;
} Elo;

// Hashtable itself
typedef struct tb{
	int tamanho;
	Elo **Tabela;
} TabSim;

// components of my list
typedef struct EloL{
	Elemento *valor; // to be defined
	struct EloL *prox;
} EloL;


// Head of linked list
typedef struct{
	int tamanho;
	EloL *Lista;
} Lista;

// Creating a struct just for the character
typedef struct{
	char *nome; // Can ask in the game
	Elemento *salaAtual;
	Elemento **mochila;

} Personagem;

# endif