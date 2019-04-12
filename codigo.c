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

int comprobar_usuario(char *p1,char *p2);

void main()
{
	int a, b, c,flag,contador, salida;
	char id[20],clave[20];
	char *p1,*p2;
    char usuario1_id[]= "manoloeldelbombo";
	do{
    contador=0;
	system("cls");
	printf("\n\t >> Bienvenido a TRANSFUTURE << \n\n");
	do {
		printf("\n\t Ya tienes cuenta? \n\n SI (1) \t NO (2) \t salir? (3) : ");
		scanf("%i", &a);
	} while(a != 1 && a != 2 && a != 3);

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
                	do {
                    if (contador!=0)
                        printf("\n Usuario o contraseña incorrectos.\n Trate de iniciar sesion de nuevo\n");
                	printf("\n Usuario: ");
                    scanf(" %[^\n]",id);
                	printf("\n Clave: ");
                    scanf(" %[^\n]",clave);
                	p1=id;
                	p2=usuario1_id;
                	flag= comprobar_usuario(p1,p2);
                	contador++;
                	}while (flag==0 && contador<4);
                	if (contador!=0)
                        printf("Quizas no esta registrado, trate de registrarse antes de iniciar sesion\n");
                    printf ("MAS FUNCIONES PROXIMAMENTE");
                	Sleep(3000);
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
			printf("\n > Registrate:\n");
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

int comprobar_usuario(char *p1,char *p2){
    char a,b;
    int flag=1;
    while(*p1 != '\0'){
        a=*p1;
        b=*p2;
        if (a!=b)
            flag=0;
        p2++;
        p1++;
        }
    return flag;
}
