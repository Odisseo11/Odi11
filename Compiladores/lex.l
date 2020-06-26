%{

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "parser.tab.h"

%}

%option noyywrap
%option yylineno

registro [Rr][Ee][Gg][Ii][Ss][Tt][Rr][Oo]
inicio [Ii][Nn][Ii][Cc][Ii][Oo]
fin [Ff][Ii][Nn]
ent [Ee][Nn][Tt]
real [Rr][Ee][Aa][Ll]
dreal [Dd][Rr][Ee][Aa][Ll]
car [Cc][Aa][Rr]
sin [Ss][Ii][Nn]
def [Dd][Ee][Ff]
si [Ss][Ii]
entonces [Ee][Nn][Tt][Oo][Nn][Cc][Ee][Ss]
sino [Ss][Ii][Nn][Oo]
mientras [Mm][Ii][Ee][Nn][Tt][Rr][Aa][Ss]
hacer [Hh][Aa][Cc][Ee][Rr]
escribir [Ee][Ss][Cc][Rr][Ii][Bb][Ii][Rr]
leer [Ll][Ee][Ee][Rr]
devolver [Dd][Ee][Vv][Oo][Ll][Vv][Ee][Rr]
terminar [Tt][Ee][Rr][Mm][Ii][Nn][Aa][Rr]
verdadero [Vv][Ee][Rr][Dd][Aa][Dd][Ee][Rr][Oo]
falso [Ff][Aa][Ll][Ss][Oo]

digito [0-9]+
ent_def [+-]?{digito}
exp [Ee][+-]?{digito}+
real_def ({digito}.?{digito}{exp}|{digito}?.{digito}{exp}?|{digito}.{digito}?{exp}?)[Ff]
dreal_def ({digito}.?{digito}{exp}|{digito}?.{digito}{exp}?|{digito}.{digito}?{exp}?)[dD]
letra [a-zA-Z]
id (_|{letra})((_|{letra}|{digito})){0,31}

car_def '([^'])'
cadena \"([^"]*)\"


%x com1
%x com2


%%


{ent}    { return ENT;}

{dreal} { return DREAL;}

{real} { return REAL;}

{car} { return CAR;}

{sin}   { return SIN;}

{registro} { return REGISTRO;}

{inicio} { return INICIO;}

{def}  { return DEF;}

{sino}    { return SINO;}

{si}    { return SI;}

{devolver} { return DEVOLVER;}

{fin}    { return FIN;}

{entonces}    { return ENTONCES;}

{verdadero} { return VERDADERO;}

{falso} { return FALSO;}

{mientras}  { return MIENTRAS;}

{hacer}  { return HACER;}

{leer}    { return LEER;}

{escribir}    { return ESCRIBIR;}

{ent_def}   {yylval.num.tipo = 1;yylval.num.ival = atoi(yytext);return NUM;}

{real_def}  {yylval.num.tipo = 2;yylval.num.fval = atof(yytext);return NUM;}

{dreal_def} {  yylval.num.tipo = 3; yylval.num.dval = atof(yytext);return NUM;}

"o"    { return O;}

"y"    { return Y;}

"no"    { return NO;}

"+"	{ return SUM; }

"-"	{ return RES; }

"*"	{ return MUL; }	

"/"	{ return DIV; }

"%"	{ return MOD; }

"(" { return LPAR; }

")" { return RPAR;}

":="   { return ASIG;}

"," { return COMA;}

"[" { return LCOR;}

"]" { return RCOR;}

";" { return PYC;}

"." { return PT;}

"<"	{   strcpy(yylval.car.sval,yytext); return SMT; }

">"	{   strcpy(yylval.car.sval,yytext); return GRT; }

">=" {  strcpy(yylval.car.sval,yytext); return GREQ; }

"<=" { strcpy(yylval.car.sval,yytext); return SMEQ; }

"<>" {   strcpy(yylval.car.sval,yytext); return DIF; }

"==" {   strcpy(yylval.car.sval,yytext); return EQEQ; }

{id} {  strcpy(yylval.dir ,yytext); return ID;}

{car_def}   { yylval.car.tipo = 0; strcpy(yylval.car.sval,yytext); return CARACTER;}

[ \n\t\r]+	{}



"/*"				{ BEGIN(com1); }

<com1>\n    		{   }

<com1>[^*\n]*		{}

<com1>"*"+[^*/\n]*	{}

<com1>"*"+"/"		{ BEGIN(INITIAL); }

"//"				{ BEGIN(com2); }

<com2>[^*\n]*		{}

<com2>\n  			{ BEGIN(INITIAL); }

.					{ printf("\n****Error lexico en la linea: %d\n", yylineno);}

%%


