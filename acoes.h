# ifndef _acoes_h 
# define _acoes_h 

#include "Estruturas.h"

/*
 This module contais all the actions/functions that can be perfomed
 in the game. By definition they're all in the form:
   int foo(personagem*, elemento*)
 and returns 1 if sucess and 0 otherwise.
*/

/*
 Print all the objects in a given room
*/
void imprimeObjetos(Elemento *);	

/*
 Given the character, visits the room in wich it is. Print the long
 description if it's there for the first time and the short one otherwise.
*/
void visitaSala(Personagem*);

/*
 Move character to given room, considering if its possible
*/
int anda(Personagem *p, Elemento *sala);

/*
 Receives an object 'e' and put it in the mochila array, representing
 the bag of the character and removes it from the room.
*/
int pega(Personagem *p, Elemento *e);

/*
 Reads 'desc' of an object
*/ 
int abrir(Personagem *nada, Elemento *l);

/*
 Store string s in the 'desc' of the element
*/
int escrever(Personagem *nada, Elemento *l);

/*
 Try to loose from element 'o'
*/
int soltar(Personagem *nada, Elemento *o);

/*
 Try to breack element 'o'
*/
int quebrar(Personagem *nada, Elemento *o);

# endif