%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap
%option yylineno

pal_rese @(if|else|while)
letra [a-zA-z]
letra_ {letra}|_
digito [0-9]
id #({letra_}|{digito})*
coment "/*"([^*/])*"*/"
arit "+"|"-"|"*"|"/"|"%"
relac ">"|"<"|">="|"<="|"=="
asig "="
logicos "&&"|"||"|"!"
operador {arit}|{relac}|{asig}|{logicos}
sim_puntuacion [.:,;]
espacios [ \t\n\r]+

%%
{pal_rese} {printf("Se encontro una palabra reservada:   %s\n",yytext);}
{id} {printf("Se encontro una id:   %s\n",yytext);}
{operador} {printf("Se encontro un operador:   %s\n",yytext);}
{sim_puntuacion} {printf("Se encontro un simbolo de puntuacion:   %s\n",yytext);}
{espacios}  {/* Ignorar los espacios */}
{coment} {/* Ignorar los comentarios */}
%%

int main(int argc, char ** argv)
{
	FILE *f;
	if (argv < 2)
	{
		printf("Falta archivo");
		exit(-1);
	}
	f = fopen(argv[1],"r");
	if (!f)
	{
		printf("No se pudo abrir el archivo");
		exit(-1);
	}
	yyin = f;
	yylex();
	return 0;
}
