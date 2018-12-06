%{
#include <stdio.h>
#include "game.h"

int yylex();
int yyerror(char *);

%}

// Declarations
%union {
  struct {
      char *ver;
      char *obj;
  } guardado;
}

%token <guardado> ACAO

%token INFO  EOL FIM  LISTAR

%defines

%%

input: 
	  EOL		{ printf("Zzzz...\n"); }

  | ACAO {

    executaComando($1.ver, $1.obj);

  }

  | LISTAR {
    listar();
  }

  | INFO {
  	printf("Lista de ações possiveis:  \nPEGAR <OBJETO> \nABRIR <OBJETO> \nESCREVER \nSOLTAR <OBJETO> \
  	\nQUEBRAR <OBJETO> \nANDAR <DIRECAO> \nLISTAR \nHELP \nSAIR \nVariações podem ser aceitas ;D\n");
 	} eol // 'eol' represents the end of command

	| FIM  { return 0;}

	| error eol;
;



eol: EOL {return 1;}
%%

int yyerror(char *s) {
  //puts("Não entendi...");
  return 0;
}
