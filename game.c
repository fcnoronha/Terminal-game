#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashTable.h"
#include"ListaValores.h"
#include"acoes.h"

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
					|
	MEMORIA	--	IDENTIDADE  --    RACIONAL
				    |
		|_______		   MEDO        ______|

*/


void inicializa(){

	int flag = 0;

	// INITIALIZING OBJECTS

	// 'Banquete' object
	banquete = malloc(sizeof(Elemento));
	banquete->nome = "Um banquete.";
	banquete->curta = "Uma mesa imensa com milhares de pratos de comida diferentes e maravilhosos. Desde doces, salgados ou agridoces.";
	banquete->ativo = true;
	// fun *açoes
	// *animaçao
	banquete->isLugar = false;
	banquete->isCoisa = true;

	// 'livro' object
	livro = malloc(sizeof(Elemento));
	livro->nome = "Um livro.";
	livro->curta = "Um livro enorme, mas não tanto a ponto de exceder o tamanho de um ser humano, com capa azul está diante de você.";
	livro->ativo = true;
	livro->desc = '\0';
	// fun *açoes
	// *animaçao
	livro->isLugar = false;
	livro->isCoisa = true;

	// 'espinhos' object
	espinhos = malloc(sizeof(Elemento));
	espinhos->nome = "Uns espinhos.";
	espinhos->curta = "Você sente algo pontudo e perfurante em suas mãos, como se fosse uma bola de agulhas. Isso te machuca.";
	espinhos->ativo = true;
	// fun *açoes
	// *animaçao
	espinhos->isLugar = false;
	espinhos->isCoisa = true;

	// 'album' object
	album = malloc(sizeof(Elemento));
	album->nome = "Um album.";
	album->curta = "É o maior álbum de fotografias que você já viu.";
	album->ativo = true;
	album->desc = '\0';
	// fun *açoes
	// *animaçao
	album->isLugar = false;
	album->isCoisa = true;

	// INITIALIZING ROOMS

	// 'identidade' room
	identidade = malloc(sizeof(Elemento));
	identidade->nome = "Identidade";
	identidade->curta = "Voce nao ve nada.";
	identidade->longa = "Nao importa para onde voce olhe, nao ha paredes, nem portas, nem janelas.";
	identidade->ativo = true;
	identidade->visitado = false;

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
	identidade->atrida.saidas[OESTE] = NULL;

	
	// 'prazer' room
	prazer = malloc(sizeof(Elemento));
	prazer->nome = "Prazer";
	prazer->curta = "Tudo e vermelho.";
	prazer->longa = "Ao seu redor nao ha outras cores alem de um vermelho cor de fogo.";
	prazer->ativo = true;
	prazer->visitado = false;


	prazer->conteudo = criaL();
	EloL *b = malloc(sizeof(EloL));
	b->tag = "Banquete";
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
	racional = malloc(sizeof(Elemento));
	racional->nome = "Racional";
	racional->curta = "Azul e tudo que seus olhos conseguem captar.";
	racional->longa = "Voce se ve imerso em um azul sem fim, que escorre por todas as direcoes do seu olhar.";
	racional->ativo = true;
	racional->visitado = false;

	racional->conteudo = criaL();
	EloL *l= malloc(sizeof(EloL));
	l->tag = "Livro";
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
	memoria = malloc(sizeof(Elemento));
	memoria->nome = "Memoria";
	memoria->curta = "Verde e tudo que voce consegue ver.";
	memoria->longa = "Voce ve uma luz verde iluminando tudo ao seu redor.";
	memoria->ativo = true;
	memoria->visitado = false;

	memoria->conteudo = criaL();
	EloL *a = malloc(sizeof(EloL));
	a->tag = "Album";
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
	ego = malloc(sizeof(Elemento));
	ego->nome = "Ego";
	ego->curta = "...";
	ego->longa = "...";
	ego->ativo = false;
	ego->visitado = false;

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
	medo = malloc(sizeof(Elemento));
	medo->nome = "Medo";
	medo->curta = "Esta tudo completamente escuro.";
	medo->longa = "Nao ha luz alguma. Voce esta completamente no escuro.";
	medo->ativo = false;
	medo->visitado = false;

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
	pessoa->salaAtual = prazer;
	pessoa->mochila = criaL();

	// INITIALIZING DICTIONARY
	dicionario = criaS(100);
	// With this, if you search "agarra" in the dictionary, the returned
	// value will be "pega".
	flag += insereSin(dicionario, "agarra", "pega");
	flag += insereSin(dicionario, "pega", "pega");
	flag += insereSin(dicionario, "anda", "anda");
	flag += insereSin(dicionario, "vai", "anda");
	flag += insereSin(dicionario, "move", "anda");
	flag += insereSin(dicionario, "soltar", "soltar");
	flag += insereSin(dicionario, "deixar", "soltar");
	flag += insereSin(dicionario, "escrever", "escrever");
	flag += insereSin(dicionario, "quebrar", "quebrar");
	flag += insereSin(dicionario, "destroi", "quebrar");
	flag += insereSin(dicionario, "abrir", "abrir");
	flag += insereSin(dicionario, "ler", "abrir");
	// More synonyms must be defined...


	// DEFINING GLOBAL FUNCTIONS
	funGlobais = criaL();
	EloL *f = malloc(sizeof(EloL));
	f->tag = "anda";
	f->inst.fun = anda;
	f->prox = NULL;
	flag += insereElol(funGlobais, f);
}

int main(){
	inicializa();

	visitaSala(pessoa);
	
}
