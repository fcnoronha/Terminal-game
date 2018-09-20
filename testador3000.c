#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//#include"hashTable.h"
#include"hashTable.c"

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

	printf("codigo hash : %d\n", hashFun("menino bonito", t));
	if(insereS(*tabtop, "menino bonito", &felipe))
		printf("inserido com sucesso\n");

	printf("codigo hash : %d\n", hashFun("visera", t));
	if(insereS(*tabtop, "visera", &oculos))
		printf("inserido com sucesso\n");

	printf("codigo hash : %d\n", hashFun("maça da terra", t));
	if(insereS(*tabtop, "maça da terra", &batata))
		printf("inserido com sucesso\n");

	printf("codigo hash : %d\n", hashFun("zoinho", t));
	if(insereS(*tabtop, "zoinho", &felipe))
		printf("inserido com sucesso\n");

	printf("codigo hash : %d\n", hashFun("fepipe", t));
	if(insereS(*tabtop, "fepipe", &felipe))
		printf("inserido com sucesso\n");


	// Consultando paradas na tabela

	Elemento *busca;

	busca = buscaS(*tabtop, "felipe");
	if (busca == NULL) printf("oi\n");
	//printf("%s\n", busca->desc);
	
	


}

int main(){
	// MODULO PARA TESTAR TUDO OQ A GNT FAZ

	testaHashTable();
}
