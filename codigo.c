#include<stdio.h>
#include <string.h>

typedef struct {
    char nombre[20];
    char apellidos[50];
    char id[20];
    int numero;
    char clave[20];
}usuario;

void main()
{
	int a, b, c, d;
	char id[20],clave[20];
	
	printf("\n\t > Bienvenido a TRANSFUTURE\n\n");
	printf("\n\t Ya tienes cuenta? SI (1) \t NO (2): ");
	scanf("%i", &a);
	
	switch(a)
	{
		case 1:
			printf ("\n Iniciar sesion como usuario(1) o como empleado(2)?");
			scanf (" %i",&c);
			switch (c)
			{
            			case 1:
                		printf("\n Usuario: ");
                		scanf(" %[^\n]",id);
                		printf("\n Clave: ");
                		scanf (" %[^\n]",clave);
                		printf ("MAS FUNCIONES PROXIMAMENTE");
                		break;
            			case 2:
                		printf ("\n Introduce la contrasena de empleado: ");
               			scanf(" %[^\n]",clave);
                		printf("MAS FUNCIONES PROXIMAMENTE");
				break;
			}
			break;
		case 2:
			printf("\n > Identificate:\n");
			usuario usuario1;
			printf("Introduce tu nick de usuario");
			scanf(" %[^\n]",usuario1.id);
			printf("\n Introduce tu nombre:");
			scanf (" %[^\n]",usuario1.nombre);
			printf("\n Introduce tus apellidos");
			scanf(" %[^\n]",usuario1.apellidos);
			printf ("Introduce tu contrasena (debe ser menor de 20 caracteres): ");
			scanf ("[^\n]",usuario1.clave);
			while (b>=20){
                		b=strlen (usuario1.clave);
               			printf ("Error en la contrasena introducela de nuevo: \n");
               			scanf (" %[^\n]",usuario1.clave);
            		}
            break;
        default:
        	printf("Operacion no valida\n");
           		printf("MAS FUNCIONES PROXIMAMENTE");
			
	}
	
	return 0;
}
