#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
struct Fecha{
    int dia;
    int mes;
    int anio;
};
struct paciente{
   char ApeNom[60];
   char Domicilio[60];
   int DniPaciente;
   char Localidad[60];
   Fecha fecha;
   char Telefono[25];
   bool borrado;
};
struct turno{
    int idProfecional;
    Fecha fecha;
    int DniPaciente;
    char DetallePaciente[380];
    bool borrado;
};  
struct usuario{
    char mail[100];
    char cont[10];
};
struct profesional{
    char ApeNom[60];
    int idProfesional;
    int Dni;
    char telefono[25];
    bool borrado;
};
//MENU
int menu(void){
    system("cls");
    int N;
    printf("\n1.- Registrar Profesionales");
    printf("\n2.- Registrar Usuario Recepcionista");
    printf("\n3.- Atenciones por Profesional");
    printf("\n4.- Ranking de Profesionales por Atenciones");
    printf("\n5.- Cerrar la aplicacion.");
    printf("\n\nIngrese una opcion: ");
    scanf("%d", &N);
    return N;
}
//Registro de Profesionales
FILE *profesionales;
profesional prof;
void regprof(FILE *profesionales, profesional prof){
    char c,r;
    system("cls");
    profesionales=fopen("Profesionales.dat", "r+b");
    if(profesionales==NULL){
        printf("El archivo Profesionales no existe..");
        printf("\nDesea crear el archivo? (S/N):  "); 
        c=getch();
        if(c=='s'||c=='S'){
            profesionales=fopen("Profesionales.dat","w+b");
            printf("\nARCHIVO CREADO\n");
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        profesionales=fopen("Profesionales.dat","a+b");
    }
        system("pause");
        system("cls");
    if(profesionales!=NULL){
        _flushall();
    do{
	    printf("Ingrese los datos del Profesional:\n\n");
        printf("Apellido y Nombre:");
        gets(prof.ApeNom);
        printf("\nID de profesional:");
        scanf("%d",&prof.idProfesional);
        printf("\nDNI:");
        scanf("%d",&prof.Dni);
        printf("Telefono de Contacto:");
        scanf("%d",&prof.telefono);
        prof.borrado=false;
        fwrite(&prof,sizeof(profesional),1,profesionales);
        system("CLS");
        printf("Profesional Registrado...");
        printf("\nDesea continuar el registro de otro profesional? (S/N)");
        r=getch();
    }while(r=='s' || r=='S');

    }
    fclose(profesionales);
}
//Registro de Recepcionistas
FILE *recepcionistas;
profesional rec;
void recepcion(FILE *recepcionistas, profesional rec){
    char c;
    system("cls");
    recepcionistas=fopen("Recepcionistas.dat", "r+b");
    if(recepcionistas==NULL){
        printf("El archivo Recepcionistas no existe..");
        printf("\nDesea crear el archivo? (S/N):  "); 
        c=getch();
        if(c=='s'||c=='S'){
            recepcionistas=fopen("Recepcionistas.dat","w+b");
            printf("\nARCHIVO CREADO\n");
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        recepcionistas=fopen("Recepcionistas.dat","a+b");
    }
}