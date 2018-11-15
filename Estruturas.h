# ifndef _Estruturas_h // Avoiding conflicts errors
# define _Estruturas_h 

struct ele;

struct tb; // Declaring before, because there is a circular use

typedef enum {false, true} boolean;

typedef enum {NORTE, LESTE, SUL, OESTE} dir;

typedef struct ele{
	char *desc; // Only for testador3000 keep working
	char *nome;
	char *curta;
	char *longa;
	boolean ativo;
	boolean visitado;
	struct ele **conteudo;
	/*
	fun *açoes -> lista de ponteiros para funçoes
	lista do genero: 
		typedef Elemento (* FPTR ) ( int ) ;
		FPTR *açoess
	*/
	//?? *animaçao -> ponteiro para funçao que ira fazer uma animaçao
	boolean isLugar;
	boolean isCoisa;

	union{
		// If is ts an exit, uses saidas
		struct ele **saidas; // [0] = N, [1] = L, [2] = S, [3] = O
		// If it is an obj, uses atributo
		struct tb *atributos;
	} atrida;

} Elemento;

// Componentes of my hashTable
typedef struct Elo{
	int chave;
	char *sinonimo;
	char *nome;
	Elemento *valor; // to be defined
	struct Elo *prox;
} Elo;

// Hashtable itself
typedef struct tb{
	int tamanho;
	Elo **Tabela;
} TabSim;

// My function pointer
typedef int (*FPTR)(Elemento*, Elemento*);

// Defining union to be used in the linked list
typedef union e{
	Elemento *obj;
	FPTR fun; // Make instc.fun = dumbFunction;
} Elecao;

// components of my linked list
typedef struct EloL{
	char *tag; // Used to find something in the list
	Elecao inst;
	Elemento *valor; // Just for the tester to keep working
	char *info; // about what is the component of the union
	struct EloL *prox;
} EloL;

// Head of linked list
typedef struct{
	int tamanho;
	EloL *Lista;
} Lista;

// Creating a struct just for the character
typedef struct{
	char nome[20]; // Can ask in the game
	Elemento *salaAtual;
	Elemento **mochila;

} Personagem;

# endif