#ifndef PILATABLASIMBOL_H_INCLUDED
#include "tablaSimbolos.h"

typedef struct sym_stack symStack;

struct sym_stack{
  tabla_simbol *root;
  int num;
};

symStack *crearSymStack();
void borrarSymStack(symStack *pts);
void insertarSymTab(symStack *pts, tabla_simbol *sym_tab);
tabla_simbol* getSymCima(symStack *pts);
tabla_simbol* getSymFondo(symStack *pts);
tabla_simbol* sacarSymTab(symStack *pts);
void printSymPila(symStack *pts);
#define PILATABLASIMBOL_H_INCLUDED
#endif
