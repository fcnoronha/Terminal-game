#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"acoes.h"
#include"hashTable.h"
#include"ListaValores.h"
#include"game.h"

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

		p->visitadas++;
		imprimeObjetos(p->salaAtual);
	}
	else {
		printf("%s\n", p->salaAtual->curta);
	}

	mudaAtivo();
}

int andar(Personagem *p, Elemento *sala)
{
	mudaAtivo();

	if (sala == NULL) return 0;

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

int pegar(Personagem *p, Elemento *e)
{
	printf("Você guardou %s na mochila\n", e->nome);
	EloL *s = buscaEle(p->salaAtual->conteudo, e);
	int flag = insereElol(p->mochila, s);
	flag = retiraElol(p->salaAtual->conteudo, s->tag);
	s->prox = NULL;

	return flag; 
}

int abrir(Personagem *nada, Elemento *l)
{
	if (l->desc == NULL)
		printf("Você abre o livro e percebe que não há nada escrito em nenhuma das páginas.\n");
	else
		printf("%s\n", l->desc);
	return 1;
}

int escrever(Personagem *nada, Elemento *l)
{
	printf("Você encontra um lápis ao lado do livro e escreve algo na primeira página.\n");
	l->desc = malloc(100*sizeof(char));
	// scanf("%s", l->desc);
	fgets(l->desc, 100, stdin);
	return 1;
}

int soltar(Personagem *nada, Elemento *o)
{
	printf("Você solta o objeto mas ele reaparece em suas mãos.\n");
	printf("%s\n", o->curta);
	return 1;
}

int quebrar(Personagem *nada, Elemento *o)
{
	printf("Você tenta quebrá-lo, mas só se machuca mais, suas mãos agora estão sangrando.\n");
	return 1;
}

