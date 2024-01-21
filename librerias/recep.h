#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
//MENU INICIO
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
//Registro de pacientes
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
    FILE *paci;
    paciente pac;
void pacientes(FILE *paci,paciente pac){
    char c;
    //_flushall();
    paci=fopen("Pacientes.dat","r+b");
    system("cls");
    if(paci==NULL){
        printf("El archivo pacientes no existe");
        printf("\nDesea crear el archivo? (S/N):  "); 
         c=getch();
        if(c=='s'||c=='S'){
            paci=fopen("Pacientes.dat","w+b");
            printf("\nARCHIVO CREADO\n");
            _flushall();
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        paci=fopen("Pacientes.dat","a+b");
    }
    system("pause");
    system("cls");
    if(paci!=NULL){    
	    printf("Ingrese los datos del Paciente\n");
	do{
        _flushall();
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
        scanf("%d", &pac.fecha.dia); _flushall();
        while(pac.fecha.dia<=0||pac.fecha.dia>=31){
            printf("\n DIA INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 30\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.fecha.dia); _flushall();
        }
        printf("\nMes: ");
        scanf("%d", &pac.fecha.mes); _flushall();
        while(pac.fecha.mes<=0||pac.fecha.mes>=13){
            printf("\n MES INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 12\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.fecha.mes); _flushall();
        }
        printf("\nAño: ");
        scanf("%d", &pac.fecha.anio); _flushall();
        while(pac.fecha.anio<=1900||pac.fecha.anio>=2025){
            printf("\n AÑO INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1900 y 2024\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &pac.fecha.anio); _flushall();
        };
        pac.borrado=false;
		fwrite(&pac, sizeof(pac), 1, paci);  
	    printf("\nDesea crear el archivo? (S/N):  \n"); 
        c=getch();
    }while(c=='S'||c=='s');
	fclose(paci); 
    }else{
        printf("\nARCHIVO NO CREADO\n");
        printf("\nHASTA PRONTO\n");
    }
}

//registro de turnos
struct turno{
    int idProfecional;
    Fecha fecha;
    int DniPaciente;
    char DetallePaciente[380];
    bool borrado;
};  

    FILE *tur;
    turno turn;

void turnos(FILE *tur, turno turn){
    int c,r;
    system("cls");
    tur=fopen("Turnos.dat","r+b");
    if(tur==NULL){
        printf("El archivo turnos no existe");
        printf("\nDesea crear el archivo? (1: SI / 0: NO) "); 
         scanf("%d", &c); _flushall();
        if(c==1){
            tur=fopen("Turnos.dat","w+b");
            printf("\nARCHIVO CREADO\n");
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        tur=fopen("Turnos.dat","a+b");
    }
        system("pause");
        system("cls");
    if(tur!=NULL){    
        _flushall();
	    printf("Ingrese los datos del Turno\n\n");
	do{
		printf("\nIngrese Codigo del profesional: ");
        scanf("%d",&turn.idProfecional);_flushall();		
		printf("\nIngrese el DNI del paciente: ");
		scanf("%d",&turn.DniPaciente);_flushall();
        printf("\nIngrese la Fecha: ");
        printf("\nDia: ");
        scanf("%d", &turn.fecha.dia); _flushall();
        while(turn.fecha.dia<=0||turn.fecha.dia>=31){
            printf("\n DIA INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 30\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &turn.fecha.dia); _flushall();
        }
        printf("\nMes: ");
        scanf("%d", &turn.fecha.mes); _flushall();
        while(turn.fecha.mes<=0||turn.fecha.mes>=13){
            printf("\n MES INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1 y 12\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &turn.fecha.mes); _flushall();
        }
        printf("\nAño: ");
        scanf("%d", &turn.fecha.anio); _flushall();
        while(turn.fecha.anio<=1900||turn.fecha.anio>=2025){
            printf("\n AÑO INCORRECTO\n");
            printf("\n Debe ingresar un valor entre 1900 y 2024\n");
            printf("\nIngrese nuevamente: ");
            scanf("%d", &turn.fecha.anio); _flushall();
        };
        turn.borrado=false;
		fwrite(&turn, sizeof(turn), 1, tur);  
	    printf("\nDesea crear el archivo? (1: SI / 0: NO) "); 
        scanf("%d", &r); _flushall();
    }while(r==1);
	fclose(tur); 
    }else{
        printf("\nARCHIVO NO CREADO\n");
        printf("\nHASTA PRONTO\n");
    }
}