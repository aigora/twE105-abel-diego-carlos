#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "libreria.h"
#define P 123456
// P es el pin para acceder al menu como trabajador de la empresa

int main()
{
	int a, b, c, flag, contador=2, pin;
	float dist,precio;
	char *p1,*p2;
	FILE *punt, *punt2;
	Ruta r;
	do{
		system("cls");

		printf("\n\t >> Bienvenido a TRANSFUTURE << \n\n");
		
		do{
			printf("\n  >>  Ya tienes cuenta? \n\n\t 1) Si \n\n\t 2) No \n\n\t 3) Salir\n");
				scanf("%i", &a);
		}while(a != 1 && a != 2 && a != 3);

		switch(a)
		{
			case 1:
				do {
					system("cls");
					printf ("\n  >>  Eres... \n\n\t 1) Cliente \n\n\t 2) Empleado\n");
						scanf (" %i",&c);
				}while(c != 1 && c != 2);
	
				switch (c)
				{
	            	case 1:
	            	    system("cls");
	                	flag=log_In(punt);
	                    if (flag==1){
	                        printf("\n > Bienvenido!\n\n");
	                        dist=comp_Ruta(punt);
	                        if (dist==-1)
	                            break;
	                        precio=calc_Precio(punt,dist);
	                    }else if(flag==-1){
	                        printf(" > Usuario no registrado... Regístrese antes de iniciar sesion.\n");
	                        Sleep(3000);
	                    }
	                	break;
	
	            	case 2:
	            		printf ("\n > Introduce el pin secreto de la empresa:\n");
	                   	scanf("%i",&pin);
	                   	system("cls");
	                   	
	            	if (pin!=P)
					{
						do
						{
	               			{    
	               				printf(" Pin incorrecto. Te quedan %i intentos.",contador);
	               				printf ("\n > Introduce el pin secreto de la empresa:\n");
	                   			scanf("%i",&pin);
	                   			system("cls");
	               				contador++;
	               				Sleep(2000);
							}
	                	}
	                	while ((pin!=P)&&(contador>=1));
	                }
	                	if (pin == P)
						{
	                        FILE *file=fopen("Distancias.txt","a"); //ruta en nuestro pc del archivo al que queremos anadir texto
	                        // Ruta en nuestro pc del archivo al que queremos anadir texto
	
	                        if(file == NULL)
	                        {
	                            printf(" Error al intentar abrir el archivo");
	                            return -1;
	                        }
							else
							{
	                            do
								{
		                            system("cls");
		                            printf("\n > Elija una operacion:\n\n\n\t 1) Rutas disponibles\n\n\t 2) Nueva ruta\n\n\t");
		                            printf(" 3) Precios actuales\n\n\t 4) Modificar precios\n\n\t 5) Resetear rutas\n\n\t 6) Salir\n");
		                        scanf ("%i",&b);
		                        fflush(stdin);
			                        switch (b)
			                        {
			                            case 1:
			                            	
			                            break;
			                            
			                            case 2:
			                            	new_Ruta(file,r);
			                            break;
			                            
			                            case 3:
			                                precios_Act(punt2);
			                            break;
			                            
			                            case 4:
			                            	modif_Precio(punt);
			                            break;
			                            
			                            case 5:
			                            	
			                            break;
			                            default:
											flag=1;
			                            	printf("\n Hasta la proxima");
			                        }
		                        }while(flag!=1);
	                        }
	                	}
	                	
						else if(contador<1)
						{
	                        printf("\n > Por motivos de seguridad sera redirigido al menu de inicio\n");
	                        Sleep(3000);
	                        contador=2;
	                        break;
	                	}
				}		
	            break;
	            
			case 2:
				new_Id(punt);
	            printf("\n > Estas siendo redirigido al inicio...");
	            Sleep(2000);
	            break;
	        case 3:
	        	system("cls");
	        	printf("\n  >>  Hasta la proxima <<");
	            break;
	        default:
	        	printf(" > Operacion no valida\n");
	        	Sleep(2000);
		}
	} while(a!=3);

	//return 0;
}


