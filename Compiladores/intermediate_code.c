/*
	*File: parser.y
	*Autores: Alvarez González Ian Arturo y López López Ulysses
	*Creado: 12/06/2020
	*Editado y terminado: 14/06/2020
	*Ultima revisión: 14/06/2020
	*Este programa lleva a cabo la generación del analizador sintáctico
*/
#include <stdio.h>
#include <stdlib.h>
#include "intermediate_code.h"

/*Función que inicializa la varable CODE */
void init_code(){
	CODE = *genCode();
}


/*Función que genera código*/
int gen_code(char *op , char *arg1, char *arg2, char *res){
	QUAD *q = genQuad(op,arg1,arg2,res);
	code *c;
	c = &CODE;
	gen_Quad(c,op,arg1,arg2,res);
	return c->instruc -1;
}

/* Funcion que reserva memoria para una cuadrupla.*/
QUAD* genQuad(char *op , char *arg1, char *arg2, char *res){
	QUAD *q;
	q = malloc(sizeof(QUAD));
	q->op = op;
	q->arg1 = arg1;
	q->arg2 = arg2;
	q->res = res;
	return q;
}

void newTemp(char* dir)
{
	sprintf(dir,"t%d",temporalGlobal++);
}


/*Función que va generando las cuadruplas*/
void gen_Quad(code* c, char *op, char* arg1, char *arg2, char* res){
	QUAD *q, *q_temp;
	q = genQuad(op,arg1,arg2,res);
	if(c->root == NULL)
		c->root = q;
	else{
		q_temp = c->root;
		while(q_temp->next != NULL)
			q_temp = q_temp->next;
		q_temp->next = q;
		q->next = NULL;
	}
	c->instruc++;
}

/*Funcion que reserva memoria para el codigo*/
code* genCode(){
	code *c;
	c = malloc(sizeof(code));
	c->root = malloc(sizeof(QUAD));
	c->instruc = 0;
	return c;
}

/*Función que borra una cuadrupla*/
void borraQuad(QUAD *q){
	while(q != NULL){
		borraQuad(q->next);
	}
	free(q);
}

/*Función que se encarga de borrar codigo*/
void borraCode(code *c){
	free(c);
	borraQuad(c->root);
}

/* Se crea una lista dentro de una etiqueta. */
label *genlist(int l){
	
	label *list = malloc(sizeof(label));
	list->items = malloc(sizeof(int) * 100);
	list->i = 0;
	list->items[list->i] = l;
	list->i++;
	return list;
}

/* Función que combina ambas listas */
label *merge(label *l1, label *l2){
	label *l = malloc(sizeof(label));
	l = l1;
	for(int i = 0; i < l2->i; i++){
		l->items[l->i] = l2->items[i];
		l->i++;
	}
	return l;
}

/* Se cambia la localizacion del resultado. */
void backpatch(label *l, label *l2){
	char res[100];
	int inst;
	if(l2){
		inst = l2->i;
	}else{
		inst = -1;
	}
	QUAD *q = CODE.root;
	for(int i = 0; i < l->i ; i++){
		sprintf(res, "%d", inst);
		strcpy((CODE.root[l->items[i]]).res, res);
	}
	
}

/*Función que concatena o combina los códigos*/
void concat_code(code *c1,code *c2){
	printf("%d",c2->instruc);
	for(int i = 0; i<c2->instruc; i++){
		gen_Quad(c1,c2->root[i].op,c2->root[i].arg1,c2->root[i].arg2,c2->root[i].res);
	}
}
