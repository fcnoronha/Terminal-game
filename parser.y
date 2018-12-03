%{
#include <stdio.h>
#include "game.h"

int yylex();
int yyerror(char *);

%}

// Declarations
%union {
  char *str;
  int  numero;
}

%token <numero> ACAO
%token <str> OBJE

%token INFO TEST READ EOL FIM

%defines

%%

input: 
	  EOL		{ printf("Zzzz...\n"); }
	| cmd 
    | INFO {
    	printf("Lista de ações possiveis:  PEGAR <OBJETO>, ABRIR <OBJETO>, ESCREVER, SOLTAR <OBJETO>, QUEBRAR <OBJETO>, ANDAR <DIRECAO>\n");
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
   ACAO OBJE {
			   /* Transitivo direto */
			   printf("%d %s\n", $1, $2);
			   /*
					$1 -> value of first token
					S2 -> value of second token
			   */
			   //F(AcertaF($1,$2))($2->value,NULL);
			 } eol 

;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
  puts("Não entendi...");
  return 0;
}
