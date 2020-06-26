/*
	Equipo de trabajo:
	-Álvarez González Ian 
	-García Oviedo Jaasiel Osmar
	-López López Ulysses
	-Domínguez Cisneros Alexis Saúl

	Materia: Compiladores
	Grupo: 01
	Semestre: 2020-1
	Fecha última versión: 13 de junio de 2020
*/
#include<stdio.h>
extern int yyparse();
extern FILE *yyin;

int main(int argc, char** argv)
{
	FILE *f;
	if(argc<2)
	{
		printf("Faltan argumentos\n");
		return -1;
	}
	f= fopen(argv[1],"r");
	if(!f)
	{
		printf("El archivo %s no se puede abrir\n", argv[1]);
		return -1;
	}
	yyin= f;
	yyparse();
	fclose(yyin);
	return 0;
}
