#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char loggin[50],pn[50],sn[50],am[50],ap[50];
int id_user,tipo_log,tipoadmin=56,tipoalumno=1,tipoprofesor=2,logueado=0;

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
void blancos(int cantidad);
void lineas(int cantidad);
void generar_menu();
void generar_archivos();
void ingresar_cursos(int tip);
void eliminar_cursos(int tip);
void ingresar_usuarios(int tip);
void ingresar_alumnos(int tip);
void mis_notas(int tip);
void check_cursos(int tip);
void borrar_alumno(int tip);
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
        case 105: borrar_alumno(tipo_log);break;
        case 201: check_cursos(tipo_log);break;
        case 10: mis_notas(tipo_log);break;
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
printf("\n      (101) Ingresar Usuarios");
printf("\n      (102) Ingresar Cursos");
printf("\n      (103) Eliminar Cursos");
printf("\n      (104) Ingresar Alumnos");
printf("\n      (105) Borrar Alumno");
}
if(tipo_log==tipoprofesor){
printf("\n      (201) Curso");
}
if(tipo_log==tipoalumno){
printf("\n      (10 ) Mis Calificaciones");
}
printf("\n      (20 ) Salir\n");
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
				strcpy(loggin,aux.login);
				strcpy(pn,aux.primer_nombre);
				strcpy(sn,aux.segundo_nombre);
				strcpy(ap,aux.apellido_paterno);
				strcpy(am,aux.apellido_materno);
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
}
void ingresar_usuarios(int tip){
	if(tip!=tipoadmin){
	no();
	return;
	}
	struct Usuarios user,aux;
	FILE *p,*fichero;
	int num=0,id=0i,tipos;
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
	printf("Ingrese primer nombre:> ");
	scanf( "%s", user.primer_nombre );
	printf("Ingrese segundo nombre:> ");
	scanf( "%s", user.segundo_nombre );
	printf("Ingrese primer apellido:> ");
	scanf( "%s", user.apellido_paterno );
	printf("Ingrese segundo apellido:> ");
	scanf( "%s", user.apellido_materno );
	printf("ingrese el tipo de usuario:\n");
	printf("1) profesor.\n");
	printf("2) alumno\n");
	scanf("%d",&tipos);
	if(tipos==1){
	user.tipo=tipoprofesor;
	}
	if(tipos==2){
	user.tipo=tipoalumno;
	}
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
struct Alumnos alumno,aux;
FILE *fichero;
char codigo[5];
int id=0,existe=0;
struct Cursos auxs;
printf("Ingresar codigo del curso:");
scanf("%s",codigo);
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &auxs, sizeof(struct Cursos), 1, fichero )){
		     	if(strcmp(auxs.codigo,codigo)==0){
			existe=1;
			}
	     }
       }
fclose(fichero);
if(existe==0){
printf("el curso %s no existe\n",codigo);
return;
}
printf("Ingrese el primer nombre\n");
scanf("%s",alumno.primer_nombre);
printf("Ingrese el segundo nombre\n");
scanf("%s",alumno.segundo_nombre);
printf("Ingrese el apellido paterno\n");
scanf("%s",alumno.apellido_paterno);
printf("Ingrese el apellido materno\n");
scanf("%s",alumno.apellido_materno);
alumno.c1=0;
alumno.c2=0;
alumno.c3=0;
alumno.c4=0;
alumno.examen=0;
alumno.final=0;
fichero = fopen(codigo,"r");
       while (!feof(fichero)){
	     if (fread( &aux, sizeof(struct Alumnos), 1, fichero )){
		     id=aux.id;
		     	if(strcmp(aux.primer_nombre,alumno.primer_nombre)==0 && strcmp(aux.segundo_nombre,alumno.segundo_nombre)==0 && strcmp(aux.apellido_paterno,alumno.apellido_paterno)==0 && strcmp(aux.apellido_materno,alumno.apellido_materno)==0){
			printf("El alumno ya existe en este curso\n");
			return;
			}
	     }
       }

fclose(fichero);
alumno.id=id+1;
printf("\nflag1\n");
fichero=fopen(codigo,"a");
fwrite(&alumno, sizeof(struct Alumnos), 1, fichero);
fclose(fichero);
return;
}
void mis_notas(int tip){
	if(tip!=tipoalumno){
	no();
	return;
	}
FILE *fichero;
char codigo[5],nombre[203],rgnombre[203];
int check,existe=0;
struct Alumnos aux;
struct Cursos auxs;
printf("Ingresar codigo del curso:");
scanf("%s",codigo);
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &auxs, sizeof(struct Cursos), 1, fichero )){
		     	if(strcmp(auxs.codigo,codigo)==0){
			existe=1;
			}
	     }
       }
fclose(fichero);
if(existe==0){
printf("el curso %s no existe\n",codigo);
return;
}
				strcpy(rgnombre,"");
			        strcat(rgnombre,pn);
				strcat(rgnombre,sn);
				strcat(rgnombre,ap);
				strcat(rgnombre,am);
fichero = fopen(codigo,"r");
       while (!feof(fichero)){
	     if (fread( &aux, sizeof(struct Alumnos), 1, fichero )){
				strcpy(nombre,"");
			        strcat(nombre,aux.primer_nombre);
				strcat(nombre,aux.segundo_nombre);
				strcat(nombre,aux.apellido_paterno);
				strcat(nombre,aux.apellido_materno);
                                printf("1-%s\n",nombre);
		if(strcmp(nombre,rgnombre)==0){
		printf("Asignatura:%s\n",codigo);	
		printf("C1:%d\n",aux.c1);
		printf("C2:%d\n",aux.c2);
		printf("C3:%d\n",aux.c3);
		printf("C4:%d\n",aux.c4);
		printf("Examen:%d\n",aux.examen);
		printf("Promedio Final:%d\n",aux.examen);
		return;
}
}
}
printf("No existes en este curso\n");
return;
}
void check_cursos(int tip){
	if(tip!=tipoprofesor){
	no();
	return;
	}
FILE *fichero,*copia;
char codigo[5],nombre[203],rgnombre[203],id[5];
int check,existe=0,largo=0,reg,tiponota,nota;
struct Alumnos aux,registro;
struct Cursos auxs;
				strcpy(rgnombre,"");
				strcpy(nombre,"");
			        strcat(rgnombre,pn);
				strcpy(rgnombre," ");
				strcat(rgnombre,sn);
				strcpy(rgnombre," ");
				strcat(rgnombre,ap);
				strcpy(rgnombre," ");
				strcat(rgnombre,am);
printf("Ingresar codigo del curso:");
scanf("%s",codigo);
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &auxs, sizeof(struct Cursos), 1, fichero )){
		     	if(strcmp(auxs.codigo,codigo)==0){
			existe=1;
			strcpy(nombre,auxs.profesor);
			}
	     }
       }
fclose(fichero);
if(strcmp(nombre,rgnombre)!=0){
printf("NO eres profesor de este curso\n");
return;
}
if(existe==0){
printf("el curso %s no existe\n",codigo);
return;
}
printf("\n");
lineas(211);
printf("\n");
printf("| id ");
printf("| Nombre Completo");
blancos(188);
printf("|\n");
lineas(211);
printf("\n");
fichero=fopen(codigo,"r");
while (!feof(fichero)){
	               if (fread( &aux, sizeof(struct Alumnos), 1, fichero )){
			sprintf(id, "%d", aux.id);
			printf("| ");
			printf("%s",id);
			blancos(3-strlen(id));
			printf("| ");
				strcpy(nombre,"");
			        strcat(nombre,aux.primer_nombre);
				strcat(nombre," ");
				strcat(nombre,aux.segundo_nombre);
				strcat(nombre," ");
				strcat(nombre,aux.apellido_paterno);
				strcat(nombre," ");
				strcat(nombre,aux.apellido_materno);
				printf("%s",nombre);
	  			largo=204-strlen(nombre);
				blancos(largo-1);
				printf("|\n");
				lineas(211);
				printf("\n");		
			      }
			}

fclose(fichero);
printf("\nIngrese el id del alumno a modifcar:\n");
scanf("%d",&reg);
printf("Ingrese la calificacion:\n");
scanf("%d",&nota);
printf("Cual es la calificacion que desea ingresar:\n");
printf("1.- C1:\n");
printf("2.- C2:\n");
printf("3.- C3:\n");
printf("4.- C4:\n");
printf("5.- Examen:\n");
printf("6.- Promedio Final\n");
scanf("%d",&tiponota);
fichero = fopen(codigo, "r" );
copia=fopen( "aux","a");
while (!feof(fichero)){
               if (fread( &registro, sizeof(Alumnos), 1, fichero ))
                {
                if(registro.id!=reg){
                        fwrite(&registro, sizeof(struct Alumnos), 1, copia);
                }else{		
                 switch(tiponota){
       			case 1: registro.c1=nota;break;
        		case 2: registro.c2=nota;break;
        		case 3: registro.c3=nota;break;
        		case 4: registro.c4=nota;break;
        		case 5: registro.examen=nota;break;
        		case 6: registro.final=nota;break;
		 }		
                        fwrite(&registro, sizeof(struct Alumnos), 1, copia);
}}}

fclose( fichero );
fclose( copia );
remove(codigo);
rename("aux",codigo);
fichero = fopen(codigo,"r");
       while (!feof(fichero)){
	     if (fread( &aux, sizeof(struct Alumnos), 1, fichero )){
		if(reg==aux.id){
		printf("\nLas calificaciones del alumno son las siguientes:\n");	
		printf("C1:%d\n",aux.c1);
		printf("C2:%d\n",aux.c2);
		printf("C3:%d\n",aux.c3);
		printf("C4:%d\n",aux.c4);
		printf("Examen:%d\n",aux.examen);
		printf("Promedio Final:%d\n",aux.final);
		return;
}}}
return; 
}
void blancos(int cantidad){
 for(int x=0;x<cantidad;x+=1)
 printf(" ");
}
void lineas(int cantidad){
 for(int x=0;x<cantidad;x+=1)
 printf("-");
}
void borrar_alumno(int tip){
	if(tip!=tipoadmin){
	no();
	return;
	}
FILE *fichero,*copia;
char codigo[5],nombre[203],id[5];
int check,existe=0,largo=0,reg,i=0;
struct Alumnos aux,registro;
struct Cursos auxs;
printf("Ingresar codigo del curso:");
scanf("%s",codigo);
fichero = fopen("Cursos.dat","r");
       while (!feof(fichero)){
	     if (fread( &auxs, sizeof(struct Cursos), 1, fichero )){
		     	if(strcmp(auxs.codigo,codigo)==0){
			existe=1;
			}
	     }
       }
fclose(fichero);
if(existe==0){
printf("el curso %s no existe\n",codigo);
return;
}
printf("\n");
lineas(211);
printf("\n");
printf("| id ");
printf("| Nombre Completo");
blancos(188);
printf("|\n");
lineas(211);
printf("\n");
fichero=fopen(codigo,"r");
while (!feof(fichero)){
	               if (fread( &aux, sizeof(struct Alumnos), 1, fichero )){
			sprintf(id, "%d", aux.id);
			printf("| ");
			printf("%s",id);
			blancos(3-strlen(id));
			printf("| ");
				strcpy(nombre,"");
			        strcat(nombre,aux.primer_nombre);
				strcat(nombre," ");
				strcat(nombre,aux.segundo_nombre);
				strcat(nombre," ");
				strcat(nombre,aux.apellido_paterno);
				strcat(nombre," ");
				strcat(nombre,aux.apellido_materno);
				printf("%s",nombre);
	  			largo=204-strlen(nombre);
				blancos(largo-1);
				printf("|\n");
				lineas(211);
				printf("\n");		
			      }
			}

fclose(fichero);
printf("\nIngrese el id del alumno a borrar:\n");
scanf("%d",&reg);
fichero = fopen(codigo, "r" );
copia=fopen( "aux","a");
while (!feof(fichero)){
               if (fread( &registro, sizeof(Alumnos), 1, fichero ))
                {
                if(registro.id!=reg){
			i=i+1;
			registro.id=i;
                        fwrite(&registro, sizeof(struct Alumnos), 1, copia);
                }
}}

fclose( fichero );
fclose( copia );
remove(codigo);
rename("aux",codigo);
}
