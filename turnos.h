#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#include <string.h>
#define MAX 100
typedef struct {
int ndia;
int hora[4];
} dia;
typedef struct {
dia d[249];
int mes;
} calendario;
typedef struct{
char cliente[50];
char idturno[4];
int servicios;
calendario fturno;
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

int* get_servicios(turno t){
    return t.servicios;
}

int get_dia_turno(turno t, int i){ //recursiva de busqueda?
    return t.fturno.d[i].ndia;
}

int get_mes_turno(turno t){
return t.fturno.mes;
}


void precarga_fechas(turno f[], int dt){
    int i, o, a;
FILE *fp=fopen("precarga.txt", "r");
 if(fopen("precarga.txt", "r")==NULL){
    printf("no es posible abrir el archivo \n");
    exit(1);
 }
    while (!feof(fp)){
        for (i=0; i<dt; i++){
            fscanf(fp, "%d \n", &f[i].fturno.mes);
            for (a=0; a<24; a++){
            fscanf(fp, "%d \n", &f[i].fturno.d[a].ndia);
                for (o=0; o<4; o++){
                fscanf(fp, "%d \n", &f[i].fturno.d[a].hora[o]);
                }
            }
        }
    }
    fclose(fp);
}

void muestrafechas(turno t[], int d){
    int i, o, a;
        for (i=0; i<d; i++){
             for (a=0; a<23; a++){
            printf("dia: %d \n", t[i].fturno.d[a].ndia);
                for (o=0; o<4; o++){
                printf("hora: %d \t", o);
                printf("estado: %d \n", t[i].fturno.d[a].hora[o]);
                }
                printf("mes: %d \n", t[i].fturno.mes);
             }

        }
}

#endif // TURNOS_H_INCLUDED
