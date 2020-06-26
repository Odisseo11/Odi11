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
#include "pilaTablaTipo.h"
#include "tablaTipo.h"
#include <stdio.h>
#include <stdlib.h>


pilaTipos* crearPilaTipos()
{
    pilaTipos *nuevaPTT = malloc(sizeof(pilaTipos));
    if(nuevaPTT){
        nuevaPTT->root = NULL;
        nuevaPTT->num = 0;
    }else{
        printf("No hay memoria disponible");
    }
    return nuevaPTT;
}

void borrarpilaTipos(pilaTipos *pt)
{
    if(pt){
        tablaTipo* aux;
        while(pt->root){
        aux = pt->root;
        pt->root = pt->root->next;
        free(aux);
        }
        free(pt);
    }else{
    printf("No existe la pila de tabla de tipos\n");
    }
}

tablaTipo* getTipoCima(pilaTipos* pt)
{
    tablaTipo *aux = pt->root;
    if(aux == NULL){return NULL;}
    while(aux->next != NULL){
        aux = aux->next;
    }
    return aux; 
}

tablaTipo* getTipoFondo(pilaTipos* pt)
{
    return pt->root;
}

void insertarTablaTipo(pilaTipos* pt, tablaTipo* tabla_Tipo) 
{
    if(pt){    //Si existe la pila
        if (pt->root == NULL){     //La pila esta vacia
            pt->root = tabla_Tipo;
        }else{                      //La pila no esta vacia
            tablaTipo *aux = pt->root;
            while(aux != NULL){
                aux = aux->next;
            }
            aux = tabla_Tipo;
            aux->next = NULL;
        }
        pt->num++;
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

tablaTipo* sacarTablaTipos(pilaTipos* pt) 
{
    if(pt){    //Si existe la pila
        if (pt->root == NULL){     //La pila esta vacia
            printf("ERROR: La pila de tabla de simbolos esta vacia");
        }else{                      //La pila no esta vacia
            tablaTipo *cima = getTipoCima(pt);
            //typetab *aux = cima;
            pt->root = cima->next;
            pt->num--;
            //free(aux);
            return(cima);
        }
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

void printPilaTipos(pilaTipos* pt) 
{
    tablaTipo *current;
    current = pt->root;
    while(current != NULL){
        printTablaTipo(current);
        current = current->next;
    }
}




