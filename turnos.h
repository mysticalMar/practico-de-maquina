#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#include <string.h>
#define MAX 100

typedef struct{
char cliente[50];
char idturno[4];
int servicios;
char fturno[5];
int fpago;
float subtotal;
} turno;

//setters y getters
char* get_cliente(turno t){
return t.cliente;
}

void set_cliente(turno *t, char cliente[]){
strcpy(t->cliente, cliente);
}

char* get_idturno(turno t){
    return t.idturno;
}

void set_idturno(turno *t, char idturno){
    strcpy(t->idturno, idturno);
}

int get_servicios(turno t){
    return t.servicios;
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

char* get_fecha(turno t){
return t.fpago;
}

void set_fecha(turno *t, char f[]){
strcpy(t->fturno, f);
}






#endif // TURNOS_H_INCLUDED
