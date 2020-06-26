/*
  *Autores: Alvarez González Ian Arturo y López López Ulysses
  *Creado: 22/05/2020
  *Editado y terminado: 23/05/2020
  *Ultima revisión: 24/05/2020
  *Este programa lleva a cabo la generación del analizador sintáctico
*/

#ifndef INTERMEDIATE_CODE_H
#define INTERMEDIATE_CODE_H

#include <string.h>

int temporalGlobal;

typedef struct quad QUAD;
/*Estructura de una cuadrupla (Operacion que se va a realizar, argumentos , Donde se va a almacenar el resultado.) */
struct quad {
  char *op;
  char *arg1;
  char *arg2;
  char *res;
  QUAD *next;
};

/* Estructura de la tabla de cuadruplas. */

typedef struct _code {
  QUAD *root;
  int instruc;
} code;
// items - cuadruplas almacenadas.
// i - total de cuadruplas.
typedef struct _label {
  struct _label* next;
  int *items;
  int i;
} label;

code CODE;

// Funciones que se explican más en el .c:
void newTemp(char* dir);
void concat_code(code *c1,code *c2);
void init_code();
QUAD *genQuad(char *op, char *arg1, char *arg2, char *res);
code *genCode();
int gen_code(char *op, char *arg1, char *arg2, char *res);
void gen_Quad(code *c, char *op, char *arg1, char *arg2, char *res);
label* genlist(int l);
label* merge(label *l1, label *l2);
void backpatch(label *l, label *l2);
void printCode(code *c);
label* newLabel(); 
#endif



