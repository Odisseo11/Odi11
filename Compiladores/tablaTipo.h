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


#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"
#include "tablaTipo.h"
#include "pilaTablaTipo.h"

int main(int argc, char *argv[]){
    pilaTipos *ptt = crearPilaTipos();
    pilaSimbolos *pts = crearPilaSimbolos();
    insertarTablaTipo(ptt,crearTablaTipo()); //Insertar tabla de tipos y crearla
    insertarTablaTipo(ptt,crearTablaTipo());
    printf("%d\n",insertarTipo(getTipoCima(ptt),crearTipoNativo(1,"int",4,1)));
    printf("%d\n",insertarTipo(getTipoCima(ptt),crearTipoNativo(2,"int",4,2)));
    printf("%d\n",insertarTipo(getTipoCima(ptt),crearTipoNativo(3,"float",4,3)));
    printTablaTipo(getTipoCima(ptt));
    sacarTablaTipos(ptt);
    insertarTablaSimbolo(pts, crearTablaSimbolo());
    insertarTablaSimbolo(pts, crearTablaSimbolo());
    printf("%d\n",insertar(getSimboloCima(pts),crearSimbolo("1",1,0,"int")));
    printf("%d\n",insertar(getSimboloCima(pts),crearSimbolo("2",2,4,"floar")));
    printf("%d\n",insertar(getSimboloCima(pts),crearSimbolo("2",3,8,"array")));
    printTablaSimbolos(getSimboloCima(pts));
    sacarTablaTipos(pts);
    return 0;
}



#ifndef TABLATIPO_H_INCLUDED
#include <stdbool.h>
#include "tablaSimbol.h"


typedef union _tipo tipo;
union _tipo{
    int type;
    tablaSimbolo *estructura;
};

typedef struct _tipoBase tipoBase;
struct _tipoBase{
    bool est;
    tipo t;
};

typedef struct _tipo1 tipo1;
struct _tipo1{
    int id;
    char nombre [10];
    tipoBase tb;
    int tamBytes;
    int numElem;
    tipo *next;
};

typedef struct _tablaTipo tablaTipo;
struct _tablaTipo{
    tipo *root;
    int num;
    tablaTipo *next;
};

/* Retorna un apuntador a una variable type */
tipo* crearTipoPrimitivo(int id);
tipo* crearTipoStruct(tablaTipo* estructura); 
tipoBase* crearATipo(bool is_struct, tipo* tipo_Base);
tipo1* crearTipoArray(int id, char* nombre, tipoBase* tb, int size, int num_elem);
tipo1* crearTipoNativo(int id, char* nombre, tipoBase* tb, int size);
tipo1* crearTipo(char* nombre, int dim, int tipo, int numElem, bool est, tablaSimbolo* estructura);
/* Borra type, libera memoria */
void borrarTipo(tipo1* t);

/*Crea tabla de tipos*/
tablaTipo* crearTablaTipo();

void setTablaSimbolo(tablaTipo tt, tablaSimbolo* ts);

/* Borra la tabla de tipos, libera memoria */
void borrarTablaTipo(tablaTipo* tt);

int buscarTipo(tablaTipo* tt, char* nombre);

/* Inserta al final de la lista en caso de insertar incrementa num
 * Retorna la posicion donde inserto en caso contrario retorna -1
 */
int insertarTipo(tablaTipo* tt, tipo1* t);

/* Retorna el tipo base de un tipo
 * En caso de no encontrarlo retorna NULL
 */
tipoBase* getTipoBase(tablaTipo* tt, int id);

/* Retorna el numero de bytes de in tipo
 * En caso de no encontrarlo retorna -1
 */
int getTamanio(tablaTipo* tt, int id);

/* Retorna el numero de elementos de un tipo
 * En caso de no encontrarlo retorna -1
 */
int getNumElem(tablaTipo* tt, int id);

/* Retorna el nombre de un tipo
 * En caso de no encontrarlo retorna NULL
 */
char* getNombre(tablaTipo* tt, int id);
void printTablaTipo(tablaTipo* tt);
#define TABLATIPO_H_INCLUDED
#endif
