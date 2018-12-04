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

%token INFO TEST READ EOL FIM CARALHO LISTAR

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

	| cmd 

  | INFO {
  	printf("Lista de ações possiveis:  \nPEGAR <OBJETO> \nABRIR <OBJETO> \nESCREVER \nSOLTAR <OBJETO> \
  	\nQUEBRAR <OBJETO> \nANDAR <DIRECAO> \nLISTAR \nHELP \nSAIR \nVariações podem ser aceitas ;D\n");
  	// Escrever coisas aqui
 	} eol // 'eol' represents the end of command
  	

  | TEST {
  	testador6000();
  	// Error
  }

	| FIM  { return 0;}

	| error eol;
;

cmd: 
   //ACAO OBJE {
			   /* Transitivo direto */
			   //printf("%d %s\n", $1, $2);
			   /*
					$1 -> value of first token
					S2 -> value of second token
			   */
			   //F(AcertaF($1,$2))($2->value,NULL);
	//		 } eol 

;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
  //puts("Não entendi...");
  return 0;
}
