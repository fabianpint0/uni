#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char loggin[50],pn[50],sn[50],am[50],ap[50];
int id_user,tipo_log,tipoadmin=56,logueado=0;

struct Cursos{
int id;
char curso[50];
char codigo[5];
char profesor[50];
};

struct Alumnos{
int id;
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
void no();
void generar_menu();
void generar_archivos();
void ingresar_cursos(int tip);
void eliminar_cursos(int tip);
void ingresar_usuarios(int tip);
void ingresar_alumnos(int tip);
int check_cursos(char *input);
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
        case 101: ingresar_usuarios(tipo_log);break;
        case 102: ingresar_cursos(tipo_log);break;
        case 103: eliminar_cursos(tipo_log);break;
        case 104: ingresar_alumnos(tipo_log);break;
        case 20: return 0;break;
        }
        }

}
void no(){
printf("\n****NO tiene acceso esta funcion****\n");
};
//generador de menus
void generar_menu(){
printf("\n ====| BIENVENIDO A LA UNIVERSIDAD DISTRITAL |==== \n");
if(tipo_log==tipoadmin){
printf("\n      (101) Ingresar usuarios");
printf("\n      (102) Ingresar Cursos");
printf("\n      (103) Eliminar Cursos");
printf("\n      (104) Ingresar alumnos");
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
printf("*************\n");
if(strcmp(user.login,"a")==0 && strcmp(user.password,"a")==0 ){
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
login();
return;
}
void ingresar_cursos(int tip){
	if(tip!=tipoadmin){
	no();
	return;
	}
struct Cursos curso,aux;
int id=0,existe=0;
FILE *fichero,*p;
printf("Ingrese codigo del curso: ");
scanf( "%s", curso.codigo );
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &aux, sizeof(struct Cursos), 1, fichero )){
			id=aux.id;
		     	if(strcmp(curso.codigo,aux.codigo)==0){
			existe=1;
			}
	     }
       }
       fclose( fichero );
       printf("Existe:%d",existe);
       if(existe==0){
       printf("Ingrese nombre del curso: \n");
       scanf( "%s", curso.curso );
       printf("Ingrese profesor asignado: \n");
       scanf( "%s", curso.profesor );
       p = fopen("Cursos.dat","a");
       curso.id=id+1;
       fwrite(&curso, sizeof(struct Cursos), 1, p);
       fclose(p);
       p = fopen(curso.codigo,"a");
       fclose(p);
       printf("\nEl curso %s es creado con exito\n",curso.curso);
       return;
       }else{
       printf("El curso ya existe en el sistema");
       return;
       }
return;
}
void ingresar_usuarios(int tip){
	if(tip!=tipoadmin){
	no();
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
	       printf("\nUsuario %s es creado con exito\n",user.login);
	       return;
}
void eliminar_cursos(int tip){
	if(tip!=tipoadmin){
	no();
	return;
	}
FILE *fichero,*copia;
char codigo[5];
struct Cursos registro;
        printf("\ningrese el codigo del curso a borrar:");
        scanf("%s",codigo);
        fichero = fopen( "Cursos.dat", "r" );
        copia=fopen( "Cursos2.dat","a");
while (!feof(fichero))
        {
               if (fread( &registro, sizeof(registro), 1, fichero ))
                {
                if(strcmp(registro.codigo,codigo)!=0)
                        {
                        fwrite(&registro, sizeof(struct Cursos), 1, copia);
                        }
        }

fclose( fichero );
fclose( copia );
remove("Cursos.dat");
rename("Cursos2.dat","Cursos.dat");
return;
}
}
void ingresar_alumnos(int tip){
	if(tip!=tipoadmin){
	no();
	return;
	}
struct Alumnos alumno;
char codigo[5];
printf("Ingresar codigo del curso:");
scanf("%s",codigo);
if(check_cursos(codigo)){
printf("El curso no existe en los registro \n");
return;
}
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
return;
}
int check_cursos(char *input){
FILE *fichero;
struct Cursos aux;
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &aux, sizeof(struct Cursos), 1, fichero )){
		     	if(strcmp(aux.codigo,input)==0){
			return 1;
			}
	     }
       }
fclose(fichero);
return 0;
}
