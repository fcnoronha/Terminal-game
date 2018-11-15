#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*FPTR)(int, int);

// Defining union to be used in the linked list
typedef union e{
	int *obj;
	FPTR fun; // Make instc.fun = dumbFunction;
} Elecao;

int oi(int i, int j){

	return i+j;
}

int main(){
	Elecao k;
	k.fun = oi;
	printf("%d\n", k.fun(1,2));
}

