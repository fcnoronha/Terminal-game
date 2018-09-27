
typedef struct{
	// ??????
	char desc[100];
} Elemento;

// Elos da minha HashTable, que formam uma lista linkada
typedef struct EloL{
	Elemento *valor; // a ser definido
	struct EloL *prox;
} EloL;
	
// Hashtable em si
typedef struct{
	int tamanho;
	Elo **Lista;
} Lista;


Lista criaL(int tam);

void destroiL(Lista l);

Elemento * insereL(Lista l, Elemento *val);

Elemento * buscaL(Lista l, char *n);

Elemento * retiraL(Lista l, Elemento *val);