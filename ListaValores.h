
typedef struct{
	char desc[100];
} Elemento;

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


Lista * criaL(int tam);

void destroiL(Lista *l);

Elemento * insereL(Lista *l, Elemento *val);

Elemento * buscaL(Lista *l, Elemento *val);

Elemento * retiraL(Lista *l, Elemento *val);