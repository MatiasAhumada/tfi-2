#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <recep.h>
main(){
     int opc;
 do{
   opc=menu();
   _flushall();
    switch(opc){
            case 1:
					
					break;
			case 2:
                    
					pacientes(paci,pac);
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