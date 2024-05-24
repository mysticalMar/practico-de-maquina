#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#include <string.h>
#define MAX 100
typedef struct {
int ndia;
int mes;
int hora[4];
} fecha;

typedef struct{
char cliente[50];
char idturno[4];
int servicios;
fecha fturno[249];
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
    return t.fturno[i].ndia;
}

int get_mes_turno(turno t, int i){
return t.fturno[i].mes;
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
            for (a=0; a<24; a++){
            fscanf(fp, "%d \n", &f[i].fturno[a].mes);
            fscanf(fp, "%d \n", &f[i].fturno[a].ndia);
                for (o=0; o<4; o++){
                fscanf(fp, "%d \n", &f[i].fturno[a].hora[o]);
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
            printf("dia: %d \n", t[i].fturno[a].ndia);
            printf("mes: %d \n", t[i].fturno[a].mes);
                for (o=0; o<4; o++){
                printf("hora: %d \t", o);
                printf("estado: %d \n", t[i].fturno[a].hora[o]);
                }

             }

        }
}

#endif // TURNOS_H_INCLUDED
