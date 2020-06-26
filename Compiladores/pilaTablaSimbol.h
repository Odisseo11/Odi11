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
#ifndef PILATABLASIMBOL_H_INCLUDED
#include "tablaSimbol.h"

typedef struct _pilaSimbolos pilaSimbolos;

struct _pilaSimbolos
{
  tablaSimbolo *root;
  int num;
};

pilaSimbolos* crearPilaSimbolos();
void borrarPilaSimbolos(pilaSimbolos* ps);
void insertarTablaSimbolo(pilaSimbolos* ps, tablaSimbolo* tablaSimbolo);
tablaSimbolo* getSimboloCima(pilaSimbolos* ps);
tablaSimbolo* getSimboloFondo(pilaSimbolos* ps);
tablaSimbolo* sacarTablaSimbolo(pilaSimbolos* pts);
void printPilaSimbolos(pilaSimbolos* ps);
#define PILATABLASIMBOL_H_INCLUDED
#endif

#ifndef PILATABLASIMBOL_H_INCLUDED
#include "tablaSimbol.h"

typedef struct _pilaSimbolos pilaSimbolos;

struct _pilaSimbolos
{
  tablaSimbolo *root;
  int num;
};

pilaSimbolos* crearPilaSimbolos();
void borrarPilaSimbolos(pilaSimbolos* ps);
void insertarTablaSimbolo(pilaSimbolos* ps, tablaSimbolo* tablaSimbolo);
tablaSimbolo* getSimboloCima(pilaSimbolos* ps);
tablaSimbolo* getSimboloFondo(pilaSimbolos* ps);
tablaSimbolo* sacarTablaSimbolo(pilaSimbolos* pts);
void printPilaSimbolos(pilaSimbolos* ps);
#define PILATABLASIMBOL_H_INCLUDED
#endif
