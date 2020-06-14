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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"

pilaSimbolos* crearPilaSimbolos()
{
    pilaSimbolos*nuevaPTS = malloc(sizeof(pilaSimbolos));
    if(nuevaPTS){
        nuevaPTS->root = NULL;
        nuevaPTS->num = 0;
    }else{
        printf("No hay memoria disponible");
    }
    return nuevaPTS;
}

void borrarPilaSimbolos(pilaSimbolos* ps) 
{
    pilaSimbolos* aux = malloc(sizeof(pilaSimbolos));	
    if(ps){
        
        while(ps->root){
          aux = ps->root;
          ps->root = ps->root->next;
          free(aux);
        }
        free(ps);
  }else{
    printf("No existe la pila de tabla de simbolos\n");
  }
}

tablaSimbolo* getSimboloCima(pilaSimbolos* ps) 
{
    tablaSimbolo *aux = ps->root;
    tablaSimbolo *aux_ant;
    while(aux != NULL){
        aux_ant = aux;
        aux = aux->next;
    }
        return aux_ant;
}

tablaSimbolo* getSimboloFondo(pilaSimbolos* ps)
{
    return ps->root;
}

void insertarTablaSimbolo(pilaSimbolos* ps, tablaSimbolo* tabla_Simbolo)
{
    if(ps){    //Si existe la pila
        if (ps->root == NULL){     //La pila esta vacia
            ps->root = tabla_Simbolo;
        }else{    
        tablaSimbolo *aux = ps->root;
            while(aux != NULL){
                aux = aux->next;
            }
            aux = tabla_Simbolo;
            aux->next = NULL;
        }
        ps->num++;
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

tablaSimbolo* sacarTablaSimbolo(pilaSimbolos* ps) 
{
    if(ps){    //Si existe la pila
        if (ps->root == NULL){     //La pila esta vacia
            printf("ERROR: La pila de tabla de simbolos esta vacia");
        }else{                      //La pila no esta vacia
            tablaSimbolo *cima = getSimboloCima(ps);
            //symtab *aux = cima;
            ps->root = cima->next;
            ps->num--;
            //free(aux);
            return cima;
        }
    }else{
        printf("La pila de tabla de simbolos no existe");
    }
}

void printPilaSimbolos(pilaSimbolos* ps) 
{
    tablaSimbolo *current;
    current = ps->root;
    while(current != NULL){
        printTablaSimbolos(current);
        current = current->next;
    }
}
