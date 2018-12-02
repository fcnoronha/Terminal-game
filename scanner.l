%{

#include "parser.tab.h"

/* readline */
#include <readline/readline.h>
#include <readline/history.h>

#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);

/* Function to substitute input */
static int mygetinput(char *buf, int size) {
  char *line;
  /* end of file */
  if (feof(yyin))  return YY_NULL;

  /* reads a line "> " */
  line = readline("> ");
  if(!line)        return YY_NULL;

  /* safety */
  if(strlen(line) > size-2){
     fprintf(stderr,"input line too long\n");
	 return YY_NULL;
  }

  sprintf(buf,"%s\n",line);
  /* adiciona ao histórico */
  add_history(line);

  /* freeing memory */
  free(line);
  return strlen(buf);
}   
%}

%option caseless

%%

(fim|Chega) { return FIM;}

<<EOF>> { puts("Bye bye..."); return FIM; }

(help|ajuda|info) {return INFO;} 

(testa|teste|test) {return TEST;}

(N|Norte|NORTE) { return NORTE;}
(S|Sul|SUL)     { return SUL;}
(L|Leste|LESTE) { return LESTE;}
(W|Oeste|OESTE) { return OESTE; /* W no lugar de O para evitar confusão com o artigo 'o'*/  } 
(C|Cima|CIMA)   { return CIMA;}
(B|Baixo|BAIXO) { return BAIXO;}


[ao]|uma?

d[aoe]|em|n[ao]

[[:alpha:]]+ {

			  }


[ \t]+
[\n;] {/* ';' também termina linhas */return EOL;}


. {yylval.str = yytext; return DESC;}
