%{
#include <stdio.h>

int yylex();
int yyerror(char *);

%}

// Declaracoes
%union {
  char *str;
  int  direc;
}

%token <tptr> VERBO OBJ LUGAR

/* DESC representa uma palavra desconhecida */
%token <str> DESC
%token NORTE SUL LESTE OESTE CIMA BAIXO VAPARA EOL FIM INVENT
%token INFO TEST

%type <direc> dir
%type <tptr> obj

%defines

%%

input: EOL		{ printf("Zzzz...\n"); }
    | cmd

    | INFO {
    	printf("Lista de ações possiveis: \n");
    	// Escrever coisas aqui
   	} eol // 'eol' represents the end of command
    	

    | TEST {
    	// make this make the game tests itself
    }

	| VAPARA  {
	  		   /* movimentação */
	  		   printf("Seguindo para ");
	  		  } eol
	| dir {
			 puts("Não há passagem....");
											} eol

	| FIM  { return 0;}
	| DESC { puts("Não tem registro, Will Robinson.");}

	| error eol;
;

cmd: VERBO {
			 /* Intransitivo */
			 printf("oi?\n");
  	 	     //F(AcertaF($1,NULL))(NULL,NULL);
		   } eol
   | VERBO obj {
			   /* Transitivo direto */
			   printf("oi?\n");
			   //F(AcertaF($1,$2))($2->value,NULL);
			 } eol 
   | VERBO obj obj {
                 /* Bitransitivo */
                 printf("oi?\n");
			     ////F(AcertaF($1,$2))($2->value,$3->value);
			   } eol
   | VERBO DESC {
   				printf("oi?\n");
			    //printf("%s??\n", $2);
			 } eol 
   | VERBO obj DESC {
  				 printf("oi?\n");
			   //printf("não sei o que é isso: %s\n",  $3);
			   } eol 
   | VERBO DESC DESC {
   				printf("oi?\n");
			   } eol 
;

obj: OBJ    { }
   | LUGAR  { }

dir: NORTE	  { puts("norte"); }
	 | SUL	  { puts("sul");   }
	 | LESTE  { puts("leste"); }
	 | OESTE  { puts("oeste"); }
	 | CIMA	  { puts("cima");  }
	 | BAIXO  { puts("baixo"); }
	 | DESC   { puts("... (onde é isso?)"); }
;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
  puts("Não entendi...");
  return 0;
}
