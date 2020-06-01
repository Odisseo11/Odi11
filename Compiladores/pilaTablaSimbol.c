#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"

/*Función que nos sirve para crear la pila 
de la tabla de simbolos*/
symstack *crearSymStack(){
    symStack *nuevaPTS = malloc(sizeof(symStack));
    if(nuevaPTS){
        nuevaPTS->root = NULL;
        nuevaPTS->num = 0;
    }else{
        printf("No hay memoria disponible");
    }
    return nuevaPTS;
}


/*Funció que borra la pila de tabla de simbolos en 
caso de no existir mandara un mensaje indicandolo*/
void borrarSymStack(symStack *pts){
    if(pts){
        tabla_simbol* aux;
        while(pts->root){
          aux = pts->root;
          pts->root = pts->root->next;
          free(aux);
        }
        free(pts);
  }else{
    printf("No existe la pila de tabla de simbolos\n");
  }
}


/*Función que añade un simbolo a la tabla, en caso de estar vacia
lo agrega al inicio de la tabla, en caso de tener un valor 
dentro de esta, lo inserta después del ultimo valor que haya
sido ingresado*/
void insertarSymTab(symStack *pts, tabla_simbol *sym_tab){
    if(pts){    
        if (pts->root == NULL){     
            pts->root = sym_tab;
        }else{    
        tabla_simbol *aux = pts->root;
            while(aux != NULL){
                aux = aux->next;
            }
            aux = sym_tab;
            aux->next = NULL;
        }
        pts->num++;
    }else{
        printf("No existe la pila de tabla de simbolos ");
    }
}
/*Función que hace pop al ultimo valor de la pila de la tabla de simbolos*/
tabla_simbol* sacarSymTab(symStack *pts){
    if(pts){    //Si existe la pila
        if (pts->root == NULL){     //La pila esta vacia
            printf("ERROR: La pila de tabla de simbolos esta vacia");
        }else{                      //La pila no esta vacia
            tabla_simbol *cima = getSymCima(pts);
            //symtab *aux = cima;
            pts->root = cima->next;
            pts->num--;
            //free(aux);
            return cima;
        }
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

/*Función que obtiene el simbolo que esta 
en la cima de la pila*/
tabla_simbol* getSymCima(symStack *pts){
    tabla_simbol *aux = pts->root;
    tabla_simbol *aux_ant;
    while(aux != NULL){
        aux_ant = aux;
        aux = aux->next;
    }
        return aux_ant;
}

/*Función que obtiene el simbolo que esta 
en el fondo de la pila*/
tabla_simbol* getSymFondo(symStack *pts){
    return pts->root;
    /*symtab *aux = pts->root;
    symtab *aux_next = pts->root->next;
    while(aux_next != NULL){
        aux = aux_next;
        aux_next = aux->next;
    }
        return aux;*/
}
/*Función que sirve para poder imprimir la pila de la tabla de simbolos*/
void printSymPila(symStack *pts){
    tabla_simbol *current;
    current = pts->root;
    while(current != NULL){
        printTablaSimbolos(current);
        current = current->next;
    }
}
