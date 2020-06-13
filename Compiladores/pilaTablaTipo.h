#ifndef PILATABLATIPO_H_INCLUDED
#include "tablaTipo.h"

typedef struct _pilaTipos pilaTipos;
struct _pilaTipos
{
   
   pilaTipos* root;
   int num;
};

pilaTipos* crearPilaTipos();
void borrarpilaTipos(pilaTipos* pt);
void insertarTablaTipo(pilaTipos* pt, tablaTipo* tabla_Tipo);
tablaTipo* getTipoCima(pilaTipos* pt);
tablaTipo* getTipoFondo(pilaTipos* pt);
tablaTipo* sacarTablaTipos(pilaTipos* pt);
void printPilaTipos(pilaTipos* pt);
#define PILATABLATIPO_H_INCLUDED
#endif
