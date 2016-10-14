#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "Cabecera.h"
#include "ParteB.h"
#include "ParteC.h"
#include "ParteD.h"

int main (int argc, char *argv[]){
/*
	//====================================== CABECERA ==========================================//

	printf("==============================================================\n");
	hostname(); //nombre del equipo
	fecha();	//Fecha y Hora actual

	//====================================== PARTE B ==========================================//	

	printf("==============================================================\n");

	cpuinfo();	//Tipo y modelo de CPU
	kernelinfo();	//Version del Kernel
	uptime();	//Tiempo desde que se inicio el SO
	filesystems();	//Cantidad de sistemas de archivos soportados por el kernel

	printf("==============================================================\n");

	//====================================== PARTE C ==========================================//

	if ((argc == 2) && (strcmp(argv[1],"-s") == 0)){
		tcpu();	//Cantidad de tiempo de CPU utilizado para usuarios, sistema y proceso idle.
		ctxt();	//Cantidad de cambios de contexto. 
		inisist();	//Fecha y hora cuando el sistema fue iniciado. 
		proc_creados();	//Número de procesos creados desde el inicio del sistema. 
	}

	//====================================== PARTE D ==========================================//

	else if ((argc==4) && (strcmp(argv[1],"-l") == 0)){
		unsigned int a=atoi(argv[2]);
		int b=atoi(argv[3]);

		tcpu();	//Cantidad de tiempo de CPU utilizado para usuarios, sistema y proceso idle.
		ctxt();	//Cantidad de cambios de contexto. 
		inisist();	//Fecha y hora cuando el sistema fue iniciado. 
		proc_creados();	//Número de procesos creados desde el inicio del sistema. 

		for(int i=0;i<b/a;i++){
			printf("-----------------------------\n");
			petdisc();	//Número de peticiones a disco realizadas.
			inforam();	//Cantidad de memoria configurada en el hardware y cantidad disponible.
			carga();	//Promedio de carga de 1 minuto.
			sleep(a);	
		}
	}


	else if(argc >= 2){
		printf("******OPCIONES NO ENCONTRADAS******\n\n");
		printf("NOMBRE\n    ksamp - informacion del sistema\n\n");
		printf("SYNOPSIS\n    ksamp\n    ksamp -s\n    ksamp -l [int]a [int]b\n\n");
		printf("DESCRIPCION\n");
		printf("    ksamp\n        Nombre del Equipo, Fecha y Hora, Tipo y Modelo de CPU, Tiempo transcurrido desde que se incio, Cantidad de sistemas de archivo soportados por el kernel\n\n");
		printf("    ksamp -s\n        Informacion de \"ksamp\" mas: Tiempo de CPU, Cantidad de cambio de contexto, Fecha y Hora de inicio de sistema, Cantidad de procesos creados\n\n");
		printf("    ksamp -l a b\n        Informacion de \"ksamp -s\" mas:Peticiones a disco, Memoria total y disponible, promedio de carga de 1 minuto en intervalos de \"a\" segundos durante \"b\" segundos\n\n");
	}

}
*/


///////////////////////////////////////////////////////////////////////////////////////////////
	int c;  
	short int parte_c=0;
	short int parte_d=0; 
	short int hflag=0;
	void mensaje_error(void);

	while ((c = getopt (argc, argv, "slh:")) != -1){ 
		switch (c){
			case 's':
				if (argc == 2){
					parte_c=1;
					break;
				}
				else{
					mensaje_error();
					return 0;
				}
			case 'l':
				if (argc == 4){
					parte_c=1;
					parte_d=1;
					break;
				}
				else if(argc != 5){
					mensaje_error();
					break;
				}
			case 'h':
				if (argc==5){
					parte_c=1;
					parte_d=1;
					hflag=1;
					break;
				}
				else
					mensaje_error();
					return 0;
			default:
				mensaje_error();
				return 0;
		}
	}


	//====================================== CABECERA ==========================================//

	printf("==============================================================\n");
	hostname(); //nombre del equipo
	fecha();	//Fecha y Hora actual

	//====================================== PARTE B ==========================================//	

	printf("==============================================================\n");

	cpuinfo();	//Tipo y modelo de CPU
	kernelinfo();	//Version del Kernel
	uptime();	//Tiempo desde que se inicio el SO
	filesystems();	//Cantidad de sistemas de archivos soportados por el kernel

	printf("==============================================================\n");

	//====================================== PARTE C ==========================================//

	if(parte_c){
		tcpu();	//Cantidad de tiempo de CPU utilizado para usuarios, sistema y proceso idle.
		ctxt();	//Cantidad de cambios de contexto. 
		inisist();	//Fecha y hora cuando el sistema fue iniciado. 
		proc_creados();	//Número de procesos creados desde el inicio del sistema. 
	}

	//====================================== PARTE D ==========================================//

	if (parte_d){
		unsigned a;
		int b;
		if (hflag){
			a=atoi(argv[3]);
			b=atoi(argv[4]);
		}
		else{
			a=atoi(argv[2]);
			b=atoi(argv[3]);
		} 

		for(int i=0;i<b/a;i++){
			printf("-----------------------------\n");
			petdisc();	//Número de peticiones a disco realizadas.
			inforam(hflag);	//Cantidad de memoria configurada en el hardware y cantidad disponible.
			carga();	//Promedio de carga de 1 minuto.
			sleep(a);	
		}
	}

}

void mensaje_error(void){
		printf("******OPCIONES NO ENCONTRADAS******\n\n");
		printf("NOMBRE\n    ksamp - informacion del sistema\n\n");
		printf("SYNOPSIS\n    ksamp\n    ksamp -s\n    ksamp -l [int]a [int]b\n    ksamp -l -h [int]a [int]b\n\n");
		printf("DESCRIPCION\n");
		printf("    ksamp\n        Nombre del Equipo, Fecha y Hora, Tipo y Modelo de CPU, Tiempo transcurrido desde que se incio, Cantidad de sistemas de archivo soportados por el kernel\n\n");
		printf("    ksamp -s\n        Informacion de \"ksamp\" mas: Tiempo de CPU, Cantidad de cambio de contexto, Fecha y Hora de inicio de sistema, Cantidad de procesos creados\n\n");
		printf("    ksamp -l a b\n        Informacion de \"ksamp -s\" mas:Peticiones a disco, Memoria total y disponible, promedio de carga de 1 minuto en intervalos de \"a\" segundos durante \"b\" segundos\n\n");
		printf("    ksamp -l -h a b\n        Informacion de \"ksamp -l\" La opcion -h devuelve valores de memoria en MB");
	}