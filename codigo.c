#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

typedef struct {
    char nombre[20];
    char apellidos[50];
    char id[20];
    char clave[20];
}usuario;

void main()
{
	int a, b, c, salida;
	char id[20],clave[20];
	do{
	system("cls");
	printf("\n\t > Bienvenido a TRANSFUTURE\n\n");
	do {
		printf("\n\t Ya tienes cuenta? SI (1) \t NO (2) \t O deseas salir? (3): ");
		scanf("%i", &a);
	} while(a != 1 && a != 2&&a!=3);

	switch(a)
	{
		case 1:
			do {
				printf ("\n Iniciar sesion como usuario(1) o como empleado(2)?");
					scanf (" %i",&c);
			}while(c != 1 && c != 2);

			switch (c)
			{
            	case 1:
                	printf("\n Usuario: ");
                		scanf(" %[^\n]",id);
                	printf("\n Clave: ");
                		scanf(" %[^\n]",clave);
                	printf("\nMAS FUNCIONES PROXIMAMENTE");
                	Sleep(2000);
                	break;

            	case 2:
                	printf ("\n Introduce la contrasena de empleado: ");
               			scanf(" %[^\n]",clave);
                	printf("\nMAS FUNCIONES PROXIMAMENTE");
                	Sleep(2000);
                break;

                default:
                	printf("Operacion no disponible\n");
                	Sleep(2000);
			}
			break;

		case 2:
			printf("\n > Identificate:\n");
			usuario usuario1;
			printf("Introduce tu nick de usuario:\t");
				scanf(" %[^\n]",usuario1.id);
			printf("\nIntroduce tu nombre:\t");
				scanf (" %[^\n]",usuario1.nombre);
			printf("\nIntroduce tus apellidos:\t");
				scanf(" %[^\n]",usuario1.apellidos);
			printf ("\nIntroduce tu contrasena (debe tener entre 4 y 20 letras):\t");
				scanf(" %[^\n]",usuario1.clave);

			b=strlen(usuario1.clave);
			printf("%i",b);
			while (b>20 || b<4){
               	printf ("Error en la contrasena introducela de nuevo: \n");
           			scanf (" %[^\n]",usuario1.clave);
           			b=strlen(usuario1.clave);
            		}
            printf("MAS FUNCIONES PROXIMAMENTE");
            Sleep(2000);
            break;
        case 3:
            break;
        default:
        	printf("Operacion no valida\n");
        	Sleep(2000);
	}
	} while(a!=3);

	return 0;
}