# ifndef _Estruturas_h // Avoiding conflict errors
# define _Estruturas_h 

// Declaring before, because there is a circular use
typedef struct ele Elemento;

typedef struct p Personagem;

struct tb; 

typedef enum {false, true} boolean;

typedef enum {NORTE, LESTE, SUL, OESTE, NULO = -1} dir;

// ------------------ HASHTABLE

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

// ------------------ LINKED LIST

// My function pointer
typedef int (*FPTR)(Personagem*, Elemento*);

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
typedef struct l{
	int tamanho;
	EloL *Lista;
} Lista;

// ---------------------------------

// Creating a struct just for the character
struct p {
	char nome[20]; // ask in the game
	Elemento *salaAtual;
	Lista *mochila;
	int visitadas;
};

struct ele{
	char *desc;
	char *nome;
	char *curta;
	char *longa;
	boolean ativo;
	boolean visitado;
	Lista *conteudo;
	Lista *funEspecificas;
	//?? *animaçao -> ponteiro para funçao que ira fazer uma animaçao
	boolean isLugar;
	boolean isCoisa;

	union{
		// If is ts an exit, uses saidas
		struct ele **saidas; // [0] = N, [1] = L, [2] = S, [3] = O
		// If it is an obj, uses atributo
		struct tb *atributos;
	} atrida;
};

# endif
