#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ListaValores.h"



void testaLista(){

	Elemento dirigivel;
	strcpy(dirigivel.desc, "Voa e pega fogo.");

	Elemento helicoptero;
	strcpy(helicoptero.desc, "Carrega um po branco.");

	Elemento jato;
	strcpy(jato.desc, "Homenagem a um certo gato.");

	Elemento planador;
	strcpy(planador.desc, "Serve para planar.");

	//int l = 100; // Tamanho da lista de valores

	Lista *aeronavegadores;
	aeronavegadores = criaL();


	// Testando a inserção

	printf("\nColocando elementos:\n");

	printf("Dirigivel: ");
    if (insereL(aeronavegadores, &dirigivel) == &dirigivel)
        printf("inseriu com sucesso!\n");
    else printf("inseriu tudo errado!\n");

	printf("Helicoptero: ");
    if (insereL(aeronavegadores, &helicoptero) == &helicoptero)
        printf("inseriu com sucesso!\n");
    else printf("inseriu tudo errado!\n");

	printf("Jato: ");
    if (insereL(aeronavegadores, &jato) == &jato)
        printf("inseriu com sucesso!\n");
    else printf("inseriu tudo errado!\n");

    printf("----\n");
    
	// Testando a busca

    Elemento *busca;
	printf("Buscando elementos:\n");

	printf("'Voa e pega fogo.': ");
	busca = buscaL(aeronavegadores, dirigivel.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &dirigivel) printf("Achou!\n");

	printf("'Carrega um po branco.': ");
	busca = buscaL(aeronavegadores, helicoptero.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &helicoptero) printf("Achou!\n");

	printf("'Homenagem a um certo gato.': ");
	busca = buscaL(aeronavegadores, jato.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &jato) printf("Achou!\n");

	printf("'Serve para planar.': ");
	busca = buscaL(aeronavegadores, planador.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &planador) printf("Achou!\n");

    printf("----\n");

	// Retirando elementos

	printf("Retirando elementos:\n");

	printf("Dirigivel: \n");
    printf("Busca antes de retirar: ");
    busca = buscaL(aeronavegadores, dirigivel.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &dirigivel) printf("Achou!\n");
	retiraL(aeronavegadores, &dirigivel);
	printf("Busca depois de retirar: ");
    busca = buscaL(aeronavegadores, dirigivel.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &dirigivel) printf("Achou!\n");

	printf("Helicoptero: \n");
    printf("Busca antes de retirar: ");
    busca = buscaL(aeronavegadores, helicoptero.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &helicoptero) printf("Achou!\n");
	retiraL(aeronavegadores, &helicoptero);
	printf("Busca depois de retirar: ");
    busca = buscaL(aeronavegadores, helicoptero.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &helicoptero) printf("Achou!\n");

	printf("Jato: \n");
    printf("Busca antes de retirar: ");
    busca = buscaL(aeronavegadores, jato.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &jato) printf("Achou!\n");
	retiraL(aeronavegadores, &jato);
	printf("Busca depois de retirar: ");
    busca = buscaL(aeronavegadores, jato.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &jato) printf("Achou!\n");

	printf("Planador: \n");
    printf("Busca antes de retirar: ");
    busca = buscaL(aeronavegadores, planador.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &planador) printf("Achou!\n");
	retiraL(aeronavegadores, &planador);
	printf("Busca depois de retirar: ");
    busca = buscaL(aeronavegadores, planador.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &planador) printf("Achou!\n");




}


int main(){
	// Modulo para testas coisas feitas, onde cada modulo vai ser testado por uma void,
	// a qual sera chamada na main.

	//testaHashTable();
	testaLista();
}
