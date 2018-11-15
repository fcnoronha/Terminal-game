#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashTable.h"
#include"ListaValores.h"

// Defining global variables in order to make them acessible to every function

// Rooms
Elemento *identidade;
Elemento *prazer;
Elemento *racional;
Elemento *memoria;
Elemento *medo;
Elemento *ego;

// Character
Personagem *pessoa;

/*

		 EGO --  PRAZER	
					|
	MEMORIA	--	IDENTIDADE  --    RACIONAL
				    |
		|_______		   MEDO        ______|

*/


void inicializa(){
	// 'identidade' room
	identidade = malloc(sizeof(Elemento));
	identidade->nome = "Identidade";
	identidade->curta = "...";
	identidade->longa = "...";
	identidade->ativo = true;
	identidade->visitado = true;
	identidade->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
	prazer->curta = "...";
	prazer->longa = "...";
	prazer->ativo = true;
	prazer->visitado = true;
	prazer->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
	racional->curta = "...";
	racional->longa = "...";
	racional->ativo = true;
	racional->visitado = true;
	racional->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
	memoria->curta = "...";
	memoria->longa = "...";
	memoria->ativo = true;
	memoria->visitado = true;
	memoria->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
	ego->visitado = true;
	ego->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
	medo->curta = "...";
	medo->longa = "...";
	medo->ativo = false;
	medo->visitado = true;
	medo->conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
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
}

int main(){
	inicializa();

	VisitaSala(pessoa);
	

}
