#include "pilaTablaTipo.h"
#include "tablaTipo.h"
#include <stdio.h>
#include <stdlib.h>

/*Función que se encarga de crear la pila de tabla de tipos
En caso de no haber memoria manda un mensaje*/
typesStack *crearTypeStack(){
    typeStack *nuevaPTT = malloc(sizeof(typeStack));
    if(nuevaPTT){
        nuevaPTT->root = NULL;
        nuevaPTT->num = 0;
    }else{
        printf("No hay memoria disponible");
    }
    return nuevaPTT;
}

/*Función que se encarga de borrar la pila de tabla de tipos
En caso de no existir dicha pila, se envía un mensaje*/
void borrarTypeStack(typeStack *ptt){
    if(ptt){
        tabla_simbol* aux;
        while(ptt->root){
          aux = ptt->root;
          ptt->root = ptt->root->next;
          free(aux);
        }
        free(ptt);
  }else{
    printf("No existe la pila de tabla de tipos\n");
  }
}

/*Función que añade un tipo a la tabla, en caso de estar vacia
lo agrega al inicio de la tabla, en caso de tener un valor 
dentro de esta, lo inserta después del ultimo valor que haya
sido ingresado*/
void insertarTypeTab(typeStack *ptt, tabla_simbol *type_tab){
    if(ptt){    //Si existe la pila
        if (ptt->root == NULL){     //La pila esta vacia
            ptt->root = type_tab;
        }else{                      //La pila no esta vacia
            tabla_simbol *aux = ptt->root;
            while(aux != NULL){
                aux = aux->next;
            }
            aux = type_tab;
            aux->next = NULL;
        }
        ptt->num++;
    }else{
        printf("La pila de tabla de tipos no existe");
    }
}

/*Función que hace pop al ultimo valor de la tabla de tipos*/
tabla_simbol* sacarTypeTab(typeStack *ptt){
    if(ptt){    
        if (ptt->root == NULL){     
            printf("ERROR: La pila de tabla de tipos esta vacia");
        }else{                      
            tabla_simbol *cima = getTypeCima(ptt);
            //typetab *aux = cima;
            ptt->root = cima->next;
            ptt->num--;
            //free(aux);
            return(cima);
        }
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

/*Función que nos sirve para poder tomar el tipo que esta en la cima
de la pila*/
tabla_simbol* getTypeCima(typeStack *ptt){
    tabla_simbol *aux = ptt->root;
    tabla_simbol *aux_ant;
    while(aux != NULL){
        aux_ant = aux;
        aux = aux->next;
    }
    return aux_ant;
}

/*Función que obtiene el ultimo tipo de la pila*/
tabla_simbol* getTypeFondo(typeStack *ptt){
    return ptt->root;/*
    typetab *aux = ptt->root;
    typetab *aux_next = ptt->root->next;
    while(aux_next != NULL){
        aux = aux_next;
        aux_next = aux->next;
    }
        return aux;*/
}

/*Función que imprime la pila de tipo de datos*/
void printTypePila(typeStack *ptt){
    tabla_simbol *current;
    current = ptt->root;
    while(current != NULL){
        printTablaTipos(current);
        current = current->next;
    }
}
