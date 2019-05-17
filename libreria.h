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

int nuevousuario(FILE *pf);
int comprobar_usuario(char *p1,char *p2);
float comprobar_ruta(FILE *pf);
int iniciar_sesion(FILE *pf);
int nueva_ruta(FILE *pf,Ruta r);
float calcularprecio (FILE *pf,float distancia);
void modificar_precios(FILE *pf);
