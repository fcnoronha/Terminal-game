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


void inicializa(){
	// Initialize the components of the game, passing informations and 
	// allocating necessary memory

	// identidade room
	identidade = malloc(sizeof(Elemento));
	identidade->nome = "Identidade";
	identidade->curta = "...";
	identidade->longa = "...";
	identidade->ativo = True;
	identidade->visivel = True;
	Elemento **conteudo = malloc(10 * sizeof(Elemento*)); // Making a list 
	// fun *açoes -> lista de ponteiros para funçoes
	// *animaçao -> ponteiro para funçao que ira fazer uma animaçao
	identidade->isLugar = True;
	identidade->isCoisa = False;
	// 4 directions and their respective rooms
	identidade->atrida.saidas = malloc(4 * sizeof(Elemento*));
	identidade->atrida.saidas[0] = prazer;
	identidade->atrida.saidas[1] = racional;
	identidade->atrida.saidas[2] = NULL;
	identidade->atrida.saidas[3] = NULL;
	// STOPPED HERE, TEST THIS
}

int main(){
	inicializa();
}
