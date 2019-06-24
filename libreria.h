#include <stdio.h>
#include <stdlib.h>
typedef struct // Nuevas rutas
{
	char Origen[20];
	char Destino[20];
	float Distancia;
} Ruta;

typedef struct {
    char id[20];
    char clave[20];
}usuario;

typedef struct{
	float km;
	float hora;
	float prem;
}Precio;

int new_Id(FILE *pf);
int comp_Str(char *p1,char *p2);
float comp_Ruta(FILE *pf);
int log_In(FILE *pf);
int new_Ruta(FILE *pf,Ruta r);
float calc_Precio(FILE *pf,float dist);
void modif_Precio(FILE *pf);

void rutas_Disp(FILE *pf);
void precios_Act(FILE *pf, Precio p);
int cuent_lin(FILE *pf);
