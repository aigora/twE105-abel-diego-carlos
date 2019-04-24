#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    char clave[20];
    
    
}usuario;
int nuevousuario(FILE *pf);
int comprobar_usuario(char *p1,char *p2);

void main()
{
	int a, b, c, flag, contador, salida; 
	char id[20],clave[20];
	char *p1,*p2;
	FILE *puntero;
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
				printf ("\n\t Iniciar sesion como usuario(1) o como empleado(2)?");
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
			nuevousuario(puntero);
            printf("\n AUN EN MANTENIMIENTO");
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
int nuevousuario(FILE *pf){
    char id[20],contrasenna[20];
    int i,b;
    char x;
    pf=fopen("usuarios.txt","a");
    if (pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    else{
        printf ("Escribe tu usuario: ");
        scanf (" %s",id);
        printf ("\n Introduzca una contraseña: ");
        scanf (" %s",contrasenna);
        b=strlen(contrasenna);
        while (b>20 || b<4){
            printf ("Error en la contrasena introducela de nuevo: \n");
            scanf (" %[^\n]",contrasenna);
            b=strlen(contrasenna);
        }
        while (fscanf(pf,"%c",x)!=EOF){
            if (x<='A'||x>='z')
                i=x;
        }
        fprintf(pf,"%i;%s;%s;\n",++i,id,contrasenna);
        fclose (pf);
        system ("cls");
        printf("ESCRITURA REALIZADA CON EXITO");
        Sleep(2000);
        return 0;
    }
}
