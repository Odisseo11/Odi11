#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"
#include "tablaTipo.h"
#include "pilaTablaTipo.h"

int main(int argc, char *argv[]){
    pilaTipos *ptt = crearPilaTipos();
    pilaSimbolos *pts = crearPilaSimbolos();
    insertarTablaTipo(ptt,crearTablaTipo()); //Insertar tabla de tipos y crearla
    printf("%d\n",insertarTipo(getTipoCima(ptt),crearTipoNativo(1,"int",4,1)));
    printTablaTipo(getTipoCima(ptt));
    return 0;
}
