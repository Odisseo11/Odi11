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
#include <stdlib.h>
#include <string.h>
#include "tablaSimbol.h"

parametro* crearParametro(int tipo)
{
    parametro* parame= malloc(sizeof(parametro));
    if(parame != NULL){
        parame->tipo = tipo;
        parame->next = NULL;
    }
    else{
        printf("No hay memoria disponible\n");  //ERROR
    }
    return parame;
}

/* Retorna un apuntador a una variable listParam */
listaParametro* crearLP()
{
    listaParametro* lista = malloc(sizeof(listaParametro));
    if(lista != NULL){
        lista->root = NULL;
        lista->num = 0;
    }
    else{
        printf("No hay memoria disponible\n");  //ERROR
    }
    return lista;
}

/* Agrega al final de la lista el parametro e incrementa num */
void agregarTipo(listaParametro* lp, int tipo)
{
    parametro* parame = crearParametro(tipo);
    if(lp->root == NULL){
        lp->root = parame;
    }else{
        parametro* puntero = lp->root;
        while(puntero->next){
            puntero = puntero->next;
        }
        puntero->next = parame;
    }
    lp->num++;
}
/* Borra toda la lista, libera la memoria */
void borrarListaParametro(listaParametro* lp) 
{
    if(lp){
        parametro* aux;
        while(lp->root){
          aux = lp->root;
          lp->root = lp->root->next;
          free(aux);
        }
        free(lp);
  }else{
    printf("No existe la lista de parametros\n");
  }
}

/* Cuenta el numero de parametros en la linea */
int getNumListaParametro(listaParametro* lp)
{
    return lp->num;
}

/* Retorna un apuntador a una variable symbol */
simbolo* crearSimbolo(char* id, int tipo, int dir, char* tipoVar) 
{
    simbolo* simbolotemp= malloc(sizeof(simbolo));
    if(simbolotemp != NULL)
    {
        strcpy(simbolotemp->id, id);
        simbolotemp->tipo = tipo;
        simbolotemp->dir = dir;
        sprintf(simbolotemp->tipoVar, "%s", tipoVar);
        simbolotemp->params = crearLP();
        simbolotemp->next = NULL;
    }
    else
    {
        printf("No hay memoria disponible\n");  //ERROR
    }
 return simbolotemp;

}

void agregarListaParametros(tablaSimbolo* ts, listaParametro* lp, char* id) 
{
    if(ts)
    {
        int posicion = 0;
        if(ts->root == NULL){
            return; //La tabla esta vacia
        }
        simbolo* simbolo_actual = ts->root;
        while (simbolo_actual != NULL){
            posicion++;
            if (strcmp(id, simbolo_actual->id) == 0){
                simbolo_actual->params = lp;
                return;
            }else
                simbolo_actual = simbolo_actual->next;
        }
  	}else
  		printf("Error: la tabla de simbolos no existe\n");
}

/* Retorna un apuntador a una variable symtab,
 * inicia contador en 0
 */
tablaSimbolo* crearTablaSimbolo() 
{
    tablaSimbolo* ts = malloc(sizeof(tablaSimbolo));
  ts->root = NULL;
  ts->num = 0;
  ts->next = NULL;
  return ts;
}

/* Borra toda la lista, libera la memoria */
void borrarTablaSimbolo(tablaSimbolo* ts) 
{
    if(ts){
        simbolo* aux;
        while(ts->root){
          aux = ts->root;
          ts->root = ts->root->next;
          borrarListaParametro(aux->params);
          free(aux);
        }
        free(ts);
    }
    else{
        printf("No existe la tabla de simbolos\n");
    }
}

/* Inserta al final de la lista, en caso de insertar incrementa num
 * y retorna la posicion donde inserto. En caso contrario retorna -1
*/
int insertar(tablaSimbolo* ts, simbolo* sym) 
{
    if(ts){
        int posicion = buscar(ts, sym->id);
        if(posicion == -1){
            ts->num++;
            if(ts->root == NULL){
                ts->root = sym; //es el primer simbolo
            }
            else{
                simbolo* simbolo_actual = ts->root;
                while(simbolo_actual->next != NULL){
                    simbolo_actual = simbolo_actual->next;
                }
                simbolo_actual->next = sym;
            }
            return (ts->num);
        }
        else{
            printf("Error: el simbolo ya existe en la posicion: %i\n", posicion);
            return -1;
        }
	}else
        printf("Error: la tabla de simbolos no existe\n");
}

/* Busca en la tabla de simbolos mediante el id
 * En caso de encontrar el id retorna la posicion
 * En caso contrario retorna -1
 */
int buscar(tablaSimbolo* ts, char* id) 
{
    if(ts){
        int posicion = 0;
        if(ts->root == NULL){
            return -1; //La tabla esta vacia
        }
        simbolo* simbolo_actual = ts->root;
        while (simbolo_actual != NULL){
            posicion++;
            if (strcmp(id, simbolo_actual->id) == 0)
                return posicion;
            else
                simbolo_actual = simbolo_actual->next;
        }
        return -1;	//El simbolo no existe
  	}else
  		printf("Error: la tabla de simbolos no existe\n");
}

/* Retorna el tipo de dato de un id
 * En caso no encontrarlo retorna -1
 */
int getTipo(tablaSimbolo* ts, char* id) 
{
    int posicion = buscar(ts, id);
    if (posicion == -1){
        printf("Tipo de dato no encontrado\n");
        return -1;
    }else{
        simbolo* simbolo_actual = ts->root;
        while(posicion != 1){
            posicion--;
            simbolo_actual = simbolo_actual->next;
        }
        return (simbolo_actual->tipo);
    }
}

/* Retorna el tipo de variable de un id
 * En caso no encontrarlo retorna -1
 */
char* getTipoVar(tablaSimbolo* ts, char* id)
{
    int posicion = buscar(ts, id);
    if (posicion == -1){
        printf("Tipo de variable no encontrado\n");
        return NULL;
    }else{
        simbolo* simbolo_actual = ts->root;
        while(posicion != 1){
            posicion--;
            simbolo_actual = simbolo_actual->next;
        }
        return (simbolo_actual->tipoVar);
    }
}

/* Retorna la direccion
 * En caso de no encontrarlo retorna -1
 */
int getDir(tablaSimbolo* ts, char* id)
{
    int posicion = buscar(ts, id);
    if (posicion == -1){
        printf("Direccion no encontrada\n");
        return -1;
    }else{
        simbolo* simbolo_actual = ts->root;
        while(posicion != 1){
            posicion--;
            simbolo_actual = simbolo_actual->next;
        }
        return (simbolo_actual->dir);
    }
}

/* Retorna la lista de parametros de un id
 * En caso de no encontrarlo retorna NULL
 */
listaParametro* getListaParametro(tablaSimbolo* ts, char* id)
{
    int posicion = buscar(ts, id);
    if (posicion == -1){
        printf("Lista de parametros no encontrada\n");
        return NULL;
    }else{
        simbolo* simbolo_actual = ts->root;
        while(posicion != 1){
            posicion--;
            simbolo_actual = simbolo_actual->next;
        }
        return (simbolo_actual->params);
    }
}

/* Retorna el numero de parametros de un id
 * En caso de no encontrarlo retorna -1
 */
int getNumParametro(tablaSimbolo* ts, char* id)
{
    int posicion = buscar(ts, id);
    if (posicion == -1){
        printf("Numero de parametros no encontrados\n");
        return -1;
    }else{
        simbolo* simbolo_actual = ts->root;
        while(posicion != 1){
            posicion--;
            simbolo_actual = simbolo_actual->next;
        }
        return (simbolo_actual->params->num);
    }
}

void getParametros(char* parametros, parametro* p)
{
    while(p){
        char tipo[100];
        sprintf(tipo, " %d", p->tipo);
        strcat(parametros,tipo);
        p = p->next;
    }
}
// Imprime la tabla de simbolos
void printTablaSimbolos(tablaSimbolo* ts)
{
    int simbolos = 1;
    int num_params;
    simbolo* simbolo_actual = ts->root;
    listaParametro* lista;
    parametro* param_actual;

    printf("**********TABLA DE SIMBOLOS**********\n");
    printf("NUM\t ID\t TIPO\t DIR\t TipoVar\t Params\n");
    while(simbolos != (ts->num)+1){ 
        char tipoVar_v[100];
        if(getTipoVar(ts, simbolo_actual->id) == NULL){
            strcpy(tipoVar_v,"Nulo");
        }else{
            strcpy(tipoVar_v,getTipoVar(ts, simbolo_actual->id));
        }
        printf("%d\t %s\t %d\t %d\t %s ",simbolos,simbolo_actual->id,getTipo(ts, simbolo_actual->id),getDir(ts, simbolo_actual->id),tipoVar_v);
        lista = getListaParametro(ts, simbolo_actual->id);
        if(lista){
            param_actual = lista->root;
            while(param_actual != NULL){
            printf("%d, ",param_actual->tipo);
            param_actual = param_actual->next;
            }
        }else{
                printf("-");
            }
        printf("\n");
        simbolo_actual = simbolo_actual->next;
        simbolos++;
    }
}




