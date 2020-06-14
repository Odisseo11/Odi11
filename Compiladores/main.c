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
