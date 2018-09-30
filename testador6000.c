#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ListaValores.h"


/*
	FUNÇÕES PARA TESTAR A LISTA DE VALORES
*/


// void testaInsereL(Lista *L, Elemento el){
// 	if (insereL(L, &el) == &el)
// 		printf("Inseriu com sucesso!\n");
// 	else printf("Inseriu tudo errado!\n");
// }

void testaBuscaL(Lista *L, Elemento el){  //tá errada acho viu
	Elemento *busca;
	busca = buscaL(L, el.desc);
	if (busca == NULL) printf("Elemento não encontrado.\n");
	else if (busca == &el) printf("Achou!\n");
}

void testaRetiraL(Lista *L, Elemento el){
	printf("Busca antes de retirar: ");
	testaBuscaL(L, el);
	retiraL(L, &el);
	printf("Busca depois de retirar: ");
	testaBuscaL(L, el);
}

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

	printf("Colocando elementos:\n");

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


	// Testando a busca

	printf("Buscando elementos:\n");
	printf("'Voa e pega fogo.': ");
	testaBuscaL(aeronavegadores, dirigivel);
	printf("'Carrega um po branco.': ");
	testaBuscaL(aeronavegadores, helicoptero);
	printf("'Homenagem a um certo gato.': ");
	testaBuscaL(aeronavegadores, jato);
	printf("'Serve para planar.': ");
	testaBuscaL(aeronavegadores, planador);


	// Retirando elementos

	printf("Retirando elementos:\n");
	printf("Dirigivel: \n");
	testaRetiraL(aeronavegadores, dirigivel);
	printf("Helicoptero: \n");
	testaRetiraL(aeronavegadores, helicoptero);
	printf("Jato: \n");
	testaRetiraL(aeronavegadores, jato);
	printf("Planador: \n");
	testaRetiraL(aeronavegadores, planador);




}


int main(){
	// Modulo para testas coisas feitas, onde cada modulo vai ser testado por uma void,
	// a qual sera chamada na main.

	//testaHashTable();
	testaLista();
}
