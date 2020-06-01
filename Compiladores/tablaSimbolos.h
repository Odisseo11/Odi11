/*
	*File: tablaTipov1.h
	*Autores: Alvarez González Ian Arturo y López López Ulysses
	*Creado: 22/05/2020
	*Editado y terminado: 30/05/2020
	*Ultima revisión: 31/05/2020

*/
#ifndef TABLA_SIMBOLOS_H_INCLUDED
typedef struct _parametro par;
struct _parametro 
{
	int tipo;
	par* next;
};

typedef struct _listaParametros listaPar;
struct _listaParametros
{
	par* root;
	int num;
};

void deleteParametro(par *p);
void addParametro(listaPar lp, int tipo);
void deleteListaParam(listaPar *lp);
int getNumeroListaParam(listaPar *lp);

typedef struct _simbolo simbolo;
struct _simbolo 
{
	char id[32];
	int tipo;
	int dir;
	char tipoVar[32];
	listaPar *parametros;
	simbolo *next;
};

simbolo* createSimbolo();
void deleteSimbolo(simbolo *s);

typedef struct _tablasimbolos tabla_simbol;
struct _tabalsimbolos 
{
	simbolo *root;
	int num;
	tabla_simbol *next;
};

/* Regresa un apuntador a par */
par* createParam(int tipo);

/* Regresa un apuntador a listaPar */
listaPar* createLP();

/* Agrega al final de la lista el parametro e incrementa num */
void addtipo(listaPar* lp, int tipo);

/* Borra la lista */
void deleteListaParametros(listaPar* lp);

/* Cuenta el numero de parametros*/
int getNumListaParametros(listaPar* lp);

/* Regresa un apuntador a simbolo */
simbolo* createSimbolo(char* id, int tipo, int dir, char* tipoVar);

/* Regresa un apuntador a symtab*/
tabla_simbol* createTablaSimbolo();

/*Agrega una lista de parametros*/
void addListaPar(tabla_simbol* st, listaPar* lp, char* id);

/* Borra la lista */
void deleteTablaSimbolos(tabla_simbol*);

/* Inserta al final de la lista, si inserta incrementa num y regresa su pisicion, si no, Regresa -1*/
int insertar(tabla_simbol* st, simbolo* simb);

/* Busca un id en la tabla de simbolos, si lo encuentra regresa la posicion*/
int buscar(tabla_simbol* st, char* id);

/* Regresa el tipo de dato de un id */
int getTipo(tabla_simbol* st, char* id);

/* Regresa el tipo de Variable de un id*/
char* getTipoVar(tabla_simbol* st, char* id);

/* Regresa la direccion de un id*/
int getDir(tabla_simbol* st, char* id);

/* Regresa la lista de parametros de un id */
listaPar* getlistaPar(tabla_simbol* st, char* id);

/* Imprimela tabla de simbolos y sus parametros*/
void printTablaSimbolos(tabla_simbol* st);

#define TABLA_SIMBOLOS_H_INCLUDED
#endif // !1

