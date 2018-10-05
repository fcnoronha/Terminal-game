#pragma once
#include "Estruturas.h"

TabSim *criaS(int);

void destroiS(TabSim*);

int insereS(TabSim*, char*, Elemento*);

Elemento *buscaS(TabSim*, char*);

int retiraS(TabSim*, char*);