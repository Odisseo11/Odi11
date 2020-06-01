#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

/* Regresa un apuntador a parametro*/
par* createParam(int tipo)
{
    par* parametro = malloc(sizeof(par)); //Se hace una asignación dinámica en memoria para el parametro.
    if (parametro != NULL) // Si el espacio en memoria está libre, se le asiga espacio para que se pueda crear.
    {
        parametro->tipo = tipo; x
        parametro->next = NULL;
    }
    //En dado caso que no se pueda crear, se manda mensaje de error
    else {
        printf("Memoria insuficiente\n");
    }
    return parametro;
}

/* Regresa un apuntador a listaPar */
listaPar* createLP()
{
    listaPar* list = malloc(sizeof(listaPar));//Se hace una asignación dinámica en memoria para la lista.
    if (list != NULL)// Si el espacio en memoria está libre, se le asiga espacio para que se pueda crear.
    {
        list->root = NULL;
        list->num = 0;
    }
    else//En dado caso que no se pueda crear, se manda mensaje de error
    {
        printf("Memoria insuficiente\n"); 
    }
    return list;
}

/* Agrega al final de la lista el parametro e incrementa num */
void addtipo(listaPar* lp, int tipo) 
{
    par* parametro = createParam(tipo);//Se llama a la función para crear un parametro
    if (lp->root == NULL) 
    {
        lp->root = parametro;
    }
    else 
    {
        param* Punt = lp->root;
        while (Punt->next) 
        {
            Punt = Punt->next;
        }
        Punt->next = parametro;
    }
    lp->num++;
}

/* Borra la lista */
void deleteListaParametros(listaPar* lp) 
{
    if (lp) 
    {
        par* aux;
        while (lp->root)
        {
            aux = lp->root;
            lp->root = lp->root->next;
            free(aux);
        }
        free(lp);
    }
    else 
    {
        printf("No existe la lista de parametros\n");
    }
}

/* Regresa un apuntador a simbolo */
simbolo* createSimbolo(char* id, int tipo, int dir, char* tipoVar) 
{
    symtab* st = malloc(sizeof(symtab));
    st->root = NULL;
    st->num = 0;
    st->next = NULL;
    return st;
}

/* Regresa un apuntador a symtab*/
tabla_simbol* createTablaSimbolo()
{
    imbolo* sym_tmp = malloc(sizeof(simbolo));
    if (sym_tmp != NULL)
    {
        strcpy(sym_tmp->id, id);
        sym_tmp->tipo = tipo;
        sym_tmp->dir = dir;
        sprintf(sym_tmp->tipoVar, "%s", tipoVar);
        sym_tmp->params = crearLP();
        sym_tmp->next = NULL;
    }
    else
    {
        printf("No queda memoria \n");
    }
    return sym_tmp;
}

/*Agrega una lista de parametros*/
void addListaPar(tabla_simbol* st, listaPar* lp, char* id)
{
    if (st) 
    {
        /*tabla vacia*/
        int pos = 0;
        if (st->root == NULL) 
        {
            return;
        }
        simbolo* simbolAct = st->root;
        while (simbolAct != NULL) 
        {
            pos++;
            if (strcmp(id, simbolAct->id) == 0)
            {
                simbolAct->parametros = lp;
                return;
            }
            else
                simbolAct = simbolAct->next;
        }
    }
    else
        printf("Error: la tabla de simbolos no existe\n");
}

/* Borra la lista */
void deleteTablaSimbolos(tabla_simbol*)
{
    if (st) 
    {
        simbolo* aux;
        while (st->root) 
        {
            aux = st->root;
            st->root = st->root->next;
            deleteListaParametros(aux->params);
            free(aux);
        }
        free(st);
    }
    else 
    {
        printf("No existe la tabla de simbolos\n");
    }
}

/* Inserta al final de la lista, si inserta incrementa num y regresa su pisicion, si no, Regresa -1*/
int insertar(tabla_simbol* st, simbolo* simb)
{
    if (st) 
    {
        int pos = buscar(st, sym->id);
        if (pos == -1) 
        {
            st->num++;
            if (st->root == NULL) 
            {
                st->root = sym;
            }
            else 
            {
                simbolo* simbolAct = st->root;
                while (simbolAct->next != NULL) 
                {
                    simbolAct = simbolAct->next;
                }
                simbolAct->next = sym;
            }
            return (st->num);
        }
        else 
        {
            printf("Error: el simbolo ya existe : %i\n", pos);
            return -1;
        }
    }
    else
        printf("Error: la tabla de simbolos no existe\n");
}

/* Busca un id en la tabla de simbolos, si lo encuentra regresa la posicion*/
int buscar(tabla_simbol* st, char* id)
{
    if (st) 
    {
        int pos = 0;
        if (st->root == NULL) 
        {
            return -1;
        }
        simbolo* simbolAct = st->root;
        while (simbolAct != NULL)
        {
            pos++;
            if (strcmp(id, simbolAct->id) == 0)
                return pos;
            else
                simbolAct = simbolAct->next;
        }
        return -1;
    }
    else
    {
        printf("Error: la tabla de simbolos no existe\n");
    }
}

/* Regresa el tipo de dato de un id */
int getTipo(tabla_simbol* st, char* id)
{
    int pos = buscar(st, id);
    if (pos == -1) 
    {
        printf("Tipo de dato no encontrado\n");
        return -1;
    }
    else 
    {
        simbolo* simbolAct = st->root;
        while (pos != 1)
        {
            pos--;
            simbolAct = simbolAct->next;
        }
        return (simbolAct->tipo);
    }
}

/* Regresa el tipo de Variable de un id*/
char* getTipoVar(tabla_simbol* st, char* id)
{
    int pos = buscar(st, id);
    if (pos == -1) 
    {
        printf("Tipo de variable no encontrado\n");
        return NULL;
    }
    else 
    {
        simbolo* simbolAct = st->root;
        while (pos != 1)
        {
            pos--;
            simbolAct = simbolAct->next;
        }
        return (simbolAct->tipoVar);
    }
}

/* Regresa la direccion de un id*/
int getDir(tabla_simbol* st, char* id)
{
    int pos = buscar(st, id);
    if (pos == -1) 
    {
        printf("No se encontro la direccion\n");
        return -1;
    }
    else 
    {
        simbolo* simbolAct = st->root;
        while (pos != 1)
        {
            pos--;
            simbolAct = simbolAct->next;
        }
        return (simbolAct->dir);
    }
}

/* Regresa la lista de parametros de un id */
listaPar* getlistaPar(tabla_simbol* st, char* id)
{
    int pos = buscar(st, id);
    if (pos == -1) 
    {
        printf("no se encontro la lista de parametros\n");
        return NULL;
    }
    else 
    {
        simbolo* simbolAct = st->root;
        while (pos != 1) 
        {
            pos--;
            simbolAct = simbolAct->next;
        }
        return (simbolAct->params);
    }
}

/* Regresa el numero de parametros de un id */
int getNumParam(tabla_simbol* st, char* id)
{
    int pos = buscar(st, id);
    if (pos == -1) 
    {
        printf("Numero de parametros no encontrados\n");
        return -1;
    }
    else 
    {
        simbolo* simbolAct = st->root;
        while (pos != 1) 
        {
            pos--;
            simbolAct = simbolAct->next;
        }
        return (simbolAct->params->num);
    }
}

/* Imprime la tabla de simbolos y sus parametros*/
void printTablaSimbolos(tabla_simbol* st)
{
    int simbolos = 1;
    int num_params;
    simbolo* simbolAct = st->root;
    listaPar* list;
    par* param_actual;

    //printf("###TABLA DE SIMBOLOS###\n");
    printf("NUM ID TIPO DIR TipoVar Params\n");
    while (simbolos != (st->num) + 1) 
    {
        char tipoVar_v[100];
        if (getTipoVar(st, simbolAct->id) == NULL) 
        {
            strcpy(tipoVar_v, "Nulo");
        }
        else 
        {
            strcpy(tipoVar_v, getTipoVar(st, simbolAct->id));
        }
        printf("%d %s %d %d %s ", simbolos, simbolAct->id, getTipo(st, simbolAct->id), getDir(st, simbolAct->id), tipoVar_v);
        list = getListParam(st, simbolAct->id);
        if (list) 
        {
            param_actual = list->root;
            while (param_actual != NULL) 
            {
                printf("%d, ", param_actual->tipo);
                param_actual = param_actual->next;
            }
        }
        else 
        {
            printf("-");
        }
        printf("\n");
        simbolAct = simbolAct->next;
        simbolos++;
    }
}