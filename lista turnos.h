#ifndef LISTA_TURNOS_H_INCLUDED
#define LISTA_TURNOS_H_INCLUDED
#include "turnos.h"

typedef struct nodo{
turno vipd; //dato
struct nodo *next; //puntero al siguiente nodo
} Nodo;
typedef struct{
Nodo *acceso;
Nodo *cursor;
Nodo *cursorA;
} lista;

void inicio(lista *l){
l->acceso=NULL;
l->cursor=NULL;
l->cursorA=NULL;
}

void reset(lista *l){
l->cursor=l->acceso;
l->cursorA=l->acceso;
}

int isOos(lista l){
if (l.cursor==NULL) return 1;
    else return 0;
}

int isEmpty(lista l){
if (l.acceso->next==NULL) return 1;
else return 0;
}

int isFull(lista l){
if (malloc(sizeof(Nodo))==NULL) return 1;
else return 0;
}

void forwards(lista *l){
l->cursorA=l->cursor;
l->cursor=l->cursor->next;
}

void insertar(lista *l, turno t){
Nodo *aux=(Nodo *)malloc(sizeof(Nodo));
if (l->cursor==l->acceso){ //inserto al principio
    l->acceso=aux;
    aux->next=l->cursor;
    l->cursor=l->acceso;
    l->cursorA=l->acceso;
}
else { //inserto en otro lado
    l->cursorA=aux;
    aux->next=l->cursor; //apunta al elemento que APUNTA EL CURSOR, NO AL CURSOR!!
    l->cursor=aux;
}
l->cursor->vipd=t;
}

void suprimir(lista *l){
	if(l->cursor==l->acceso){
		l->acceso=l->cursor->next;
		free(l->cursor);
		l->cursor=l->acceso;
		l->cursorA=l->acceso;
	}
	else {
		l->cursorA->next=l->cursor->next;
		free(l->cursor);
		l->cursor=l->cursorA->next;
	}
}

turno copia(lista l){
return l.cursor->vipd;
}


#endif // LISTA_TURNOS_H_INCLUDED
