
typedef struct{
	// ??????
	char desc[100];
} Elemento;

// Elos da minha HashTable, que formam uma lista linkada
typedef struct Elo{
	int chave;
	char *nome;
	Elemento *valor; // a ser definido
	struct Elo *prox;
} Elo;

// Hashtable em si
typedef struct{
	int tamanho;
	Elo **Tabela;
} TabSim;

TabSim *criaS(int);

void destroiS(TabSim*);

int insereS(TabSim, char*, Elemento*);

Elemento *buscaS(TabSim, char*);

int retiraS(TabSim, char*);