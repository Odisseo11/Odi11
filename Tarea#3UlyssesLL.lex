%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap
%option yylineno

d1 [0-9]
d3 [0-2]
dirip ((d3)?(d1)?(d1))
Diriptip ((d3)?(d1)?(d1).(d3)?(d1)?(d1).(d3)?(d1)?(d1).(d3)?(d1)?(d1))

%%
{Diriptip} {printf("Se encontro una direccion IP: %s\n",yytext);}
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
