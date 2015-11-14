#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char loggin[50],pn[50],sn[50],am[50],ap[50];
int tipo_log,tipoadmin=56,logueado=0;

struct Materias{
char curso[50];
char codigo[5];
char primer_nombre[50];
char segundo_nombre[50];
char apellido_paterno[50];
char appelido_materno[50];
};

struct Cursos{
char primer_nombre[50];
char segundo_nombre[50];
char apellido_paterno[50];
char apellido_materno[50];
int c1;
int c2;
int c3;
int c4;
int examen;
int final;
};

struct Usuarios{
unsigned long id_usuario;
char login[50];
char password[50];
char primer_nombre[50];
char segundo_nombre[50];
char apellido_paterno[50];
char apellido_materno[50];
int  tipo;
};

void login();
void generar_menu();
void generar_archivos();
void ingresar_usuarios(int tip);
int main(){
        int menu;
	generar_archivos();
        while(1){
	if(logueado==0){
	login();
	}
        generar_menu();
        scanf("%i", &menu);
        switch(menu){
        case 1: ingresar_usuarios(tipo_log);break;
        case 20: return 0;break;
        }
        }

}

//generador de menus
void generar_menu(){
printf("\n BIENVENIDO A LA UNIVERSIDAD DISTRITAL \n");
if(tipo_log==56){
printf("\n      (1) Ingresar usuarios");
}
printf("\n      (20) Salir\n");
printf("\n\n Elija su opcion +---> ");
return;
}
void generar_archivos(){
	        FILE *p,*q,*r,*s;
		p = fopen ("Cursos.dat","a");
		fclose(p);
		q = fopen ("Usuarios.dat","a");
		fclose(q);
		return;
}

void login(){
struct Usuarios user,aux;
FILE *fichero;
printf("\n****LOGIN*****\n");
printf("Ingrese usuario:\n");
scanf( "%s", user.login);
printf("Ingrese password:\n");
scanf( "%s",user.password);
if(strcmp(user.login,"Admin")==0 && strcmp(user.password,"fabian")==0 ){
tipo_log=tipoadmin;
logueado=1;
strcpy(loggin,user.login);
return;
}

fichero = fopen("Usuarios.dat","r");
	while (!feof(fichero)){
	               if (fread( &aux, sizeof(struct Usuarios), 1, fichero )){
			       if(strcmp(aux.login,user.login)==0 && strcmp(aux.password,user.password)==0){
			        tipo_log=aux.tipo;
			      	logueado=1;
				strcpy(loggin,user.login);
				strcpy(pn,user.primer_nombre);
				strcpy(sn,user.segundo_nombre);
				strcpy(ap,user.apellido_paterno);
				strcpy(am,user.apellido_materno);
				return;
			      }
			}
	}
	 fclose( fichero );
}
void ingresar_usuarios(int tip){
	if(tip!=tipoadmin){
	printf("\n****NO tiene acceso esta funcion****\n");
	return;
	}
	struct Usuarios user,aux;
	FILE *p,*fichero;
	int num=0,id=0;
	printf("Ingrese el nombre de usuario:> ");
	scanf( "%s", user.login );
	fichero = fopen("Usuarios.dat","r");
	while (!feof(fichero)){
	               if (fread( &aux, sizeof(struct Usuarios), 1, fichero )){
	                     num=1;
			     id=aux.id_usuario;
			       if(strcmp(aux.login,user.login)==0){
			        printf("El usuario %s ya existe \n",user.login);
			      return;
			      }
			}
	}
	 fclose( fichero );
	printf("id:%d",id);
	printf("Ingrese el password:> ");
	scanf( "%s", user.password );
	printf("Ingrese tipo de usuario:> ");
	scanf( "%d", &user.tipo );
	printf("Ingrese primer nombre:> ");
	scanf( "%s", user.primer_nombre );
	printf("Ingrese segundo nombre:> ");
	scanf( "%s", user.segundo_nombre );
	printf("Ingrese primer apellido:> ");
	scanf( "%s", user.apellido_paterno );
	printf("Ingrese segundo apellido:> ");
	scanf( "%s", user.apellido_materno );
	p = fopen("Usuarios.dat","a");
	       user.id_usuario=id+1;
	       fwrite(&user, sizeof(struct Usuarios), 1, p);
	       fclose(p);
	       printf("Usuario %s es creado con exito\n",user.login);
	       return;
}
