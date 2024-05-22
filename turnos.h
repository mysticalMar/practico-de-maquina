#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#define MAX 100
typedef struct {
int ndia;
int hora[4];
} dia;
typedef struct {
dia d[MAX];
int mes;
} fecha;
typedef struct{
char cliente[50];
int idturno;
int servicios_a_realizar;
fecha fturno[MAX];
int fpago;
float subtotal;
} turno;
void precarga_fechas(turno f[], int d){
    int i, o;
FILE *fp=fopen("precarga.txt", "r");
 if(fopen("precarga.txt", "r")==NULL){
    printf("no es posible abrir el archivo \n");
    exit(1);
 }
    while (!feof(fp)){
        for (i=0; i<d; i++){
        fscanf(fp, "%d \n", &f[i].fturno[i].d[i].ndia);
        fscanf(fp, "%d \n", &f[i].fturno[i].mes);
            for (o=0; o<4; o++){
            fscanf(fp, "%d \n", &f[i].fturno[i].d[i].hora[o]);
            }
        }
    }
    fclose(fp);
}

void muestrafechas(turno t[], int d){
    int i, o;
        for (i=0; i<d; i++){
            printf("dia: %d \t", t[i].fturno[i].d[i].ndia);
            printf("mes: %d \n", t[i].fturno[i].mes);
            for (o=0; o<4; o++){
            printf("hora: %d \t", o);
            printf("estado: %d \n", t[i].fturno[i].d[i].hora[o]);
            }
        }
}

#endif // TURNOS_H_INCLUDED
