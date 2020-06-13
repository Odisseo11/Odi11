#ifndef TABLASIMBOL_H_INCLUDED
typedef struct _parametro parametro;
struct _parametro 
{
  int tipo;
  parametro *next;
};
typedef struct _listaParametro listaParametro;
struct _listaParametro 
{
  parametro *root;
  int num;
};

void borraParametro(parametro* p);
void agregar(listaParametro lp, int tipo);
void borrarListaParametro(listaParametro* lp);
int getNumListaParametro(listaParametro* lp);

typedef struct _simbolo simbolo;
struct _simbolo 
{
  char id[32];
  int tipo;
  int dir;
  char tipoVar[32];
  listaParametro *params;
  simbolo *next;
};

simbolo* crearSimbolo();
void borrarSimbolo(simbolo* s);

typedef struct _tablaSimbolo tablaSimbolo;
struct _tablaSimbolo 
{
  simbolo *root;
  int num;
  tablaSimbolo *next;
};

/* Retorna un apuntador a una variable Param */
parametro* crearParametro(int tipo);

/* Retorna un apuntador a una variable listParam */
listaParametro* crearLP();

/* Agrega al final de la lista el parametro e incrementa num */
void agregarTipo(listaParametro* lp, int tipo);

/* Borra toda la lista, libera la memoria */
void borrarListaParametro(listaParametro* lp);

/* Cuenta el numero de parametros en la linea */
int getNumListaParametro(listaParametro* lp);

/* Retorna un apuntador a una variable symbol */
simbolo* crearSimbolo(char* id, int tipo, int dir, char* tipoVar);

/* Retorna un apuntador a una variable symtab,
 * inicia contador en 0
 */
tablaSimbolo* crearTablaSimbolo();

void agregarListaParametros(tablaSimbolo* ts, listaParametro* lp, char* id);
/* Borra toda la lista, libera la memoria */
void borrarTablaSimbolo(tablaSimbolo*);

/* Inserta al final de la lista, en caso de insertar incrementa num
 * y retorna la posicion donde inserto. En caso contrario retorna -1
*/
int insertar(tablaSimbolo* ts, simbolo* sym);

/* Busca en la tabla de simbolos mediante el id
 * En caso de encontrar el id retorna la posicion
 * En caso contrario retorna -1
 */
int buscar(tablaSimbolo* ts, char* id);

/* Retorna el tipo de dato de un id
 * En caso no encontrarlo retorna -1
 */
int getTipo(tablaSimbolo* ts, char* id);

/* Retorna el tipo de Variable de un id
 * En caso de no encontrarlo retorna -1
 */
char* getTipoVar(tablaSimbolo* ts, char* id);

/* Retorna la direccion de un id
 * En caso de no encontrarlo retorna -1
*/
int getDir(tablaSimbolo* ts, char* id);

/* Retorna la lista de parametros de un id
 * En caso de no encontrarlo retorna NULL
 */
listaParametro* getListaParametro(tablaSimbolo* ts, char* id);

/* Retorna el numero de parametros de un id
 * En caso de no encontrarlo retorna -1
 */
int getNumParametro(tablaSimbolo* ts, char* id);

void getParametros(char* parametros, parametro* p);
/* Imprime toda la tabla de simbolos,
 * si contiene parametros los imprime tambien
*/
void printTablaSimbolos(tablaSimbolo* ts);
#define TABLASIMBOL_H_INCLUDED
#endif
