/*
	*File: tablaTipov1.c
	*Autores: Alvarez González Ian Arturo y López López Ulysses
	*Creado: 22/05/2020
	*Editado y terminado: 30/05/2020
	*Ultima revisión: 31/05/2020

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tablaTipo.h"

 /* indica el numero de bytes de un tipo */
 int getTam(tabla_simbol *tt, int id){
    if(tt->root){
        type* aux = tt->root;
        while(aux != NULL){
            if(aux->id == id){
                return aux->tamBytes;
            }
            aux = aux->next;
        }
        return -1;
    }
 }

//Crea e inicializa la tabla de tipos
tipo *creaPrimitivo(int id){
    tipo* base_type = malloc(sizeof(tipo));
    if(base_type){
        base_type->type = id;
    }else{
        printf("No queda memoria\n");
    }
    return base_type;
}

int buscarTipo(tabla_simbol* tt, char* name){
    if(tt){
        int posicion = 0;
        if(tt->root == NULL){
            return -1; 
        }
        type* tipoAct = tt->root;
        while (tipoAct != NULL){
            posicion++;
            if (strcmp(name, tipoAct->name) == 0)
                return posicion;
            else
                tipoAct = tipoAct->next;
        }
        return -1;  
    }else
        printf("Error: la tabla de tipos no existe\n");
      return -1;
}


/* Regresa un apuntador a tipoBase */
tipoBase *creaArque(bool is_struct, tipo* base_type){
    tipoBase* nuevo = malloc(sizeof(tipoBase));
    if(nuevo){
        nuevo->est = is_struct;
        nuevo->t = *base_type;
    }else{
        printf("No queda memoria\n");
    }
    return nuevo;
}


 /* Regresa el tipo base de un tipo */
 tipoBase* getTipoBase(tabla_simbol *tt, int id){
   if(tt){
    if(tt->root){
       type* aux = tt->root;
       int i;
       for(i=0;i<id; i++)
         aux = aux->next;
       if(&aux->tb)
         return &aux->tb;
     }
     return NULL;
   }
   return NULL;
 }


type *creaTipo(char* name, int dim, int tipo, int numElem, bool est,tabla_simbol *estructura){
    type* nuevo_type = malloc(sizeof(type));
    if(nuevo_type){
        //Se inserta el id al mismo tiempo que la tabla de tipos 
        strcpy(nuevo_type->name, name);
        nuevo_type->tb.t.type = tipo;
        nuevo_type->tb.est = est;
        if(est == true){
            nuevo_type->tb.t.estructura = estructura;
        }
        nuevo_type->numElem = numElem;
        nuevo_type->tamBytes = dim * numElem;
        return nuevo_type;
    }else{
        printf("No queda memoria");
        return NULL;
    }
    return nuevo_type;
}

 /* Regresa el numero de elementos de un tipo */
 int getNumElem(tabla_simbol *tt, int id){
    if(tt){
        if(tt->root){
            type* aux = tt->root;
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

/* Imprime la tabla de tipos y distingue entre estructuras,nativos*/
char* getNombre(tabla_simbol *tt, int id){
    if(tt){
     if(tt->root){
        type* aux = tt->root;
        //Recorre la lista hasta que encuentre el id
        int i;
        for(i=0;i<id; i++)
            aux = aux->next;
        return aux->name;
    }
   }
    return NULL;
}

/* Inserta al final de la lista e incrementa num */
int insertarTipo(tabla_simbol *tt, type *t){
    if(tt){
        int posicion = buscarTipo(tt, t->name);
        if(posicion == -1){
            tt->num++;
            if(tt->root == NULL){
                tt->root = t; 
            }
            else{
                type* tipoAct = tt->root;
                while(tipoAct->next != NULL){
                    tipoAct = tipoAct->next;
                }
                tipoAct->next = t;
            }
            return (tt->num);
        }
        else{
            printf("No guardar nada\n");
            return -1;
        }
    }else
        printf("Error: la tabla de tipos no existe\n");
        return -1;
}

// Imprime la tabla de tipos
void printTablaTipos(tabla_simbol *tt){
    type* tipoAct = tt->root;
    tipoBase* tb;

    printf("###TABLA DE TIPOS###\n");
    printf("ID\tNOMBRE\tNUM_ELEM TAM TIPO_BASE\n");
    while(tipoAct!=NULL){
        int id = tipoAct->id;
        printf("%d\t%s\t%d\t%d\t%d\n",id,getNombre(tt,id),getNumElem(tt,id),getTam(tt,id),getTipoBase(tt,id)->t.type);
        tipoAct = tipoAct->next;
    }
}
//hay que ver porque imprime 2 tablas

/*Crea una lista de tipos*/
tabla_simbol* crearTypeTab(){
    tabla_simbol* tt= malloc(sizeof(typetab));
    tipo *tipo_base;
    tipoBase *arquetipo;
    type *nuevoTipo;
    tt->root=NULL;
    tt->num=0;
    tt->next = NULL;
    
    tipo_base = creaPrimitivo(0);
    arquetipo = creaArque(false, tipo_base);
    nuevoTipo = crearTipoNativo(0, "sin", arquetipo, 0);
    insertarTipo(tt, nuevoTipo);
    //Crear tipo entero
    tipo_base = creaPrimitivo(1);
    arquetipo = creaArque(false, tipo_base);
    nuevoTipo = crearTipoNativo(1, "ent", arquetipo, 4);
    insertarTipo(tt, nuevoTipo);

    //Crear tipo real
    tipo_base = creaPrimitivo(2);
    arquetipo = creaArque(false, tipo_base);
    nuevoTipo = crearTipoNativo(2, "real", arquetipo, 8);
    insertarTipo(tt, nuevoTipo);

    //Crear tipo doble
    tipo_base = creaPrimitivo(3);
    arquetipo = creaArque(false, tipo_base);
    nuevoTipo = crearTipoNativo(3, "dreal", arquetipo, 16);
    insertarTipo(tt, nuevoTipo);

    //Crear tipo caracter
    tipo_base = creaPrimitivo(4);
    arquetipo = creaArque(false, tipo_base);
    nuevoTipo = crearTipoNativo(4, "car", arquetipo, 4);
    insertarTipo(tt, nuevoTipo);
    return tt;
}

/* Crear un tipo nativo */
//esto no se a que se refiere :'v
type *crearTipoNativo(int id, char* name, tipoBase* tb, int size){
    type* tipo = malloc(sizeof(type));
    if(tipo != NULL){
        tipo->id = id;
        strcpy(tipo->name, name);
        tipo->tb = *tb;
        tipo->tamBytes = size;
        tipo->numElem = 0;
        tipo->next = NULL;
    }
    else{
        printf("No queda memoria\n");  
    }
    return tipo;
}
