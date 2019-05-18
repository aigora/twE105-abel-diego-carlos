#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "libreria.h"
#define P 123456
// P es el pin para acceder al menu como trabajador de la empresa

int main()
{
	int a, b, c, flag, contador = 3, salida, pin;
	float distancia,precio;
	char id[20],clave[20];
	char *p1,*p2;
	FILE *puntero;
	Ruta r;
	do{
		system("cls");
	
		printf("\n\t >> Bienvenido a TRANSFUTURE << \n\n");
		do {
			printf("\n  >>  Ya tienes cuenta? \n\n  (1)Si | (2)No | (3)Salir ");
				scanf("%i", &a);
		} while(a != 1 && a != 2 && a != 3);
	
		switch(a)
		{
			case 1:
				do {
					system("cls");
					printf ("\n  >>  Eres (1)cliente o (2)empleado ?");
						scanf (" %i",&c);
				}while(c != 1 && c != 2);
	
				switch (c)
				{
	            	case 1:
	            	    system("cls");
	                	flag=iniciar_sesion(puntero);
	                    if (flag==1){
	                        printf("\n  Bienvenido...\n\n");
	                        distancia=comprobar_ruta(puntero);
	                        if (distancia==-1)
	                            break;
	                        precio=calcularprecio(puntero,distancia);
	                    }else if(flag==-1){
	                        printf("  Este usuario no existe... (Regístrese antes de iniciar sesion)\n");
	                    }
	                	Sleep(3000);
	                	break;
	
	            	case 2:
	            		printf ("\n  Introduce el pin secreto de la empresa: ");
	                   	scanf("%i",&pin);
	                   	system("cls");
	            	if (pin!=P)
					{
						do
						{   
	               				printf("  El pin es incorrecto...");
	               				printf ("\n  Introduce el pin secreto de la empresa\t (Te quedan %i intentos)",contador-1);
	               				contador--;
	                   			scanf("%i",&pin);
	                   			system("cls");
	               				Sleep(1000);
	                	} while (pin!=P && contador>1);
	                }
	                	if (pin == P)
						{
	                        FILE *file=fopen("Distancias.txt","a"); //ruta en nuestro pc del archivo al que queremos anadir texto
	                        // Ruta en nuestro pc del archivo al que queremos anadir texto
	
	                        if(file == NULL)
	                        {
	                            printf("  Error al abrir el archivo...");
	                            //return 0;
	                        }
							else
							{
	                            do
								{
		                            system("cls");
		                            printf("  Que desea hacer?\n  (1)Introducir nueva ruta | (2)Modificar precios | (3)Salir");
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
		                                printf("\n  Hasta la proxima...");
		                                break;
		                            }
	                            } while(flag!=1);
	                        }
	                	}
	                	
						else if(contador==1)
						{
	                        printf("\n  Por motivos de seguridad seras redirigido al menu de inicio...");
	                        Sleep(3000);
	                        contador=3;
	                        break;
	                	}
	                	Sleep(1000);
				}		
	            break;
	            
			case 2:
				nuevousuario(puntero);
	            printf("\n  Estas siendo redirigido al inicio...");
	            Sleep(2000);
	            break;
	        case 3:
	        	system("cls");
	        	printf("\n  >>  Hasta la proxima");
	            break;
	        default:
	        	printf("Operacion no valida\n");
	        	Sleep(2000);
		}
	} while(a!=3);

	//return 0;
}


