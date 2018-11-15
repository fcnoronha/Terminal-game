#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"acoes.h"
#include"hashTable.h"
#include"ListaValores.h"

/*
 This module contais all the actions/functions that can be perfomed
 in the game. By definition they're all in the form:
   int foo(personagem*, elemento*)
 and returns 1 if sucess and 0 otherwise.
*/

void imprimeObjetos(Elemento *sala)
{
	if (sala->conteudo == NULL) return;

	int t = sala->conteudo->tamanho;

	if (t == 0) return;

	if (t > 0) printf("Aqui, temos os seguintes objetos: \n");
	for (EloL *i = sala->conteudo->Lista; i != NULL; i = i->prox)
	{
		printf("%s\n", i->inst.obj->nome);
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

int pega(Personagem *p, Elemento *e)
{
	EloL *s = buscaEle(p->salaAtual->conteudo, e);
	int flag = insereElol(p->mochila, s);
	flag = retiraElol(p->salaAtual->conteudo, s->tag);
	s->prox = NULL;

	return flag; 
}

int abrir(Personagem *nada, Elemento *l)
{
	if (strcmp(l->desc,"\0") == 0)
		printf("Olha só, não tem nada aqui.\n");
	else
		printf("%s\n", l->desc);
	return 1;
}

int escrever(Personagem *nada, Elemento *l)
{
	printf("O que você quer escrever aqui?\n");
	char x[90];
	scanf("%s", x);
	l->desc = x;
	return 1;
}

int soltar(Personagem *nada, Elemento *o)
{
	printf("Aii, sai da minha mão... \nAhhhh apareceu de novo na minha mão!\n");
	printf("%s\n", o->curta);
	return 1;
}

int quebrar(Personagem *nada, Elemento *o)
{
	printf("Você é muito burro... Tentando quebrar espinhos você só se machuca mais.\n");
	return 1;
}

