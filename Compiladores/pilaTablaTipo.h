#ifndef PILATABLATIPO_H_INCLUDED
#include "tablaTipov2.h"
typedef struct type_stack typeStack;

struct type_stack
{
   tabla_simbol *root;
   int num;
};

typeStack *crearTypeStack();
void borrarTypeStack(typeStack *ptt);
void insertarTabType(typeStack *ptt, tabla_simbol *type_tab);
tabla_simbol* getTypeCima(typeStack *ptt);
tabla_simbol* getTypeFondo(typeStack *ptt);
tabla_simbol* sacarTypeTab(typeStack *ptt);
void printTypePila(typeStack *ptt);
#define PILATABLATIPO_H_INCLUDED
#endif

