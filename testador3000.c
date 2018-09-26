#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hashTable.h"

/*
Maneira de se copilar:

gcc hashTable.c testador3000.c -o testador3000

ou seja, incluir os modulos e dps o testador
*/

void testaHashTable(){

	Elemento batata;
	strcpy(batata.desc, "Alimento amarelo e totoso");

	Elemento oculos;
	strcpy(oculos.desc, "Pra te ver melhor");
	
	Elemento felipe;
	strcpy(felipe.desc, "Menino lindo que estuda no IME");

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


}

int main(){
	// Modulo para testas coisas feitas, onde cada modulo vai ser testado por uma void,
	// a qual sera chamada na main.

	testaHashTable();
}
