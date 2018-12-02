#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashTable.h"
#include"ListaValores.h"
#include"acoes.h"
#include"parser.tab.h"

// For lexical and grammar interpretation
extern int yyparse();

// Defining global variables in order to make them acessible to every function

// Rooms
Elemento *identidade;
Elemento *prazer;
Elemento *racional;
Elemento *memoria;
Elemento *medo;
Elemento *ego;

// Objects
Elemento *banquete;
Elemento *livro;
Elemento *espinhos;
Elemento *album;

// Character
Personagem *pessoa;

// Dictionary
TabSim *dicionario;

// Global functions that can be perfomed by the character
Lista *funGlobais;

/*

		 EGO --  PRAZER	
					^
					|
					v
 MEMORIA  <--> IDENTIDADE <-->  RACIONAL
		 		    ^
		 		    |
		|_______>  MEDO      <______|

*/


void inicializa()
{

	int flag = 0;
	EloL *f; // Auxiliar pointer to define functions

	// INITIALIZING POINTERS
	banquete = malloc(sizeof(Elemento));
	livro = malloc(sizeof(Elemento));
	espinhos = malloc(sizeof(Elemento));
	album = malloc(sizeof(Elemento));
	identidade = malloc(sizeof(Elemento));
	prazer = malloc(sizeof(Elemento));
	racional = malloc(sizeof(Elemento));
	memoria = malloc(sizeof(Elemento));
	medo = malloc(sizeof(Elemento));
	ego = malloc(sizeof(Elemento));


	// INITIALIZING OBJECTS

	// 'Banquete' object
	banquete->nome = "Um banquete.";
	banquete->curta = "Uma mesa imensa com milhares de pratos de comida diferentes e maravilhosos. Desde doces, salgados ou agridoces.";
	banquete->ativo = true;
	banquete->funEspecificas = criaL();

	f = malloc(sizeof(EloL));
	f->tag = "pegar";
	f->inst.fun = pegar;
	f->prox = NULL;
	flag += insereElol(banquete->funEspecificas, f);

	// *animaçao
	banquete->isLugar = false;
	banquete->isCoisa = true;

	// 'livro' object
	livro->nome = "Um livro.";
	livro->curta = "Um livro enorme, mas não tanto a ponto de exceder o tamanho de um ser humano, com capa azul está diante de você.";
	livro->ativo = true;
	livro->desc = NULL;
	livro->funEspecificas = criaL();

	f = malloc(sizeof(EloL));
	f->tag = "abrir";
	f->inst.fun = abrir;
	f->prox = NULL;
	flag += insereElol(livro->funEspecificas, f);

	f = malloc(sizeof(EloL));
	f->tag = "escrever";
	f->inst.fun = escrever;
	f->prox = NULL;
	flag += insereElol(livro->funEspecificas, f);

	// *animaçao
	livro->isLugar = false;
	livro->isCoisa = true;

	// 'espinhos' object
	espinhos->nome = "Uns espinhos.";
	espinhos->curta = "Você sente algo pontudo e perfurante em suas mãos, como se fosse uma bola de agulhas. Isso te machuca.";
	espinhos->ativo = true;
	espinhos->funEspecificas = criaL();

	f = malloc(sizeof(EloL));
	f->tag = "soltar";
	f->inst.fun = soltar;
	f->prox = NULL;
	flag += insereElol(espinhos->funEspecificas, f);

	f = malloc(sizeof(EloL));
	f->tag = "quebrar";
	f->inst.fun = quebrar;
	f->prox = NULL;
	flag += insereElol(espinhos->funEspecificas, f);

	// *animaçao
	espinhos->isLugar = false;
	espinhos->isCoisa = true;

	// 'album' object
	album->nome = "Um album.";
	album->curta = "É o maior álbum de fotografias que você já viu.";
	album->ativo = true;
	album->desc = NULL;
	album->funEspecificas = criaL();

	f = malloc(sizeof(EloL));
	f->tag = "abrir";
	f->inst.fun = abrir;
	f->prox = NULL;
	flag += insereElol(album->funEspecificas, f);

	f = malloc(sizeof(EloL));
	f->tag = "pegar";
	f->inst.fun = pegar;
	f->prox = NULL;
	flag += insereElol(album->funEspecificas, f);
	// *animaçao
	album->isLugar = false;
	album->isCoisa = true;

	// INITIALIZING ROOMS

	// 'identidade' room
	identidade->nome = "Identidade";
	identidade->curta = "Você não vê nada.";
	identidade->longa = "Não importa para onde você olhe, não há paredes, nem portas, nem janelas.";
	identidade->ativo = true;
	identidade->visitado = false;
	identidade->funEspecificas = criaL();
	identidade->conteudo = criaL();

	// fun *açoes -> lista de ponteiros para funçoes
	// *animaçao -> ponteiro para funçao que ira fazer uma animaçao
	identidade->isLugar = true;
	identidade->isCoisa = false;
	// 4 directions and their respective rooms
	identidade->atrida.saidas = malloc(4 * sizeof(Elemento*));
	identidade->atrida.saidas[NORTE] = prazer;
	identidade->atrida.saidas[LESTE] = racional;
	identidade->atrida.saidas[SUL] = NULL;
	identidade->atrida.saidas[OESTE] = memoria;

	
	// 'prazer' room
	prazer->nome = "Prazer";
	prazer->curta = "Tudo é vermelho.";
	prazer->longa = "Ao seu redor não há outras cores além de um vermelho cor de fogo.";
	prazer->ativo = true;
	prazer->visitado = false;

	prazer->funEspecificas = criaL();
	prazer->conteudo = criaL();
	EloL *b = malloc(sizeof(EloL));
	b->tag = "banquete";
	b->inst.obj = banquete;
	b->prox = NULL;
	flag += insereElol(prazer->conteudo, b);

	// fun *açoes 
	// *animaçao 
	prazer->isLugar = true;
	prazer->isCoisa = false;
	prazer->atrida.saidas = malloc(4 * sizeof(Elemento*));
	prazer->atrida.saidas[NORTE] = NULL;
	prazer->atrida.saidas[LESTE] = NULL;
	prazer->atrida.saidas[SUL] = identidade;
	prazer->atrida.saidas[OESTE] = ego;

	
	// 'racional' room
	racional->nome = "Racional";
	racional->curta = "Azul é tudo que seus olhos conseguem captar.";
	racional->longa = "Você se vê imerso em um azul sem fim, que escorre por todas as direções do seu olhar.";
	racional->ativo = true;
	racional->visitado = false;

	racional->funEspecificas = criaL();
	racional->conteudo = criaL();
	EloL *l= malloc(sizeof(EloL));
	l->tag = "livro";
	l->inst.obj = livro;
	l->prox = NULL;
	flag += insereElol(racional->conteudo, l);

	// fun *açoes 
	// *animaçao 
	racional->isLugar = true;
	racional->isCoisa = false;
	// 4 directions and their respective rooms
	racional->atrida.saidas = malloc(4 * sizeof(Elemento*));
	racional->atrida.saidas[NORTE] = NULL;
	racional->atrida.saidas[LESTE] = NULL;
	racional->atrida.saidas[SUL] = medo;
	racional->atrida.saidas[OESTE] = identidade;
	

	// 'memoria' room
	memoria->nome = "Memoria";
	memoria->curta = "Verde é tudo que você consegue ver.";
	memoria->longa = "Você vê uma luz verde iluminando tudo ao seu redor.";
	memoria->ativo = true;
	memoria->visitado = false;

	memoria->funEspecificas = criaL();
	memoria->conteudo = criaL();
	EloL *a = malloc(sizeof(EloL));
	a->tag = "album";
	a->inst.obj = album;
	a->prox = NULL;
	flag += insereElol(memoria->conteudo, a);

	// fun *açoes
	// *animaçao
	memoria->isLugar = true;
	memoria->isCoisa = false;
	// 4 directions and their respective rooms
	memoria->atrida.saidas = malloc(4 * sizeof(Elemento*));
	memoria->atrida.saidas[NORTE] = NULL;
	memoria->atrida.saidas[LESTE] = identidade;
	memoria->atrida.saidas[SUL] = medo;
	memoria->atrida.saidas[OESTE] = NULL;


	// 'ego' room
	ego->nome = "Ego";
	ego->curta = "...";
	ego->longa = "...";
	ego->ativo = false;
	ego->visitado = false;

	ego->funEspecificas = criaL();
	ego->conteudo = criaL();

	// fun *açoes
	// *animaçao
	ego->isLugar = true;
	ego->isCoisa = false;
	// 4 directions and their respective rooms
	ego->atrida.saidas = malloc(4 * sizeof(Elemento*));
	ego->atrida.saidas[NORTE] = NULL;
	ego->atrida.saidas[LESTE] = prazer;
	ego->atrida.saidas[SUL] = NULL;
	ego->atrida.saidas[OESTE] = NULL;
	

	// 'medo' room
	medo->nome = "Medo";
	medo->curta = "Está tudo completamente escuro.";
	medo->longa = "Não há luz alguma. Você está completamente no escuro.";
	medo->ativo = false;
	medo->visitado = false;

	medo->funEspecificas = criaL();
	medo->conteudo = criaL();

	EloL *e = malloc(sizeof(EloL));
	e->tag = "espinhos";
	e->inst.obj = espinhos;
	e->prox = NULL;
	flag += insereElol(medo->conteudo, e);

	// fun *açoes
	// *animaçao
	medo->isLugar = true;
	medo->isCoisa = false;
	// 4 directions and their respective rooms
	medo->atrida.saidas = malloc(4 * sizeof(Elemento*));
	medo->atrida.saidas[NORTE] = identidade;
	medo->atrida.saidas[LESTE] = NULL;
	medo->atrida.saidas[SUL] = NULL;
	medo->atrida.saidas[OESTE] = NULL;

	// Initializing the character
	pessoa = malloc(sizeof(Personagem));
	pessoa->salaAtual = identidade;
	pessoa->mochila = criaL();
	pessoa->visitadas = 0;

	// INITIALIZING DICTIONARY
	dicionario = criaS(100);
	// With this, if you search "agarrar" in the dictionary, the returned
	// value will be "pegar".
	flag += insereSin(dicionario, "agarrar", "pegar");
	flag += insereSin(dicionario, "pegar", "pegar");
	flag += insereSin(dicionario, "andar", "andar");
	flag += insereSin(dicionario, "vai", "andar");
	flag += insereSin(dicionario, "move", "andar");
	flag += insereSin(dicionario, "soltar", "soltar");
	flag += insereSin(dicionario, "deixar", "soltar");
	flag += insereSin(dicionario, "escrever", "escrever");
	flag += insereSin(dicionario, "quebrar", "quebrar");
	flag += insereSin(dicionario, "destroi", "quebrar");
	flag += insereSin(dicionario, "abrir", "abrir");
	flag += insereSin(dicionario, "ler", "abrir");
	flag += insereSin(dicionario, "info", "info");

	flag += insereSin(dicionario, "banquete", "banquete");
	flag += insereSin(dicionario, "livro", "livro");
	flag += insereSin(dicionario, "espinhos", "espinhos");
	flag += insereSin(dicionario, "album", "album");
	flag += insereSin(dicionario, "norte", "NORTE");
	flag += insereSin(dicionario, "sul", "SUL");
	flag += insereSin(dicionario, "leste", "LESTE");
	flag += insereSin(dicionario, "oeste", "OESTE");
	flag += insereSin(dicionario, "frente", "NORTE");
	flag += insereSin(dicionario, "tras", "SUL");
	flag += insereSin(dicionario, "direita", "LESTE");
	flag += insereSin(dicionario, "esquerda", "OESTE");
	
	// More synonyms must be defined...


	// DEFINING GLOBAL FUNCTIONS
	funGlobais = criaL();

	f = malloc(sizeof(EloL));
	f->tag = "andar";
	f->inst.fun = andar;
	f->prox = NULL;
	flag += insereElol(funGlobais, f);

	visitaSala(pessoa);
}

void destroier()
{

	free(identidade->atrida.saidas);
	destroiL(identidade->conteudo);
	destroiL(identidade->funEspecificas);
	free(identidade); 
	free(prazer->atrida.saidas);
	destroiL(prazer->conteudo);
	destroiL(prazer->funEspecificas);
	free(prazer);
	free(racional->atrida.saidas); 
	destroiL(racional->conteudo);
	destroiL(racional->funEspecificas);
	free(racional);
	free(memoria->atrida.saidas);
	destroiL(memoria->conteudo); 
	destroiL(memoria->funEspecificas);
	free(memoria);
	free(medo->atrida.saidas);
	destroiL(medo->conteudo);
	destroiL(medo->funEspecificas);
	free(medo);
	free(ego->atrida.saidas);
	destroiL(ego->conteudo);
	destroiL(ego->funEspecificas);
	free(ego);


	destroiL(banquete->funEspecificas);
	free(banquete);
	destroiL(livro->funEspecificas);
	free(livro);
	destroiL(espinhos->funEspecificas);
	free(espinhos);
	destroiL(album->funEspecificas);
	free(album);

	destroiL(pessoa->mochila);
	free(pessoa);

	destroiS(dicionario);

	destroiL(funGlobais);
}

void finalizaJogo()
{
	printf("Parece que as coisas estão mais claras agora\n");
	destroier();
}

void mudaAtivo()
{
	if (pessoa->visitadas > 3)
		medo->ativo = true;
	if (pessoa->salaAtual == identidade && pessoa->visitadas == 5)
		finalizaJogo();
}

FPTR buscaFun(char *verbo, char *objeto)
{
	verbo = buscaSin(dicionario, verbo);
	objeto = buscaSin(dicionario, objeto);

	if (verbo == NULL)
		return NULL;

	// View in the objects of the room
	EloL *bus = buscaElol(pessoa->salaAtual->conteudo, objeto);
	if (bus != NULL){
		bus = buscaElol(bus->inst.obj->funEspecificas, verbo);
	}

	if (bus != NULL)
		return bus->inst.fun;


	// View in the functions of the room
	bus = buscaElol(pessoa->salaAtual->funEspecificas, verbo);
	if (bus != NULL)
		return bus->inst.fun;

	// View in general functions
	bus = buscaElol(funGlobais, verbo);
	if (bus != NULL)
		return bus->inst.fun;

	// Didn't find anything
	return NULL;
}

dir charToDir(char *x)
{	
	if (strcmp("NORTE", x) == 0)
		return NORTE;
	if (strcmp("SUL", x) == 0)
		return SUL;
	if (strcmp("OESTE", x) == 0)
		return OESTE;
	if (strcmp("LESTE", x) == 0)
		return LESTE;

	return NORTE; // Default
}

void testador6000()
{
	printf("\n\n INCIALIZANDO TESTE \n\n");

	destroier();
	inicializa();

	printf("sinonimo de %s : %s\n", "agarrar", buscaSin(dicionario, "agarrar"));
	printf("sinonimo de %s : %s\n", "vai", buscaSin(dicionario, "vai"));
	printf("sinonimo de %s : %s\n", "deixar", buscaSin(dicionario, "deixar"));
	printf("sinonimo de %s : %s\n", "banquete", buscaSin(dicionario, "banquete"));
	printf("sinonimo de %s : %s\n", "norte", buscaSin(dicionario, "norte"));
	printf("sinonimo de %s : %s\n", "frente", buscaSin(dicionario, "frente"));
	printf("sinonimo de %s : %s\n", "info", buscaSin(dicionario, "info"));
	printf("sinonimo de %s : %s\n", "ler", buscaSin(dicionario, "ler"));

	int flag, cont = 1;

	printf("\n Ação: %d\n", cont++);

	FPTR doing = buscaFun("andar", "sul");
	if (doing == NULL) printf("Não achei\n");

	dir direcao = charToDir(buscaSin(dicionario, "sul"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the identidade room


	printf("\n Ação: %d\n", cont++);
	
	direcao = charToDir(buscaSin(dicionario, "frente"));
	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the prazer room


	printf("\n Ação: %d\n", cont++);

    doing = buscaFun("pegar", "banquete");
	if (doing == NULL) printf("Não achei\n");

	flag = doing(pessoa, banquete);
	if (flag) printf("PEGUEI!\n");
	else printf("Não peguei\n");
	// Put 'banquete' in my bag


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "sul");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "sul"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the identidade room


	printf("\n Ação: %d\n", cont++);

	direcao = charToDir(buscaSin(dicionario, "leste"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the 'racional' room


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("pegar", "livro");
	if (doing == NULL) printf("Não achei\n");

 	doing = buscaFun("abrir", "livro");
	if (doing == NULL) printf("Não achei\n");
	
	flag = doing(pessoa, livro);
	// Opening the 'livro'


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("escrever", "livro");
	if (doing == NULL) printf("Não achei\n");
	flag = doing(pessoa, livro);
	// Writing in 'livro'


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("abrir", "livro");
	if (doing == NULL) printf("Não achei\n");

	flag = doing(pessoa, livro);
	// Opening the 'livro'


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "sul");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "sul"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// Tryed to walk south


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "esquerda");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "esquerda"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the 'identidade'room


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "esquerda");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "esquerda"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the 'memoria' room


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("abrir", "album");
	if (doing == NULL) printf("Não achei\n");

	flag = doing(pessoa, album);
	// Reading 'album'


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "sul");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "sul"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the 'medo' room


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("soltar", "espinhos");
	if (doing == NULL) printf("Não achei\n");

	flag = doing(pessoa, espinhos);
	// Tryed to get loose


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("quebrar", "espinhos");
	if (doing == NULL) printf("Não achei\n");

	flag = doing(pessoa, espinhos);
	// Tryed to break


	printf("\n Ação: %d\n", cont++);

	doing = buscaFun("andar", "frente");
	if (doing == NULL) printf("Não achei\n");

	direcao = charToDir(buscaSin(dicionario, "frente"));

	flag = doing(pessoa, pessoa->salaAtual->atrida.saidas[direcao]);
	if (flag == 1) printf("Mudei de sala\n");
	else if (flag == 2) printf("Ainda não posso entrar\n");
	else if (flag == 0) printf("Não existe sala nesta direção\n");
	// I'm in the 'identidade' room

	destroier();
	inicializa();

	printf("\n\n TESTE FINALIZADO \n\n");
}

int main(){
	// Starting description
	printf("\nVocê não sabe onde está.\nDe todos os lados o único sentimento que te consome é um vazio.\
Não há cores, odores, sabores, seus sentidos não captam nada.\nVocê percebe que essa confusão e indefinição\
 são reflexos de quem você é, pois como este lugar, você não se conhece. \nVocê está no cerne de sua mente, sua IDENTIDADE.\
 E irá começar uma jornada em busca de QUEM VOCÊ É.\n\n");
		
	// Initializing games components
	inicializa();	

	// Running game
	while (yyparse());

	// Ending game
	destroier();
	return 0; 

}
