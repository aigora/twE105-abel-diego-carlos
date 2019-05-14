#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define P 123456
// P es el pin para acceder al menu como trabajador de la empresa

typedef struct {
    char id[20];
    char clave[20];
}usuario;
typedef struct // Nuevas rutas
{
	char Origen[20];
	char Destino[20];
	float Distancia;
} Ruta;
int nuevousuario(FILE *pf);
int comprobar_usuario(char *p1,char *p2);
float comprobar_ruta(FILE *pf);
int iniciar_sesion(FILE *pf);
int nueva_ruta(FILE *pf,Ruta r);
float calcularprecio (FILE *pf,float distancia);
void modificar_precios(FILE *pf);


void main()
{
	int a, b, c, flag, contador = 0, salida, pin, aux = 0;
	float distancia,precio;
	char id[20],clave[20];
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
                	do{
                	printf ("\n Introduce el pin secreto de la empresa: ");
                    scanf("%i",&pin);
                    system("cls");
                    if(pin != P)
               			{
               				printf("El pin es incorrecto\tRecuerda que solo tienes tres intentos\n");
               				contador++;
               				Sleep(4000);
						}
                    if(pin ==P)
                        contador+=4;
                	}while (contador<4);
                	if (contador>=4){
                        FILE *file=fopen("Distancias.txt","a"); //ruta en nuestro pc del archivo al que queremos anadir texto
                        // Ruta en nuestro pc del archivo al que queremos anadir texto

                        if(file == NULL)
                        {
                            printf("Error al abrir el archivo");
                            return 0;
                        }else{
                            do{
                                system("cls");
                                printf("Que desea hacer? 1.Introducir nueva ruta\t 2.Modificar precios\t 3.Salir");
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
                            }while(flag!=1);
                        }
                	}else if(contador==3){
                        printf("Por motivos de seguridad seras redirigido al menu de inicio\n");
                        Sleep(3000);
                        break;
                	}
                	Sleep(2000);
			}
                    break;

		case 2:
			nuevousuario(puntero);
            printf("\n AUN EN MANTENIMIENTO");
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
    int flag,i,b;
    char x;
    pf=fopen("usuarios.txt","a");
    if (pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    else{
        printf ("Si desea salir pulse 0, para continuar pulse 1 \n");
        scanf("%i",&flag);
        if (flag!=0){
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
            fprintf(pf,"%s;%s;\n",id,contrasenna);
            fclose (pf);
            system ("cls");
            printf("ESCRITURA REALIZADA CON EXITO");
        }
        Sleep(2000);
        return 0;
    }
}
float comprobar_ruta(FILE *pf){
    int flag=0,flag2=0;
    Ruta ruta1;
    char Origen[20],Destino[20],*p1,*p2;
    pf=fopen("Distancias.txt","r");
    if (pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO");
    else{
        printf("Introduzca el origen de su viaje:");
        scanf("%[^\n]",Origen);
        printf("\nIntroduzca el destino de su viaje:");
        fflush(stdin);
        scanf("%[^\n]",Destino);
        //EN ESTE BUCLE WHILE SE VA BUSCANDO QUE Ruta1.Origen COINCIDA CON EL ORIGEN INTRODUCIDO POR EL USUARIO
        while (feof(pf)==0&&(flag!=1||flag2!=1)){
            fscanf(pf,"%[^;];%[^;];%f\n",ruta1.Origen,ruta1.Destino,&ruta1.Distancia);
            //SE USAN LOS PUNTEROS HACIA LOS DOS STRINGS ANTES MENCIONADOS PARA QUE LA FUNCION COMPROBAR_USUARIO COMPRUEBEN
            // SI SON EL MISMO STRING O NO
            p1=Origen;
            p2=ruta1.Origen;
            flag=comprobar_usuario(p1,p2);
            //SI FLAG VALE UNO, LOS STRING SON IGUALES; POR TANTO COMPROBAMOS SI EL DESTINO TAMBIEN COINCIDE
            if (flag==1){
                system("cls");
                printf("\nCOMPROBANDO DESTINO...");
                p1=Destino;
                p2=ruta1.Destino;
                flag2=comprobar_usuario(p1,p2);
            }
        }
        fclose(pf);
        if (flag!=1||flag2!=1){
            printf("LA RUTA NO ESTA EN NUESTRA BASE DE DATOS\n");
            Sleep(2000);
            return -1;
        }
        else {
         return ruta1.Distancia;
        }

    }

}
int iniciar_sesion(FILE *pf){
    usuario user1;
    int flag=0,flag2=0,contador=0;
    char id[20],clave[20],*p1,*p2;
    pf=fopen("usuarios.txt","r");
    if(pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO");
    else{
        do{
        if (contador!=0)
            printf("\n Usuario o contraseña incorrectos.\n Trate de iniciar sesion de nuevo\n");
        printf("\n Usuario: ");
        scanf(" %[^\n]",id);
        fflush(stdin);
        printf("\n Clave: ");
        scanf("%[^\n]",clave);
        fflush(stdin);
        contador++;
        while (feof(pf)==0&&(flag!=1||flag2!=1)){
            fscanf(pf,"%[^;];%[^;];\n)",user1.id,user1.clave);
            p1=id;
            p2=user1.id;
            flag=comprobar_usuario(p1,p2);
            if (flag==1){
                p1=clave;
                p2=user1.clave;
                flag2=comprobar_usuario(p1,p2);
            }

        }
        }while (flag==0 && flag2==0 && contador<4);
        fclose(pf);
        if(flag==1&&flag2==1){
            return 1;
        }else if(flag!=1){
            printf("Quizas no esta registrado, trate de registrarse antes de iniciar sesion\n");
            return -1;
        }else if(flag2!=1){
            printf("La contraseña es incorrecta, pruebe de nuevo o registrese antes de iniciar sesion\n");
            return -1;
        }
}
}
int nueva_ruta(FILE *pf,Ruta r){
    printf("\nIntroduce el origen: ");
    scanf("%s", &r.Origen);
    printf("Introduce el destino: ");
    scanf("%s", &r.Destino);
    printf("Introduce la distancia: ");
    scanf("%f", &r.Distancia);
    fprintf(pf, "\n%s;%s;%f", r.Origen, r.Destino, r.Distancia);
    fclose(pf);
    printf("\nRutas añadidas correctamente.\n\n");
    Sleep(2000);
}
    float calcularprecio (FILE *pf,float distancia){
        int a;
        float precio,premium,km,noche;
        pf=fopen("precios.txt","r");
        fscanf(pf,"%f;%f;%f;",&km,&noche,&premium);
        printf("%f;%f;%f",km,noche,premium);
        fclose(pf);
        do{
            fflush(stdin);
            printf("Va a realizar el viaje de noche?\n 1.SI\t2.NO:");
            scanf("%i",&a);
            if (a==1)
                precio=distancia*noche;
        }while(a!=1&&a!=2);
        do{
            printf("Desea tener el servicio premium (cargador,conexion a Internet,etc) en su viaje:\n 1.SI\t 2.NO:");
            scanf("%i",&a);
            fflush(stdin);
            if (a==1)
                precio+=distancia*premium;
        }while(a!=1&&a!=2);
        precio+=distancia*km;
        printf("El precio final de tu viaje seria de %f",precio);
        Sleep(5000);
        return precio;
}
void modificar_precios(FILE *pf){
    float km,premium,noche;
    pf=fopen("precios.txt","w");
    if(pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO");
    else{
        system("cls");
        printf("\nIntroduzca el nuevo precio por kilometraje:");
        scanf("%f",&km);
        fflush(stdin);
        printf("\n Introduzca el nuevo precio por el servicio nocturno:");
        scanf("%f",&noche);
        fflush(stdin);
        printf("\n Introduzca el nuevo precio por el servicio premium:");
        scanf("%f",&premium);
        fflush(stdin);
        fprintf(pf,"%f;%f;%f;",km,noche,premium);
        fclose(pf);
        system("cls");
        printf("ACTUALIZACION DE LOS PRECIOS REALIZADA CON EXITO");
    }
}
