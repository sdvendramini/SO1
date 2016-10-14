//====================================== PARTE D ==========================================//

/*
• Número de peticiones a disco realizadas. 
• Cantidad de memoria configurada en el hardware y cantidad disponible 
• Promedio de carga de 1 minuto. 
*/


//----------------------------- Peticiones a Disco -----------------------------//
//cat /proc/diskstats

void petdisc(){
	char buffer[BUFFSIZE+1];
	char *p=NULL;
	int peticiones;
	FILE *fdiskstats;

	fdiskstats=fopen("/proc/diskstats","r");
		while (!feof(fdiskstats)){
			fgets(buffer,BUFFSIZE+1,fdiskstats);
			p=strstr(buffer,"sda");
			if(p !=NULL){
				strcpy(buffer,p);
				break;
			}
		}
	fclose(fdiskstats); 

	sscanf(buffer, "sda %d",&peticiones);
	printf("Peticiones a Disco: %d\n",peticiones);
}


//-------------------------------- Memoria ----------------------------------//
// cat /proc/meminfo

void inforam(int c){
	int memtotal, memfree, memdisp;
	FILE *fmeminfo;

	fmeminfo=fopen("/proc/meminfo","r");
	fscanf(fmeminfo,"MemTotal: %d kB \n",&memtotal);
	fscanf(fmeminfo,"MemFree: %d kB\n",&memfree);
	fscanf(fmeminfo,"MemAvailable: %d kB",&memdisp);
	fclose(fmeminfo);

	if (c==1){
		printf("Memoria Total: %d kB\n", memtotal);
		//printf("Memoria Free: %d kB\n", memfree);
		printf("Memoria Disponible: %d kB\n", memdisp);
	}
	else{
		printf("Memoria Total: %d MB\n", memtotal/1024);
		//printf("Memoria Free: %d kB\n", memfree);
		printf("Memoria Disponible: %d MB\n", memdisp/1024);
	}	
}


//--------------------------- Promedio de carga ----------------------------// 
// cat /proc/loadavg

void carga(){
	float carga;
	FILE *floadavg;

	floadavg=fopen("/proc/loadavg","r");
	fscanf(floadavg,"%f",&carga);
	fclose(floadavg);

	printf("Carga: %f\n", carga);
}