#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <admin.h>
main(){
     int opc;
 do{
    opc=menu();
	_flushall();
    switch(opc){
            case 1:
					regprof(profesionales,prof);
					break;
			case 2:
					recepcion(recepcionistas, rec);
					break;
			case 3:
					
					break;
			case 4: 		
					
					break;
			case 5:
					printf("\nHASTA PRONTO\n");
					break;			
			default:
					printf("\nNo es una opcion correcta...");
					break;
    }
    system("pause");
 }while(opc!=5);
}