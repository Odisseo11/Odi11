/*
	*File: tablaTipov1.h
	*Autores: Alvarez González Ian Arturo y López López Ulysses
	*Creado: 22/05/2020
	*Editado y terminado: 30/05/2020
	*Ultima revisión: 31/05/2020

*/
#ifndef TABLATIPO_H_INCLUDED
#include <stdbool.h>
#include "tablaSimbolos.h"
typedef struct _type type;
typedef struct _tipoBase tipoBase;
typedef union _tipo tipo;

union _tipo{
int type;
tabla_simbol *estructura;
};

struct _tipoBase{
bool est;
tipo t;
};

struct _type{
int id;
char name [10];
tipoBase tb;
int tamBytes;
int numElem;
type *next;
};

typedef struct _typetab typetab;
struct _typetab{
type *root;
int num;
typetab *next;
};

void setSymTab(typetab tt, tabla_simbol* st);

/* Inserta al final de la lista e incrementa num */
int insertarTipo(typetab *tt, type *t);

/* Regresa el numero de elementos de tipo */
int getNumElem(typetab* tt, int id);

/* Regresa el tipo base de  tipo */
tipoBase* getTipoBase(typetab *tt, int id);

/*Crea tabla de tipos*/
typetab* crearTypeTab();

/* Regresa el name de un tipo
 * En caso de no encontrarlo Regresa NULL
 */
char* getNombre(typetab* tt, int id);
void printTablaTipos(typetab *tt);

/* Regresa un apuntador a type */
tipo *creaPrimitivo(int id);

/* Regresa un apuntador a tipoBase */
tipoBase *creaArque(bool is_struct, tipo* base_type);

/* Crear un tipo nativo */
type *crearTipoNativo(int id, char* name, tipoBase* tb, int size);

type *creaTipo(char* name, int dim, int tipo, int numElem, bool est,tabla_simbol *estructura);

/* Regresa el numero de bytes de tipo */
int getTam(typetab* tt, int id);
#define TABLATIPO_H_INCLUDED
#endif
