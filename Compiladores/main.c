#include <stdio.h>
#include "tablaSimbolos.h"
#include "pilaTablaSimbol.h"
#include "tablaTipov2.h"
#include "pilaTablaTipo.h"

int main(int argc, char *argv[])
{
    typeStack *ptt = crearTypeStack();
    symStack *pts = crearSymStack();
    insertarSymTab(ptt,crearTypeTab()); //Insertar tabla de tipos y crearla
    printf("%d\n",insertarTipo(getCimaType(ptt),crearTipo(1,"int",4,1)));
    printTablaTipos(getCimaType(ptt));
    return 0;
}
