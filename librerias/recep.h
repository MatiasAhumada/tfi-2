#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct FechaNacimiento{
    int dia;
    int mes;
    int anio;
};

struct paciente{
   char ApeNom[60];
   char Domicilio[60];
   int DniPaciente;
   char Localidad[60];
   FechaNacimiento Fecha;
   char Telefono[25];
};
    FILE *paci;
    paciente pac;

int menu(void){
    system("cls");
    int N;
    printf("\n1.- Iniciar Sesion");
    printf("\n2.- Registrar Pacientes");
    printf("\n3.- Registrar Turno");
    printf("\n4.- Listado de Atenciones por Profesional y Fecha");
    printf("\n5.- Cerrar la aplicacion.");
    printf("\n\nIngrese una opcion: ");
    scanf("%d", &N);
    return N;
   
}

void pacientes(FILE *paci,paciente pac){
    char respuesta;
    int c;
    system("cls");
    paci=fopen("Pacientes.dat","r+b");
    if(paci==NULL){
        printf("El archivo pacientes no existe");
        printf("\nDesea crear el archivo? (1: SI / 0: NO) "); 
         scanf("%d", &c); _flushall();
        if(c==1){
            paci=fopen("Pacientes.dat","w+b");
            printf("\nARCHIVO CREADO\n");
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        paci=fopen("Pacientes.dat","a+b");
    }
    system("pause");
    system("cls");
    if(paci!=NULL){    
        _flushall();
	printf("Ingrese los datos del Paciente\n\n");
	do{
		printf("\nIngrese Apellido y Nombre: ");
        gets(pac.ApeNom);
		printf("\nIngrese Domicilio de residencia: ");
        gets(pac.Domicilio);
		printf("\nIngrese el DNI del paciente: ");
		scanf("%d",&pac.DniPaciente);_flushall();
		printf("\nIngrese la localidad: ");
        gets(pac.Localidad);
        printf("\nIngrese la Fecha de nacimiento: ");
        printf("\nDia: ");
        scanf("%d", &pac.Fecha.dia); _flushall();
        while(pac.Fecha.dia<=0||pac.Fecha.dia>=31){
            printf("\n DIA INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 30\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.Fecha.dia); _flushall();
        }
        printf("\nMes: ");
        scanf("%d", &pac.Fecha.mes); _flushall();
        while(pac.Fecha.mes<=0||pac.Fecha.mes>=13){
            printf("\n MES INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 12\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.Fecha.mes); _flushall();
        }
        printf("\nAño: ");
        scanf("%d", &pac.Fecha.anio); _flushall();
        while(pac.Fecha.anio<=1900||pac.Fecha.anio>=2025){
            printf("\n AÑO INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1900 y 2024\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.Fecha.anio); _flushall();
        }		
		fwrite(&pac, sizeof(pac), 1, paci);  
	    printf("\nDesea agregar otro paciente? (S/N)"); 
        getchar();
    }while(getchar()=='S' || getchar()=='s');
	fclose(paci); 
    }else{
        printf("\nARCHIVO NO CREADO\n");
        printf("\nHASTA PRONTO\n");
    }
}