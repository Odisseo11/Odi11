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
