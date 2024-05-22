#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#define MAX 100
typedef struct {
int dia;
int mes;
int hora;
int estado; //0 ocupado 1 libre
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
    int i;
FILE *fp=fopen("precarga.txt", "r");
 if(fopen("precarga.txt", "r")==NULL){
    printf("no es posible abrir el archivo \n");
    exit(1);
 }
    while (!feof(fp)){
        for (i=0; i<d; i++){
        fscanf(fp, "%d \n", &f[i].fturno[i].dia);
        fscanf(fp, "%d \n", &f[i].fturno[i].mes);
        fscanf(fp, "%d \n", &f[i].fturno[i].hora);
        fscanf(fp, "%d \n", &f[i].fturno[i].estado);
        }
    }
    fclose(fp);
}
int buscadia(turno f[], int dia, int mes, int d){
    if (d<0){
        return -1;
    }
    else {
        if (f[d-1].fturno[d-1].dia==dia&&f[d-1].fturno[d-1].mes==mes){
            return d-1;
            exit(1);
        }
        else buscadia(f, dia, mes, d-1);
    }
}
void muestrafechas(turno t[], int d){
int i;
for (i=0; i<d; i++){
    printf("dia:%d \t", t[i].fturno[i].dia);
    printf("mes:%d \t", t[i].fturno[i].mes);
    printf("hora:%d \t", t[i].fturno[i].hora);
    printf("estado: %d\n", t[i].fturno[i].estado);
}
}

#endif // TURNOS_H_INCLUDED
