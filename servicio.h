#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <string.h>
#include <malloc.h>

typedef struct{
    int id_servicio;
    char descripcion[100];
    float precio;
    int descuento;
    }servicio;


//función precarga
void precarga_servicio(servicio aux[]){
    int i;
    FILE *fp=fopen("servicios.txt","r");
    if(fopen("servicios.txt","r")==NULL){
        printf("no es posible abrir el archivo\n");
        exit(1);
    }
    while (!feof(fp)){
        for(i=0;i<15;i++){
            fscanf(fp, "%d \n", &aux[i].id_servicio);
            fscanf(fp,"%[^\n]s \n", &aux[i].descripcion);
            fscanf(fp, "%f \n", &aux[i].precio);
            fscanf(fp, "%d \n", &aux[i].descuento);
        }
    }
    fclose(fp);
}




//setters
void set_id_servicio (servicio *s, int idservicio){
    s->id_servicio=idservicio;
}

void set_descripcion (servicio *s, char des[100]){
    strcpy (s->descripcion,des);
}

void set_precio (servicio *s, float prec){
    s->precio=prec;
}

void set_descuento (servicio *s, int desc){
    s->descuento=desc;
}
//getters
int get_id_servicio (servicio s){
    return s.id_servicio;
}

char* get_descripcion (servicio s){
    char *p;
    p=(char*)malloc(strlen(s.descripcion)+1);
    if(p==NULL)return 0;
    else{
         strcpy(p,s.descripcion);
         return p;
    }
}

float get_precio (servicio s){
    return s.precio;
}

int get_descuento (servicio s){
    return s.descuento;
}

#endif // SERVICIO_H_INCLUDED
