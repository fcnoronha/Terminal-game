#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashTable.h"
#include"ListaValores.h"
//#include "Estruturas.h"

/*
Maneira de se copilar:

make all
*/

void testaHashTable(){

	printf("\n\nTESTANDO HASHTABLE\n\n");

	Elemento batata;
	batata.desc = "Alimento amarelo e totoso";

	Elemento oculos;
	oculos.desc = "Pra te ver melhor";

	Elemento felipe;
	felipe.desc = "Menino lindo que estuda no IME";

	int t = 100; // Tamanho da minha tabela

	// Criando uma tabela hash
	TabSim *tabtop;
	tabtop = criaS(t);

	// Inserindo paradas na tabela

	printf("codigo hash 'menino bonito': %d\n", hashFun("menino bonito", t));
	if(insereS(tabtop, "menino bonito", &felipe))
		printf("inserido com sucesso\n");

	printf("codigo hash 'visera' : %d\n", hashFun("visera", t));
	if(insereS(tabtop, "visera", &oculos))
		printf("inserido com sucesso\n");

	printf("codigo hash 'maça da terra' : %d\n", hashFun("maça da terra", t));
	if(insereS(tabtop, "maça da terra", &batata))
		printf("inserido com sucesso\n");

	printf("codigo hash 'zoinho': %d\n", hashFun("zoinho", t));
	if(insereS(tabtop, "zoinho", &oculos))
		printf("inserido com sucesso\n");

	printf("codigo hash 'fepipe': %d\n", hashFun("fepipe", t)); // COlisao com visera
	if(insereS(tabtop, "fepipe", &felipe))
		printf("inserido com sucesso\n");

	printf("\n");

	// Consultando paradas na tabela
	Elemento *busca = malloc(sizeof(Elemento));

	printf("Busca para 'menino bonito:'\n");
	busca = buscaS(tabtop, "menino bonito");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Busca para 'visera:'\n");
	busca = buscaS(tabtop, "visera");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Busca para 'maça da terra:'\n");
	busca = buscaS(tabtop, "maça da terra");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Busca para 'zoinho:'\n");
	busca = buscaS(tabtop, "zoinho");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Busca para 'fepipe:'\n");
	busca = buscaS(tabtop, "fepipe");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Busca para 'bomba de carbo':'\n");
	busca = buscaS(tabtop, "bomba de carbo");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("\n");

	// Excluindo elementos
	printf("Excluindo 'visera': \n");
	if (retiraS(tabtop, "visera"))
		if (buscaS(tabtop, "visera") == NULL)
			printf("Apagou mesmo eim\n");

	printf("Checando se fepipe ainda esta: \n");
	printf("Busca para 'fepipe:'\n");
	busca = buscaS(tabtop, "fepipe");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);

	printf("Checando se visera ainda esta: \n");
	printf("Busca para 'visera:'\n");
	busca = buscaS(tabtop, "visera");
	if (busca == NULL) printf("Deu Errado\n");
	else printf("%s\n", busca->desc);


	printf("Apagando oq nao tem: \n");
	if (retiraS(tabtop, "bomba de carbo")){
		if (buscaS(tabtop, "bomba de carbo") == NULL)
			printf("Apagou mesmo eim\n");
	}
	else
		printf("Nao apagou nada\n");

	// Destruindo a tabela
	printf("\n");

	destroiS(tabtop);
	printf("Tabela apagada com sucesso!\n");

}


void testaLista(){

	printf("\n\n TESTANDO LISTA DE VALORES \n\n");

	Elemento dirigivel;
	dirigivel.desc = "Voa e pega fogo.";

	Elemento helicoptero;
	helicoptero.desc = "Carrega um po branco.";

	Elemento jato;
	jato.desc = "Homenagem a um certo gato.";

	Elemento planador;
	planador.desc = "Serve para planar.";

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
 
	printf("'Voa e pega fogo.': "); printf("\n");
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

	testaHashTable();
	testaLista();

	// Esta dando segfault, nao sei pq

}
