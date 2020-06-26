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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tablaTipo.h"

//Crea e inicialia una tabla de tipos
tipo* crearTipoPrimitivo(int id) 
{
    tipo* base_type = malloc(sizeof(tipo));
    if(base_type){
        base_type->type = id;
    }else{
        printf("No hay memoria disponible\n");
    }
    return base_type;
}

/* Retorna un apuntador a una variable tipo */
tipo* crearTipoStruct(tablaSimbolo* estructura) 
{
    tipo* base_type = malloc(sizeof(tipo));
    if(base_type){
        base_type->estructura = estructura;
    }else{
            printf("No hay memoria disponible\n");
    }
    return base_type;
}

/* Retorna un apuntador a una variable tipoBase */
tipoBase* crearATipo(bool is_struct, tipo tipo_Base) {
    tipoBase* nuevo = (tipoBase*)malloc(sizeof(tipoBase)); 
    if(nuevo){
        nuevo->est = is_struct;
        nuevo->t = tipo_Base;
    }else{
        printf("No hay memoria disponible\n");
    }
    return nuevo;
}

/* Crear un tipo arreglo */
tipo1* crearTipoArray(int id, char* nombre, tipoBase* tb, int size, int num_elem)
{
    tipo1* tipo = malloc(sizeof(tipo1));
    if(tipo != NULL){
        tipo->id = id;
        strcpy(tipo->nombre, nombre);
        tipo->tb = tb;
        tipo->tamBytes = size;
        tipo->numElem = num_elem;
        tipo->next = NULL;
    }
    else{
        printf("No hay memoria disponible\n");  //ERROR
    }
    return tipo;
}

/* Crear un tipo nativo */
tipo1* crearTipoNativo(int id, char* nombre, tipoBase* tb, int size) 
{
    tipo1* tipo = malloc(sizeof(tipo1));
    if(tipo != NULL){
        tipo->id = id;
        strcpy(tipo->nombre, nombre);
        tipo->tb = tb;
        tipo->tamBytes = size;
        tipo->numElem = 0;
        tipo->next = NULL;
    }
    else{
        printf("No hay memoria disponible\n");  //ERROR
    }
    return tipo;
}

tipo1* crearTipo(char* nombre, int dim, int tipon, int numElem, bool est, tablaSimbolo* estructura)
{ 
    tipo ft;
    tipo1* nuevo_type = (tipo1*)malloc(sizeof(tipo1));
    if (nuevo_type) {
        //El id se agrega al momento de insertar a la tabla de tipos 
        strcpy(nuevo_type->nombre, nombre);
        
        if (est == true) {
            ft.estructura = estructura;
            nuevo_type->tb = crearATipo(est,ft);
        }
        else
        {
            ft.type = tipon; 
            nuevo_type->tb = crearATipo(est,ft);
        }
        
        
        nuevo_type->numElem = numElem;
        nuevo_type->tamBytes = dim * numElem;
        //El espacio en bytes se agrega al momento de insertar a la tabla de tipos
        return nuevo_type;
    }
    else {
        printf("No hay memoria disponible");
        return NULL;
    }
    return nuevo_type;
}

/*Crea una lista de tipos*/
tablaTipo* crearTablaTipo()
{
    tablaTipo* tt= malloc(sizeof(tablaTipo));
    tt->root=NULL;
    tt->num=0;
    tt->next = NULL;
    return tt;
}

/* Borra la tabla de tipos, libera memoria */
void borrarTablaTipo(tablaTipo* tt) {
    while(tt!=NULL){
        borrarTablaTipo(tt->next);
        free(tt);
    }
}
void borrarTipo(tipo1 *t){ 
    while(t!=NULL){
        borrarTipo(t->next);
        free(t);
    }
    
}

int buscarTipo(tablaTipo* tt, char* nombre){
    if(tt){
        int posicion = 0;
        if(tt->root == NULL){
            return -1; //La tabla esta vacia
        }
        tipo1* tipo_actual = tt->root;
        while (tipo_actual != NULL){
            posicion++;
            if (strcmp(nombre, tipo_actual->nombre) == 0)
                return posicion;
            else
                tipo_actual = tipo_actual->next;
        }
        return -1;  //El simbolo no existe
    }else
        printf("Error: la tabla de tipos no existe\n");
        return -1;
}

/* Inserta al final de la lista en caso de insertar incrementa num
 * Retorna la posicion donde inserto en caso contrario retorna -1
 */
int insertarTipo(tablaTipo* tt, tipo1* t) 
{
    if(tt){
        int posicion = buscarTipo(tt, t->nombre);
        if(posicion == -1){
            t->id = tt->num;
            tt->num++;
            if(tt->root == NULL){
                tt->root = t; //es el primer simbolo
            }
            else{
                tipo1* tipo_actual = tt->root;
                while(tipo_actual->next != NULL){
                    tipo_actual = tipo_actual->next;
                } 
                tipo_actual->next = t;
            }
            return (tt->num-1);
        }
        else{
            printf("No guardar nada\n");
            return -1;
        }
    }else
        printf("Error: la tabla de tipos no existe\n");
        return -1;
}

/* Retorna el tipo base de un tipo
  * En caso de no encontrarlo retorna NULL
  */
tipoBase* getTipoBase(tablaTipo* tt, int id) 
{
    if(tt){
    if(tt->root){
        tipo1* aux = tt->root;
        int i;
        for(i=0;i<id; i++)
            aux = aux->next;
            if(aux->tb)
            return aux->tb;
    }
    return NULL;
    }
    return NULL;
}
/* Retorna el numero de bytes de un tipo
  * En caso de no encontrarlo retorna -1
  */
int getTamanio(tablaTipo* tt, int id) 
{
    if(tt->root){
        tipo1* aux = tt->root;
        while(aux != NULL){
            if(aux->id == id){
                return aux->tamBytes;
            }
            aux = aux->next;
        }
        return -1;
    }
}



/* Retorna el numero de elementos de un tipo
  * En caso de no encontrarlo retorna -1
  */
int getNumElem(tablaTipo* tt, int id)  {
    if(tt){
        if(tt->root){
            tipo1* aux = tt->root;
            //Recorre la lista hasta que encuentre el id
            int i;
            for(i=0;i<id; i++)
                aux = aux->next;
            return aux->numElem;
        }
        return -1;
    }
    return -1;
}

/* Imprime toda la tabla de tipos,
 * distingue entre estructuras, arrays y tipos nativos
*/
char* getNombre(tablaTipo* tt, int id) 
{
    if(tt){
    if(tt->root){
        tipo1* aux = tt->root;
        //Recorre la lista hasta que encuentre el id
        int i;
        for(i=0;i<id; i++)
            aux = aux->next;
        return aux->nombre;
    }
}
    return NULL;
}
// Imprime la tabla de tipos
void printTablaTipo(tablaTipo* tt) 
{
    tipo1* tipo_actual = tt->root;
    tipoBase* tb;
    int a;
    printf("##########TABLA DE TIPOS###########\n");
    printf("ID\tNOMBRE\t TAM TIPO_BASE\n");
    while(tipo_actual!=NULL){
        int id = tipo_actual->id;
        if(getTipoBase(tt,id)->est == false)
        {
            a = getTipoBase(tt,id)->t.type;
        }else
        {   
            a = -2;
        }
        printf("%d\t%s\t%d\t%d\n",id,getNombre(tt,id),getTamanio(tt,id),a);
        tipo_actual = tipo_actual->next;
    }
}









