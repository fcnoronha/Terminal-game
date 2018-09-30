
typedef struct{
	char desc[100];
} Elemento;

// Elos da minha Lista, que formam uma lista linkada
typedef struct EloL{
	Elemento *valor; // a ser definido
	struct EloL *prox;
} EloL;
<<<<<<< HEAD
	
// Aponta pro primeiro elemento da lista
=======

// Hashtable em si
>>>>>>> refs/remotes/origin/master
typedef struct{
	int tamanho;
	EloL *Lista;
} Lista;


Lista * criaL();

void destroiL(Lista *l);

Elemento * insereL(Lista *l, Elemento *val);

Elemento * buscaL(Lista *l, Elemento *val);

Elemento * retiraL(Lista *l, Elemento *val);
