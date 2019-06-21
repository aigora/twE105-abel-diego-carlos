#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "libreria.h"
#define P 123456
// P es el pin para acceder al menu como trabajador de la empresa

int main()
{
	int a, b, c, flag, contador = 1, pin;
	float distancia,precio;
	char *p1,*p2;
	FILE *puntero;
	Ruta r;
	do{
	system("cls");

	printf("\n\t >> Bienvenido a TRANSFUTURE << \n\n");
	do {
		printf("\n  >>  Ya tienes cuenta? \n\n SI (1) \t NO (2) \t Salir (3): ");
			scanf("%i", &a);
	} while(a != 1 && a != 2 && a != 3);

	switch(a)
	{
		case 1:
			do {
				system("cls");
				printf ("\n  >>  Eres CLIENTE (1)  o  EMPLEADO (2)? ");
					scanf (" %i",&c);
			}while(c != 1 && c != 2);

			switch (c)
			{
            	case 1:
            	    system("cls");
                	flag=iniciar_sesion(puntero);
                    if (flag==1){
                        printf("\nBienvenido!\n\n");
                        distancia=comprobar_ruta(puntero);
                        if (distancia==-1)
                            break;
                        precio=calcularprecio(puntero,distancia);
                    }else if(flag==-1){
                        printf("No esta registrado ese usuario; Regístrese antes de iniciar sesion.\n");
                    }
                	Sleep(3000);
                	break;

            	case 2:
            		printf ("\n Introduce el pin secreto de la empresa: ");
                   	scanf("%i",&pin);
                   	system("cls");
            	if (pin!=P)
				{
					do
					{
               			{    
               				printf("El pin es incorrecto\tRecuerda que solo tienes tres intentos \t\t ");
               				printf(" intento numero: %d",contador+1);
               				printf ("\n Introduce el pin secreto de la empresa: ");
                   			scanf("%i",&pin);
                   			system("cls");
               				contador++;
               				Sleep(2000);
						}
                	}
                	while ((pin!=P)&&(contador<3));
                }
                	if (pin == P)
					{
                        FILE *file=fopen("Distancias.txt","a"); //ruta en nuestro pc del archivo al que queremos anadir texto
                        // Ruta en nuestro pc del archivo al que queremos anadir texto

                        if(file == NULL)
                        {
                            printf("Error al abrir el archivo");
                            //return 0;
                        }
						else
						{
                            do
							{
                                system("cls");
                                printf("Que desea hacer? 1.Introducir nueva ruta\t 2.Modificar precios\t 3.Salir \t");
                            scanf ("%i",&b);
                            fflush(stdin);
                            switch (b)
                            {
                                case 1:
                                nueva_ruta(file,r);
                                break;
                                case 2:
                                    modificar_precios(puntero);
                                break;
                                case 3:
                                flag=1;
                                printf("\nHasta la proxima");
                                break;
                            }
                            }
							while(flag!=1);
                        }
                	}
                	
					else if(contador==3)
					{
                        printf("\n\tPor motivos de seguridad sera redirigido al menu de inicio\n");
                        Sleep(3000);
                        contador=0;
                        break;
                	}
                	Sleep(2000);
			}		
                    break;
            

		case 2:
			nuevousuario(puntero);
            printf("\nSERA REDIRIGIDO AL HOME");
            Sleep(2000);
            break;
        case 3:
        	system("cls");
        	printf("\n  >>  Hasta la proxima.");
            break;
        default:
        	printf("Operacion no valida\n");
        	Sleep(2000);
	}
	} while(a!=3);

	//return 0;
}


