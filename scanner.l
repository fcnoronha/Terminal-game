%{

#include "parser.tab.h"

/* readline */
#include <readline/readline.h>
#include <readline/history.h>

#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);

int estado = 0;

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

(fim|chega|sair|tchau) { return FIM;}

(help|ajuda|info) {return INFO;} 

(testa|teste|test) {return TEST;}

para // Ignora as conjunções

[ao]|uma?

d[aoe]|em|n[ao]

(pau) {
  yylval.numero = 2;
  return ACAO
;} 

(buc) {
  yylval.str = "oi";
  return OBJE
;}

[ \t]+

[[:alpha:]]+ { 
  if(estado == 0){
    printf("verbo: %s\n", yytext);
    estado++;
    yylval.str = yytext;
  }
  else {
    printf("obj: %s\n", yytext);
    estado = 0;
    yylval.str = yytext;
    return SEGUNDO;
  }

  return PRIMEIRO
;}

[\n;] {/* ';' também termina linhas */return EOL;}


