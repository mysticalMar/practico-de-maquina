#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#include <string.h>
#define MAX 100

typedef struct{
char cliente[50];
char idturno[4];
int servicios[15];
char fturno[5];
int fpago;
float subtotal;
} turno;

//setters y getters
char* get_cliente(turno t){
    char *p;
    p=(char*)malloc(strlen(t.cliente)+1);
    if (p==NULL)return (char*)1;
    else {
        strcpy(p,t.cliente);
        return p;
    }
}

void set_cliente(turno *t, char cliente[]){
strcpy(t->cliente, cliente);
}

char* get_idturno(turno t){
    char *p;
    p=(char*)malloc(strlen(t.idturno)+1);
    if (p==NULL)return (char*)1;
    else {
        strcpy(p,t.idturno);
        return p;
    }
}

void set_idturno(turno *t, char* idturno){
    strcpy(t->idturno, idturno);
}

int get_servicios(turno t, int i){
    return t.servicios[i];
}

void set_servicios(turno *t, int s){
t->servicios[s]=1;
}

int get_fpago(turno t){
    return t.fpago;
}

void set_fpago(turno *t, int f){
 t->fpago=f;
}

float get_subtotal(turno t){
return t.subtotal;
}

void set_subtotal(turno *t, float s){
 t->subtotal=s;
}

char* get_fecha (turno t){
    char *p;
    p=(char*)malloc(strlen(t.fturno)+1);
    if (p==NULL)return (char*)1;
    else {
        strcpy(p,t.fturno);
        return p;
    }
}

void set_fecha(turno *t, char* f[]){
strcpy(t->fturno, f);
}

 //extra
void reset_turno(turno *t) {
    int i;
    strcpy(t->cliente, "");
    strcpy(t->fturno, "");
    strcpy(t->idturno, "");
    for (i=0; i<15; i++){
    t->servicios[i] = 0;
    }
    t->fpago = 0;
    t->subtotal = 0.0;
}




#endif // TURNOS_H_INCLUDED
