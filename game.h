# ifndef _game_h // Avoiding conflicts errors
# define _game_h 

#include "Estruturas.h"

/*
 Initialize the components of the game, passing informations,
 allocating necessary memory and defining all the relationships
 through rooms, objects and the character.
*/ 
void inicializa();

/*
 Can change the dynamicness of the rooms
*/
void mudaAtivo();

/*
 Free all the momory allocated for the game
*/
void destroier();

/*
 Test all functions of the game
*/
void testador6000();

/*
 Search all the functions of the objects in the room. If not found,
 seach room functions. If not found, search general functions. If 
 not found, return NULL. For exemple, in the sentence "Take car", 
 "take" is verbo and "car" is objeto.
*/
FPTR buscaFun(char *verbo, char *objeto);

/*
 Return enum dir type of a given term x
*/
dir charToDir(char *x);

/*
 Search all elements with the character and in the room. Can also
 return a location, if the input string is a direction. Return NULL
 if nothing is find.
*/
Elemento *buscaObj(char *objeto);

/*
 Ends the game
*/
void finalizaJogo();

/*
 Receive words and execute commans according to it
*/
void executaComando(char*, char*);

# endif
