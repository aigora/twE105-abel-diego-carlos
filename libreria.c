#include "libreria.h"
#include <windows.h>
#include <string.h>

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
    char id[20],contrasenna[20],id2[20],s[20],*p1,*p2;
    int flag,flag2=1,salida=1,b;
    char x;
    do{
        pf=fopen("usuarios.txt","r");
        if (pf==NULL)
            printf("ERROR AL ABRIR EL ARCHIVO\n");
        else{
            printf ("\n  Si desea salir pulse 0, para continuar pulse 1 \n");
            scanf("%i",&flag);
            fflush(stdin);
            if (flag==1){
                printf ("  Escribe tu usuario: ");
                scanf ("%s",id);
                _strupr(id);
                do{
                    fscanf(pf,"%[^;];%[^;];\n",id2,s);
                    p1=id;
                    p2=id2;
                    flag2=comprobar_usuario(p1,p2);
                }while (feof(pf)==0&&flag2!=1);
                fclose(pf);
                if (flag2==0){
                    printf ("\n  Introduzca una contrasena: ");
                    fflush(stdin);
                    scanf ("%s",contrasenna);
                    b=strlen(contrasenna);
                    while (b>20 || b<4){
                        printf ("  Error en la contrasena, introducela de nuevo: \n");
                        scanf (" %[^\n]",contrasenna);
                        b=strlen(contrasenna);
                    }
                    pf=fopen("usuarios.txt","a");
                    fprintf(pf,"%s;%s;\n",id,contrasenna);
                    fclose (pf);
                    system ("cls");
                    printf("  ESCRITURA REALIZADA CON EXITO...");
                    salida=0;
                }
                else {
                    system("cls");
                    printf("  Este usuario ya esta registrado, pruebe con un usuario distinto\n");
                }
        	}
        }
    } while(flag !=0 && salida!=0);
        Sleep(1000);
        return 0;
}
float comprobar_ruta(FILE *pf){
    int flag=0,flag2=0;
    Ruta ruta1;
    char Origen[20],Destino[20],*p1,*p2;
    pf=fopen("Distancias.txt","r");
    if (pf==NULL)
        printf("  ERROR AL ABRIR EL ARCHIVO...");
    else{
        printf("  Introduzca el origen de su viaje:");
        	scanf("%[^\n]",Origen);
        _strupr(Origen);
        printf("\n\n  Introduzca el destino de su viaje:");
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
            flag=comprobar_usuario(p1,p2);
            //SI FLAG VALE UNO, LOS STRING SON IGUALES; POR TANTO COMPROBAMOS SI EL DESTINO TAMBIEN COINCIDE
            if (flag==1){
                system("cls");
                printf("\n  COMPROBANDO DESTINO...");
                p1=Destino;
                p2=ruta1.Destino;
                flag2=comprobar_usuario(p1,p2);
            }
        }
        fclose(pf);
        if (flag!=1||flag2!=1){
            printf("\n  LA RUTA NO ESTA EN NUESTRA BASE DE DATOS...");
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
        printf("  ERROR AL ABRIR EL ARCHIVO...");
    else{
        do{
	        if (contador!=0)
	            printf("\n  Usuario o contrasena incorrectos...\t Trate de iniciar sesion de nuevo\n");
	        printf("\n  Usuario: ");
	        	scanf(" %[^\n]",id);
	        _strupr(id);
	        	fflush(stdin);
	        printf("\n  Clave: ");
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
            printf("  Quizas no esta registrado...\t Registrese antes de iniciar sesion\n");
            return -1;
        }else if(flag2!=1){
            printf("  La contraseña es incorrecta...\t Pruebe de nuevo o registrese antes de iniciar sesion\n");
            return -1;
        }
	}
}

int nueva_ruta(FILE *pf,Ruta r){
    printf("\n  Introduce el origen: ");
    	scanf("%s", &r.Origen);
    _strupr (r.Origen);
    printf("  Introduce el destino: ");
    	scanf("%s", &r.Destino);
    _strupr (r.Destino);
    printf("  Introduce la distancia: ");
    	scanf("%f", &r.Distancia);
    fprintf(pf, "\n%s;%s;%f", r.Origen, r.Destino, r.Distancia);
    fclose(pf);
    printf("\n  Rutas anadidas correctamente...\n\n");
    Sleep(2000);
}
    float calcularprecio (FILE *pf,float distancia){
        int a;
        float precio,premium,km,noche;
        pf=fopen("precios.txt","r");
        fscanf(pf,"%f;%f;%f;",&km,&noche,&premium);
        fclose(pf);
        
        do{
            	fflush(stdin);
            printf("\n  Va a realizar el viaje de noche?\n  (1)Si | (2)No:");
            	scanf("%i",&a);
            if (a==1)
                precio=distancia*noche;
        }while(a!=1 && a!=2);
        
        do{
            printf("\n  Desea tener el servicio premium (cargador,conexion a Internet,etc) en su viaje:\n (1)Si | (2)No ");
            	scanf("%i",&a);
            	fflush(stdin);
            if (a==1)
                precio+=distancia*premium;
        }while(a!=1 && a!=2);
        
        precio+=distancia*km;
        printf("\n  El precio final de tu viaje seria de %f €",precio);
        Sleep(5000);
        return precio;
}
void modificar_precios(FILE *pf){
    float km,premium,noche;
    pf=fopen("precios.txt","w");
    
    if(pf==NULL)
        printf("ERROR AL ABRIR EL ARCHIVO...");
    else{
        system("cls");
        printf("\n  Introduzca el nuevo precio por kilometro (Actual = %f): ",km);
        	scanf("%f",&km);
        	fflush(stdin);
        printf("\n  Introduzca el nuevo precio por el servicio nocturno (Actual = %f): ",noche);
        	scanf("%f",&noche);
        	fflush(stdin);
        printf("\n  Introduzca el nuevo precio por el servicio premium (Actual = %f): ",premium);
        	scanf("%f",&premium);
        	fflush(stdin);
        fprintf(pf,"%f;%f;%f;",km,noche,premium);
        fclose(pf);
        system("cls");
        printf("  ACTUALIZACION DE LOS PRECIOS REALIZADA CON EXITO...");
    }
}
