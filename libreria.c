#include "libreria.h"
#include <windows.h>
#include <string.h>

int comp_Str(char *p1,char *p2){
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
int new_Id(FILE *pf){
    char id[20],clave[13],id2[20],s[20],*p1,*p2;
    int flag=1,salida=1,b;
    char x;
    do{
        pf=fopen("usuarios.txt","r");
        if (pf==NULL)
            printf("\n Error al intentar leer el archivo...\n");
        else{
            printf ("\n Escribe tu usuario: ");
            	scanf ("%s",id);
            _strupr(id);
            do{
                fscanf(pf,"%[^;];%[^;];\n",id2,s);
                p1=id;
                p2=id2;
                flag=comp_Str(p1,p2);
            }while (feof(pf)==0&&flag!=1);
            fclose(pf);
            
            if (flag==0){
                printf ("\n Introduzca una contrasena: (de 4 a 12 caracteres)\n");
                fflush(stdin);
                	scanf ("%s",clave);
                _strupr(clave);
                b=strlen(clave);
                
                while (b>12 || b<4)
				{
                    printf ("\n Contrasena no valida. Prueba con otra:\n");
                    	scanf (" %[^\n]",clave);
                    _strupr(clave);
                    b=strlen(clave);
                }
                
                pf=fopen("usuarios.txt","a");
                fprintf(pf,"%s;%s;\n",id,clave);
                fclose (pf);
                system ("cls");
                printf("\n Te has registrado correctamente. Reinicia el programa para hacer efectivo el cambio.\n");
                Sleep(2000);
                salida=0;
            }
            else {
                system("cls");
                printf(" Este nombre de usuario ya existe, pruebe con uno distinto\n");
            }
        }
    }while(salida!=0);
        Sleep(2000);
        return 0;
}
float comp_Ruta(FILE *pf){
    int flag=0,flag2=0;
    Ruta ruta1;
    char Origen[20],Destino[20],*p1,*p2;
    pf=fopen("Distancias.txt","r");
    if (pf==NULL)
        printf("\n Error al intentar leer el archivo...\n");
    else{
        printf("\n Introduzca el origen de su viaje:\n");
        	scanf("%[^\n]",Origen);
        _strupr(Origen);
        printf("\n Introduzca el destino de su viaje:\n");
        fflush(stdin);
        	scanf("%[^\n]",Destino);
        _strupr(Destino);
        //EN ESTE BUCLE WHILE SE VA BUSCANDO QUE Ruta1.Origen COINCIDA CON EL ORIGEN INTRODUCIDO POR EL USUARIO
        while (feof(pf)==0&&(flag!=1||flag2!=1)){
            fscanf(pf,"%[^;];%[^;];%f\n",ruta1.Origen,ruta1.Destino,&ruta1.Distancia);
            //SE USAN LOS PUNTEROS HACIA LOS DOS STRINGS ANTES MENCIONADOS PARA QUE LA FUNCION COMPROBAR_USUARIO COMPRUEBEN
            // SI SON EL MISMO STRING O NO
            p1=Origen;
            p2=ruta1.Origen;
            flag=comp_Str(p1,p2);
            //SI FLAG VALE UNO, LOS STRING SON IGUALES; POR TANTO COMPROBAMOS SI EL DESTINO TAMBIEN COINCIDE
            if (flag==1){
                system("cls");
                p1=Destino;
                p2=ruta1.Destino;
                flag2=comp_Str(p1,p2);
            }
        }
        fclose(pf);
        if (flag!=1||flag2!=1){
            printf("\n Esta ruta no esta en nuestra base de datos...\n");
            Sleep(2000);
            return -1;
        }
        else {
         return ruta1.Distancia;
        }
    }

}
int log_In(FILE *pf){
    char *p1,*p2,id[20],clave[20],id2[20],clave2[20];
    int flag,flag2,contador=0;
    do{
        flag=0;
        flag2=0;
        pf=fopen("usuarios.txt","r");
        if(pf==NULL)
            printf(" Error al intentar leer el archivo");
        else {
            printf("\n Introduzca su usuario:");
            scanf("%s",id);
            _strupr(id);
            fflush(stdin);
            printf("\n Introduzca su clave:");
            scanf("%s",clave);
            _strupr(clave);
            fflush(stdin);
            do{
                fscanf(pf,"%[^;];%[^;];\n",id2,clave2);
                p1=id;
                p2=id2;
                flag=comp_Str(p1,p2);
                }
            while(feof(pf)==0&&flag!=1);
            fclose(pf);
            if (flag==1){
                p1=clave;
                p2=clave2;
                flag2=comp_Str(p1,p2);
                if(flag2!=1){
                    contador++;
                    printf("\n\n La clave es incorrecta. Le quedan %i intentos.\n",3-contador);
                }
            }
            else{
                contador++;
                printf("\n\n El usuario es incorrecto. Le quedan %i intentos.\n",3-contador);
            }
        }
    }while (contador<3&&(flag!=1&&flag2!=1));
    if (flag==1&&flag2==1){
        return 1;
    }else{
        return -1;
    }
}

int new_Ruta(FILE *pf,Ruta r){
    printf("\n Introduce el origen: ");
    scanf("%s", &r.Origen);
    _strupr (r.Origen);
    printf("\n Introduce el destino: ");
    scanf("%s", &r.Destino);
    _strupr (r.Destino);
    printf("\n Introduce la distancia: ");
    scanf("%f", &r.Distancia);
    fprintf(pf, "\n%s;%s;%f", r.Origen, r.Destino, r.Distancia);
    fclose(pf);
    printf("\n > Rutas anadidas correctamente.\n\n");
    Sleep(2000);
}

float calc_Precio (FILE *pf,float dist){
    int a;
    float precio,premium,km,noche;
    pf=fopen("precios.txt","r");
    fscanf(pf,"%f;%f;%f;",&km,&noche,&premium);
    fclose(pf);
    do{
        fflush(stdin);
        printf("\n Horario del viaje:\n\n\t 1) Diurno \n\n\t 2) Nocturno \n\t");
        scanf("%i",&a);
        if (a==2)
            precio=dist*noche;
    }while(a!=1&&a!=2);
    do{
        printf("\n Desea tener el servicio premium (wifi, asiento reclinable,etc):\n\n\t 1) Si \n\n\t 2) No\n\t");
        scanf("%i",&a);
        fflush(stdin);
        if (a==1)
            precio+=dist*premium;
    }while(a!=1&&a!=2);
    precio+=dist*km;
    printf("\n El precio final de tu viaje seria de %g euros.",precio);
    Sleep(5000);
    return precio;
}

void modif_Precio(FILE *pf){
    float km,premium,noche;
    pf=fopen("precios.txt","w");
    if(pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO");
    else{
        system("cls");
        printf("\n\t Introduzca el nuevo precio por kilometraje:");
        	scanf("%f",&km);
        fflush(stdin);
        printf("\n\t Introduzca el nuevo precio por el servicio nocturno:");
        	scanf("%f",&noche);
        fflush(stdin);
        printf("\n\t Introduzca el nuevo precio por el servicio premium:");
        	scanf("%f",&premium);
        fflush(stdin);
        fprintf(pf,"\t%f;%f;%f;",km,noche,premium);
        fclose(pf);
        system("cls");
        printf("\n Operacion realizada con exito. Reinicie el programa para hacer efectivos los cambios.");
    }
}

void precios_Act(FILE *pf){
	double km, noche, prem;
	system("cls");
	pf = open("precios.txt","r");
	if(pf=NULL){
		printf("\n Error al intentar leer el archivo...\n");
	}else{
		fscanf(pf,"%f;%f;%f", &km, &noche, &prem);
		fclose(pf);
	
		printf("\n > Listado de precios:");
		printf("\n\n\n\t- Kilometro: %d euros",km);
		printf("\n\n\t- Servicio nocturno: %d euros",noche);
		printf("\n\n\t- Clase premium: %d euros",prem);
		printf("\n\n\n Pulsa cualquier tecla para volver atras...");
		getch();
	}
	
}
