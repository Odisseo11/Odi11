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

#ifndef PILATABLATIPO_H_INCLUDED
#include "tablaTipo.h"

typedef struct _pilaTipos pilaTipos;
struct _pilaTipos
{
   
   tablaTipo *root;
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

