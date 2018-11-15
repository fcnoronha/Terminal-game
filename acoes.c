#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"acoes.h"

/*
 This module contais all the actions/functions that can be perfomed
 in the game. By definition they're all in the form:

   int foo(personagem*, elemento*)

 and returns 1 if sucess and 0 otherwise.
*/

void imprimeObjetos(Elemento *sala)
{
	int t = sizeof(sala->conteudo) / sizeof(Elemento*);
	for (int i = 0; i < t; i++){
		printf("%s\n", sala->conteudo[i]->nome);
	}
}

void visitaSala(Personagem *p)
{
	if (p->salaAtual->visitado == false){
		p->salaAtual->visitado = true;
		printf("%s\n", p->salaAtual->longa);

		imprimeObjetos(p->salaAtual);
	}
	else {
		printf("%s\n", p->salaAtual->curta);
	}
}

int anda(Personagem *p, Elemento *sala)
{
	if (sala->isLugar && sala->ativo){
		p->salaAtual = sala;
		visitaSala(p);
		return 1; // Visited
	}
	else if (sala->isLugar && !(sala->ativo)){
		return 2; // Can't be visited
	}
	return 0; // Is not room
}