#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

void registro();

void sesion();

void cumple();

int tipo();

void menu();

void modif_us();

void mostrar_saldo();

void recarga_saldo();

void sube();

void billetera();

void volver();

void hora_actual_boleto();

void fecha_boleto();

long dniglobal, dniglobalcuenta;
long long  telefono;

void consultas();

void listar_recarga();

void movimientos_fecha();

void volver_consultas();

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Tiempo{
	int hora;
	int minuto;
	int segundo;
};

struct Usuario{
	long DNI;
	char nombre[50];
	struct Fecha fecha_nacimiento;
	char direccion[50];
	int tipo;
}persona;

struct Chofer{
	long DNI;
	char nombre[50];
	struct Fecha fecha_nacimiento;
	char direccion[50];
	long telefono;
	char email[50];
}chofer;

struct Recarga{
	long DNI_recarga;
	int num_con;
	float monto;
	char boca[50];
	char buffer[80];
}recarga;

struct Boleto{
	long DNI;
	long nro_tarjeta;
	long long telefono;
	int viaje;
	float saldo_utilizado;
	struct Fecha fecha_boleto;
	struct Tiempo tiempo_boleto;
	int tipo;
}boleto;

struct Colectivo{
	long nro_unidad;
	long DNIC;
	int turno;
	char marca[50];
	char modelo[50];
	int asientos;
	float kilometraje;
	struct Fecha fecha_alta;
	int discapacidad;
}colectivo; 

struct Cuenta{
	long DNI_cuen;
	float saldo;
	long nro_tarjeta;
	long long telefono;
	int tipo;
}perfil;

int main(){
//menu principal
	int a,b;
  	system ("color F3");
  	system("cls");
	printf("Bienvenido a SUBEMISIONERO \n\n");
	
	printf("1) Menu para usuarios \n2) Menu para administradores \n0) Salir\n");
	printf("Ingrese la opcione que desea: ");
	scanf("%d", &a);
do{

	switch(a){
		
		case 1: 
			sleep(1);
			system("cls");
			printf("Bienvenidos al menu de Usuarios: \n\n");
			printf("1) Iniciar secion\n2) Registrarte\n0) Volver\n");
			printf("Ingrese la opcione que desea: ");
			scanf("%d", &b);
			do{

	switch(b){
		
		case 1: 
			sleep(1);
			system("cls");	
			sesion();
			break;
	
		case 2: 
			sleep(1);
			system("cls");
			registro();
			break;

		case 0: 
			sleep(1);
			system("cls");
			volver_consultas();
			return 0;
			break;
		
		default:
			a=b;
			printf("Opcion incorrecta.\n");
	}
	}while(b==0);
	
	return 0;

		break;
	
		case 2: 
		
				consultas();
		break;

		case 0: 
		system("cls");
		printf("Muchas gracias");
		return 0;
		break;
		
		default:
			a=0;
			printf("Opcion incorrecta.\n");
	}
	}while(a==0);

	return 0;
}

void sesion(){
	//menu sesion
	long dniuser;
	FILE *arch;
    int auxi=0;
	int b=0;
	
	printf("Bienvenido al Inicio de sesion\n");
	do {
        printf("\nIngrese su DNI: ");
        scanf("%ld", &dniuser);

        auxi = 1;
        b = 0;

        if ((arch = fopen("usuarios.dat", "rb")) != NULL) {
            fread(&persona, sizeof(persona), 1, arch);
            
            while (!feof(arch)) {
                if (dniuser == persona.DNI) {
                    auxi = 0;
                    b = 1;
                    break;  // Salir del bucle si se encuentra el DNI
                }
                
                fread(&persona, sizeof(persona), 1, arch);
            }

            if (b == 0) {
                printf("El DNI no existe, intente de nuevo o registrese\n");
            }

            fclose(arch);
        } else {
            printf("Error al abrir el archivo.\n");
        }
    } while (auxi == 1);
    	sleep(1);
    	system("cls");
    	printf("Hola %s! Bienvenido al Menu principal\n", persona.nombre);
    	dniglobal=dniuser;
		dniglobalcuenta=dniuser;
		menu();
}

void registro(){
	
	long long  telefonouser;
	long dniuser;
	FILE *arch, *archivo2;
    int auxi=0;
	int b=0;
	printf("Bienvenido al Registro de usuario\n\n");
	do{
   	 	printf("Ingrese su DNI: ");
   		scanf("%ld", &dniuser);
   		auxi=0;
   		b=0;
   
   		if((arch = fopen("usuarios.dat","rb")) != NULL) {
    		fread(&persona,sizeof(persona),1,arch);
      		while(!feof(arch)){
    
           		if(dniuser == persona.DNI && b==0) {
                printf("El DNI ya esta en uso. Intente de nuevo \n");
               	auxi=1;
               	b=1;
              
           		 }	
				fread(&persona,sizeof(persona),1,arch);	
        	}
       
       	fclose(arch);
   		}
        
    		
    }while(auxi==1);
    
    persona.DNI=dniuser;
    dniglobal=dniuser;
    dniglobalcuenta=dniuser;
    	
	printf("Ingrese su nombre: ");
	fflush(stdin);
	gets(persona.nombre);
	
	printf("Ingrese su direccion: ");
	fflush(stdin);
	gets(persona.direccion);
	
	printf("Ingrese su fecha de nacimiento (DD/MM/AAAA) \n");
	cumple();
	
	do{
   	 	printf("Ingrese su telefono: ");
   		scanf("%lld", &telefonouser);
   		auxi=0;
   		b=0;
   
   		 if((arch = fopen("cuenta.dat","rb")) != NULL) {
    		fread(&perfil,sizeof(perfil),1,arch);
      		while(!feof(arch)){
    
           		if(telefonouser == perfil.telefono && b==0) {
                printf("El numero de telefono ya esta en uso. Intente de nuevo \n");
               	auxi=1;
               	b=1;
              
           		 }	
				fread(&perfil,sizeof(perfil),1,arch);	
        	}
       
       	 fclose(arch);
   		} 
        	
    }while(auxi==1);
    
    perfil.telefono=telefonouser;

	
	perfil.nro_tarjeta=persona.DNI;
	
	printf("Ingrese su tipo de usuarios : ");
	tipo();
	
	perfil.saldo=0;
	perfil.tipo=persona.tipo;
	perfil.DNI_cuen=dniuser;
	
	if ((arch=fopen("usuarios.dat", "ab"))!=NULL){
		
		fwrite(&persona,sizeof(persona),1,arch);
		
	printf("\n--------------------------------------\n");
		printf("\nTus datos de usuario ingresados son los siguientes:");
		printf("\nDNI: %ld \n", persona.DNI);
		printf("NOMBRE: %s \n", persona.nombre);
		
			if(persona.tipo==1){
				printf("TIPO: Normal");
				}
				if(persona.tipo==2){
					printf("TIPO: Beneficio Boleto Estudiantil Gratuito");
					}
					if(persona.tipo==3){
						printf("TIPO: Beneficio por discapacidad");
						}
						if(persona.tipo==4){
							printf("TIPO: Beneficio de Mayor de Edad");
							}
							if(persona.tipo==5){
								printf("TIPO: Beneficio Ex-Combatiente de Malvinas");
								}

		
		printf("\nDIRECCION: %s \n", persona.direccion);
		printf("FECHA: %d/%d/%d", persona.fecha_nacimiento.dia, persona.fecha_nacimiento.mes, persona.fecha_nacimiento.anio);
			
		fclose(arch);
		
	}else{
		printf("error");
	}
	
	if((archivo2=fopen("cuenta.dat","ab"))!=NULL){
		
		fwrite(&perfil,sizeof(perfil),1,archivo2);
		printf("\nTELEFONO: %lld ", perfil.telefono);
		printf("\nNRO TARJETA: %ld ", perfil.nro_tarjeta);
		printf("\nSALDO: %.2f ", perfil.saldo);
		printf("\n--------------------------------------\n");
		fclose(archivo2);
	
	}else{
		printf("error");
	}
	sleep(1);
	system("cls");     
	printf("\nHola %s! Bienvenido al Menu principal\n", persona.nombre);
	dniglobal=dniuser;
	menu();
 
}

int tipo(){ 

	int a, b=0, aux=0;
	
	do {
		printf("\n 1) Normal \n 2) Beneficio Boleto Estudiantil Gratuito \n 3) Beneficio por discapacidad");
		printf (" \n 4) Beneficio de Mayor de Edad \n 5) Beneficio Ex-Combatiente de Malvinas\n");
		printf("Ingrese la opcion que desea: ");
		scanf("%d", &persona.tipo);
		switch(persona.tipo){
			case 1:
				aux=1;
				break;
			case 2:
				printf("Posee la Constancia de Inscripcion BEEG?");
					do {
						printf("\n 1) si \n 2) no \n ");
						scanf("%d", &a);
						switch(a){
							case 1:
								b=1;
								aux=1;
								break;
							case 2:
							printf(" No cuentas con los requisitos. Reintente \n");
							b=1;
								break;
							default: 
								printf(" Numero invalido, intente de nuevo \n");		
						}
					}while(b==0);
				break;
			case 3:
					printf("Posee el Certificado Unico de Discapacidad 'CUD'?");
					do {
						printf("\n 1) si \n 2) no \n ");
						scanf("%d", &a);
						switch(a){
							case 1:
								b=1;
								aux=1;
								break;
							case 2:
							printf("\n No cuentas con los requisitos. Reintente \n");
							b=1;
								break;
							default: 
								printf(" Numero invalido, intente de nuevo \n");		
						}
					}while(b==0);
				break;
			case 4:
				if(persona.fecha_nacimiento.anio<1953){
					aux=1;
				}
				else if(persona.fecha_nacimiento.anio==1953 && persona.fecha_nacimiento.mes<=11){ //si queremos agregar el dia hay q hacer otro if. No agregar a este. atte: mati
					aux=1;
				}
				else{
						printf("\n No cuentas con los requisitos. Reintente \n");
				}
				break;
			case 5:
					printf("Posee el Certificado de Ex-Combatiente?");
					do {
						printf("\n 1) si \n 2) no \n ");
						scanf("%d", &a);
						switch(a){
							case 1:
								b=1;
								aux=1;
								break;
							case 2:
							printf("\n No cuentas con los requisitos. Reintente \n");
							b=1;
								break;
							default: 
								printf(" Numero invalido, intente de nuevo \n");		
						}
					}while(b==0);
				break;
				
			default: 
			printf(" Numero invalido, intente de nuevo \n");		
		}
	}while(aux==0);

}

void cumple(){

	printf("Ingrese el dia: ");
	scanf("%d", &persona.fecha_nacimiento.dia);
	
		while(persona.fecha_nacimiento.dia<1 || persona.fecha_nacimiento.dia>31){
		printf("\nDia no valido, ingreselo otra vez: ");
		scanf("%d",&persona.fecha_nacimiento.dia);
	}
	printf("Ingrese el mes: ");
	
	scanf("%d", &persona.fecha_nacimiento.mes);
	while(persona.fecha_nacimiento.mes<1 || persona.fecha_nacimiento.mes>12){
		printf("\nmes no valido, ingreselo otra vez: ");
		scanf("%d",&persona.fecha_nacimiento.mes);
	}
	
	printf("Ingrese el anio: ");
	
	scanf("%d", &persona.fecha_nacimiento.anio);
	while(persona.fecha_nacimiento.anio>2023){
		printf("\nAnio no valido, ingreselo otra vez: ");
		scanf("%d",&persona.fecha_nacimiento.anio);
	}
}

void menu(){

	int opcion, opcion_us, opcion_sa, opcion_subi, opcion_colchof;

	//Menu Principal

	printf("Por favor elija una de las siguientes opciones:\n");
	printf("1: Menu de Usuarios\n");
	printf("2: Menu de saldo\n");
	printf("3: Menu de uso de la SUBE o Billetera Electronica\n");
	printf("4: Volver al menu de inicio\n");
	printf("Ingrese el numero correspondiente de a donde desea entrar: ");
	scanf("%d", &opcion);

	switch(opcion){
		
		//Menu de Usuarios
		case 1: 
		system("cls");
			printf("Bienvenido al Menu de usuarios\n");
			printf("Por favor elija una de las siguientes opciones:\n");
			printf("1) Para modificar datos de un usuario\n0) Salir\n");
			printf("Ingrese el numero correspondiente de a donde desea entrar: ");
			scanf("%d",&opcion_us);

			if(opcion_us==1){
				sleep(1);
				system("cls");
				modif_us();					//Se llama a la funcion que modifica los usuarios		
			}else if (opcion_us==0){
				system("cls");
				volver();
			}else{
			 printf("Opcion incorrecta\n");
			 getch();
			menu();
		}

			break;
		//Menu de saldo
		case 2:
			system("cls");
			printf("Bienvenido al Menu de saldo\n");
			printf("Por favor elija una de las siguientes opciones:\n");
			printf("1) Para recargar saldo\n");
			printf("2) Para mostrar cuanto saldo tiene disponible\n");
			printf("Ingrese el numero correspondiente de a donde desea entrar: ");
			scanf("%d",&opcion_sa);
			if(opcion_sa==1){
				sleep(1);
				system("cls");
				recarga_saldo();					//Se llama a la funcion que recarga saldo
					
			}else{
				sleep(1);
				system("cls");
				mostrar_saldo();					//Se llama a la funcion que muestra el saldo disponible
					
			}
			break;
		
		//Menu de uso de boleto o boletotera
		case 3:
			system("cls");
			printf("Bienvenido al Menu de uso de boleto o boletotera\n");
			printf("Por favor elija una de las siguientes opciones:\n\n");
			printf("1) Para usar la SUBE para pagar un boleto\n");
			printf("2) Para usar la Billetera Electronica para pagar un boleto\n");
			printf("Ingrese el numero correspondiente de a donde desea entrar: ");
			scanf("%d",&opcion_subi);
			
			if(opcion_subi==1){
				system("cls");
				sube();						//Se llama a la funcion donde se registra el uso de la sube
					
			}else if(opcion_subi==2){
				system("cls");
				billetera();				//Se llama a la funcion donde se registra el uso de la billetera
					
			}else{
				printf("Incorrecto");
				getch();
				menu();
			}
			break;
		case 4: 
			volver_consultas();
		break;
		
		//Mensaje por si la persona ingresa una opcion que no existe
		default:
			printf("La opcion ingresada es erronea");
			sleep(1);
			system("cls");
	}
}

void modif_us(){

	FILE *archivo;
	int opcion, tipo_n;
	long dni;
	char name[50], direc[50];
	struct Fecha fecha_buscada;
	int aux_modif=0;
	int a=1;
	int aux_bucle;

	int cancel=0;

    //if ((archivo=fopen("usuario.dat","r+b"))!=NULL) {
	
		printf("Elija el dato que desea modificar:\n\n");
		
		
		do{
		printf("1: Nombre y apellido\n");
		printf("2: Fecha de nacimiento\n");
		printf("3: Direccion\n");
		printf("4: Tipo de usuario\n");
		printf("5: Cancelar\n");
		printf("Ingrese el numero correspondiente de a la opcion desea: ");
			scanf("%d", &opcion);
		
			switch(opcion){
				
				case 1:
				
					 if ((archivo = fopen("usuarios.dat", "r+b")) != NULL) {
      					  while (fread(&persona, sizeof(persona), 1, archivo) == 1) {
          					  if (persona.DNI == dniglobal) {
					                printf("\nIngrese el nuevo nombre: ");
					                fflush(stdin);
					                gets(persona.nombre);
					                fflush(stdin);
					                fseek(archivo,-sizeof(persona), SEEK_CUR);
					                fwrite(&persona, sizeof(persona), 1, archivo);
					                break; // Importante salir del bucle después de actualizar
            					}
       						 }	

					       fclose(archivo);
					        printf("Se ha actualizado el dato con exito\n");
					    } else {
					        printf("Error de apertura de archivo\n");
					    }
					break;
				
				case 2:
					 if ((archivo = fopen("usuarios.dat","r+b")) != NULL) {
      					  while (fread(&persona, sizeof(persona),1,archivo) == 1) {
          					  if (persona.DNI==dniglobal) {
          					  	
					            printf("Ingrese su nueva fecha de nacimiento (DD/MM/AAAA) \n");
								cumple();
								
					
					                fseek(archivo,-sizeof(persona),SEEK_CUR);
					                fwrite(&persona,sizeof(persona),1,archivo);
					                break; // Importante salir del bucle después de actualizar
            					}
       						 }	

					       fclose(archivo);
					        printf("Se ha actualizado el dato con exito\n");
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					break;
					
				case 3:
					
					if ((archivo = fopen("usuarios.dat", "r+b")) != NULL) {
      					  while (fread(&persona, sizeof(persona), 1, archivo) == 1) {
          					  if (persona.DNI == dniglobal) {
          					  	
					           	printf("Ingrese su nueva direccion: \n");
					           	fflush(stdin);
					            fgets(persona.direccion, sizeof(persona.direccion), stdin);
								
					
					                fseek(archivo, -sizeof(persona), SEEK_CUR);
					                fwrite(&persona, sizeof(persona), 1, archivo);
					                break; // Importante salir del bucle después de actualizar
            					}
       						 }	

					       fclose(archivo);
					        printf("Se ha actualizado el dato con exito\n");
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					break;
			
					
				case 4:
					
					 if ((archivo = fopen("usuarios.dat", "r+b")) != NULL) {
      					  while (fread(&persona, sizeof(persona), 1, archivo) == 1) {
          					  if (persona.DNI == dniglobal) {
          					  	
          					  	printf("Ingrese su nuevo tipo de usuario \n");
							
								tipo();
					                fseek(archivo, -sizeof(persona), SEEK_CUR);
					                fwrite(&persona, sizeof(persona), 1, archivo);
					                break;
            					}
       						 }	

					       fclose(archivo);
					        printf("Se ha actualizado el dato con exito\n");
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					break;
					
					case 5:
						cancel=1;
						aux_modif=1;
						
					break;
						
				default:
					printf("La opcion ingresada no existe, Intente de nuevo\n");
				}
					if(opcion==1||opcion==2||opcion==3||opcion==4){
						
			do{
				a=1;
			printf("\nDesea actualizar otro dato?");
			printf("\n1) Si \n2) No \n ");
			printf("\nIngrese la opcion: ");
			scanf("%d", &aux_bucle);
			switch(aux_bucle){
			case 1:
				aux_modif=0;
				break;
			case 2:
				aux_modif=1;
				break;
			default:
				printf("Tecla incorrecta, intente de nuevo");	
				a=0;
			}
				}while(a==0);
		}
	}while(aux_modif==0);
	if(cancel!=1){
	system("cls");
	printf("Tus datos se han actualizado con exito!");
		printf("\n--------------------------------------\n");
           		printf("\nDNI: %ld ", persona.DNI);
				printf("\nNOMBRE: %s ", persona.nombre);
		
				if(persona.tipo==1){
					printf("\nTipo: Normal");
					}
					if(persona.tipo==2){
						printf("\nTipo: Beneficio Boleto Estudiantil Gratuito");
						}
						if(persona.tipo==3){
							printf("\nTipo: Beneficio por discapacidad");
							}
							if(persona.tipo==4){
								printf("\nTipo: Beneficio de Mayor de Edad");
								}
								if(persona.tipo==5){
									printf("\nTipo: Beneficio Ex-Combatiente de Malvinas");
									}
				printf("\nDIRECCION: %s ", persona.direccion);
				printf("\nFECHA: %d/%d/%d", persona.fecha_nacimiento.dia, persona.fecha_nacimiento.mes, persona.fecha_nacimiento.anio);
				printf("\n--------------------------------------\n");
			}
	volver();
	
}

void recarga_saldo(){
	
	FILE *archivo_cuenta, *archivo_recarga, *archivo_txt;
	int dni;
	float saldo;
	char linea[1000];
	
	printf("BIENVENIDO A LA RECARGA DE SALDO");
	if((archivo_cuenta=fopen("cuenta.dat","rb"))!=NULL){
		
		fread(&perfil,sizeof(perfil),1,archivo_cuenta);
		while(!feof(archivo_cuenta)){
		if(dniglobalcuenta==perfil.DNI_cuen){
		printf("\n--------------------------------------");
		printf("\nDNI CUENTA: %ld ", perfil.DNI_cuen);
		printf("\nTELEFONO: %lld ", perfil.telefono);
		printf("\nNRO TARJETA: %ld ", perfil.nro_tarjeta);
		printf("\nSALDO: %.2f \n", perfil.saldo);
		if(persona.tipo==1){
				printf("TIPO: Normal");
				}
				if(persona.tipo==2){
					printf("TIPO: Beneficio Boleto Estudiantil Gratuito");
					}
					if(persona.tipo==3){
						printf("TIPO: Beneficio por discapacidad");
						}
						if(persona.tipo==4){
							printf("TIPO: Beneficio de Mayor de Edad");
							}
							if(persona.tipo==5){
								printf("TIPO: Beneficio Ex-Combatiente de Malvinas");
								}
		
		printf("\n--------------------------------------\n");
		}
		fread(&perfil,sizeof(perfil),1,archivo_cuenta);
		}
		fclose(archivo_cuenta);
	
	}else{
		printf("error");
	}     
	
	
	if((archivo_cuenta=fopen("cuenta.dat","r+b"))!=NULL){
	
		fread(&perfil,sizeof(perfil),1,archivo_cuenta);
	//	fseek(archivo_cuenta,-sizeof(perfil),SEEK_CUR);
		while(!feof(archivo_cuenta)){

			if(dniglobalcuenta==perfil.DNI_cuen){
				
				if((archivo_recarga=fopen("recarga.dat","ab"))!=NULL){
					
					recarga.DNI_recarga=dniglobalcuenta;
					// Obtener la hora actual en segundos desde el Epoch
    				time_t tiempo_actual;
				    time(&tiempo_actual);
				
				    // Convertir el tiempo actual a una estructura tm (estructura de tiempo)
				    struct tm *info_tiempo = localtime(&tiempo_actual);
				
				    // Formatear y mostrar la hora actual
				    char buffer[80]; // Buffer para almacenar la hora formateada
				    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info_tiempo);
				    //printf("La hora actual es: %s\n", buffer);
    				strcpy(recarga.buffer, buffer);
					printf("Ingrese desde donde esta haciendo la recarga: ");
					getchar();
					gets(recarga.boca);
					printf("Ingrese cuanto saldo desea recargar: $");
					scanf("%f", &recarga.monto);
					perfil.saldo=perfil.saldo+recarga.monto;
					
				//	recarga.num_con=contadorglobalfuncion();
					
					//fwrite(&perfil,sizeof(perfil),1,archivo_cuenta);
					fwrite(&recarga,sizeof(recarga),1,archivo_recarga);
					fclose(archivo_recarga);
				}else{
					printf("Error de apertura del archivo 'recarga'\n");
				}
				fseek(archivo_cuenta, -sizeof(perfil), SEEK_CUR);
            fwrite(&perfil, sizeof(perfil), 1, archivo_cuenta);
				break;
			}
			
			fread(&perfil,sizeof(perfil),1,archivo_cuenta);
		}
		fclose(archivo_cuenta);
		getch();
		system("cls");
		
		if((archivo_txt=fopen("comprobante.txt", "w"))!=NULL){
			// Escribe el comprobante en el archivo
			fprintf(archivo_txt, "\n--------------------------------------\n");
			fprintf(archivo_txt, "COMPROBANTE DE RECARGA\n");
		    fprintf(archivo_txt, "DNI: %ld\n", recarga.DNI_recarga);
		    fprintf(archivo_txt, "Nro. Control: %d\n", recarga.num_con);
		    fprintf(archivo_txt, "Monto: %.2f\n", recarga.monto);
		    fprintf(archivo_txt, "Boca de Pago: %s\n", recarga.boca);
		    fprintf(archivo_txt, "Fecha y hora actual: %s\n", recarga.buffer);
		    //fprintf(archivo_txt, "Fecha y Hora: %d/%d/%d | %d hs %d mins %d segs\n", recarga.fecha_recarga.dia, recarga.fecha_recarga.mes,
		    //recarga.fecha_recarga.anio, recarga.tiempo_recarga.hora, recarga.tiempo_recarga.minuto, recarga.tiempo_recarga.segundo);
		    fprintf(archivo_txt, "--------------------------------------\n");
		    fclose(archivo_txt);
		}else{
			printf("Error de apertura del archivo 'comprobante'\n");
		}
	}else{
		printf("Error de apertura del archivo 'cuentas'\n");
	}
	
	if((archivo_txt=fopen("comprobante.txt","r"))!=NULL){
		while (fgets(linea, sizeof(linea), archivo_txt) != NULL) {
            printf("%s", linea);
        }
	}
	getch();
	system("cls");
	volver();
}

void mostrar_saldo(){
	
	FILE *archivo;
	long dni;
	
	// Obtener la hora actual en segundos desde el Epoch
    time_t tiempo_actual;
    time(&tiempo_actual);

    // Convertir el tiempo actual a una estructura tm (estructura de tiempo)
    struct tm *info_tiempo = localtime(&tiempo_actual);

    // Formatear y mostrar la hora actual
    char buffer[80]; // Buffer para almacenar la hora formateada
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info_tiempo);
	
if ((archivo = fopen("cuenta.dat", "rb")) != NULL) {
        fread(&perfil, sizeof(perfil), 1, archivo);

        while (!feof(archivo)) {
            if (perfil.DNI_cuen == dniglobalcuenta) {
                printf("DNI: %ld\n", perfil.DNI_cuen);
                printf("Su saldo actual es de: $%.2f\n", perfil.saldo);
                printf("La hora actual es: %s\n", buffer);
                getch();
                system("cls");
                break;  // Salir del bucle después de encontrar el DNI
            }
            fread(&perfil, sizeof(perfil), 1, archivo);
        }

        fclose(archivo);
    } else {
        printf("Error de apertura de archivo\n");
        getch();
        system("cls");
    }
	volver();
	system("cls");
}

void sube(){
	FILE *arch, *arch2, *archivo_movimientos1, *archivo_movimientos2;
	int auxi, b, auxi1, b1, opc, opc2, hora, fecha;
		
		printf("Que viaje quiere realizar: \n");
		printf("1)Dentro de Posadas. \n");
		printf("2)Dentro de Garupa. \n");
		printf("3)Dentro de Candelaria. \n");
		printf("4)De Posadas a Garupa. \n");
		printf("5)De Posadas a Candelaria. \n");
		printf("6)De Garupa a Posadas. \n");
		printf("7)De Garupa a Candelaria. \n");
		printf("8)De Candelaria a Posadas. \n");
		printf("9)De Candelaria a Garupa. \n");
		printf("Ingrese un numero: ");
		scanf("%d",&opc);
		boleto.viaje=opc;
		boleto.tipo=1;
		
		switch (opc){
			
			case 1:
				
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				
				if (opc2==1){
					 if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;
          					 	 	break;
										}	
										if(	(perfil.saldo>=100)){
										boleto.saldo_utilizado=100;
										perfil.saldo= perfil.saldo-100;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						/*printf("dni: %ld\n", boleto.DNI);
						printf("tarjeta: %ld\n", boleto.nro_tarjeta);
						printf("viaje: %d\n", boleto.viaje);
						printf("saldo: %.2f\n", boleto.saldo_utilizado);
						printf("tipo: %d\n", boleto.tipo);
						printf("fecha y hora: %d/%d/%d | %d:%d", boleto.fecha_boleto.dia, boleto.fecha_boleto.mes, boleto.fecha_boleto.anio, boleto.tiempo_boleto.hora, boleto.tiempo_boleto.minuto);*/
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

			break;
			case 2:
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
							
					if (opc2==1){
						if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=100)){
										boleto.saldo_utilizado=100;
										perfil.saldo= perfil.saldo-100;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

			break;
						
			case 3:
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
									}	
										if(	(perfil.saldo>=100)){
										boleto.saldo_utilizado=100;
										perfil.saldo= perfil.saldo-100;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

			break;
			case 4:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			case 5:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
					if (opc2==1){
						if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			break;
			case 6:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			case 7:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
				if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			case 8:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				

									
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			break;
			case 9:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				
					

									
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
                    				boleto.nro_tarjeta=perfil.nro_tarjeta;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
					
					fecha_boleto();		
					hora_actual_boleto();
					printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					fclose(archivo_movimientos1);
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			break;
			
			
			
			
		}
		
}

void billetera(){
	
	FILE *arch, *arch2, *archivo_movimientos1, *archivo_movimientos2;
	int auxi, b, auxi1, b1, opc, opc2, hora, fecha;
	long long tel, tel2;
	
		if ( (arch = fopen("cuenta.dat", "rb")) != NULL) {
            fread(&perfil, sizeof(perfil), 1, arch);
            
            while (!feof(arch)) {
                if (dniglobal==perfil.DNI_cuen) {
                	//printf("%lld",perfil.telefono);
                	tel=perfil.telefono;
                    auxi = 0;
                    b = 1;
                    break;  // Salir del bucle cuando cargue el telefono en la variable tel
                }
                
                fread(&perfil, sizeof(perfil), 1, arch);
            }

            if (b == 0) {
                printf("El Telefono no existe\n");
            }

            fclose(arch);
        } else {
            printf("Error al abrir el archivo.\n");
        } 
        
        printf("Ingrese su telefono : ");
        scanf("%ld",&tel2);
        
        if(tel==tel2){
        	
			printf("Que viaje quiere realizar: \n");
			printf("1)Dentro de Posadas. \n");
			printf("2)Dentro de Garupa. \n");
			printf("3)Dentro de Candelaria. \n");
			printf("4)De Posadas a Garupa. \n");
			printf("5)De Posadas a Candelaria. \n");
			printf("6)De Garupa a Posadas. \n");
			printf("7)De Garupa a Candelaria. \n");
			printf("8)De Candelaria a Posadas. \n");
			printf("9)De Candelaria a Garupa. \n");
			printf("Ingrese un numero: ");
			scanf("%d",&opc);
			boleto.viaje=opc;
			boleto.tipo=2;
			
			switch (opc){
			
			case 1:
				
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
				
				if (opc2==1){
					 if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					if (perfil.DNI_cuen==dniglobal) {
                    			boleto.DNI=dniglobal;
          					 	boleto.telefono=tel;
          					  	if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
								}	
								if(	(perfil.saldo>=100)){
									boleto.saldo_utilizado=100;
									perfil.saldo= perfil.saldo-100;
								}else{
									printf("\nNo tiene saldo disponible\n");
									getch();
									menu();											
									break;
								}
					        	fseek(arch2,-sizeof(perfil),SEEK_CUR);
					            fwrite(&perfil,sizeof(perfil),1,arch2);
					            break;
            				}
       					}	

					       fclose(arch2);
					       
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						/*printf("dni: %ld\n", boleto.DNI);
						printf("telefono: %lld\n", boleto.telefono);
						printf("viaje: %d\n", boleto.viaje);
						printf("saldo: %.2f\n", boleto.saldo_utilizado);
						printf("tipo: %d\n", boleto.tipo);
						printf("fecha y hora: %d/%d/%d | %d:%d", boleto.fecha_boleto.dia, boleto.fecha_boleto.mes, boleto.fecha_boleto.anio, boleto.tiempo_boleto.hora, boleto.tiempo_boleto.minuto);*/
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

				break;
				
			case 2:
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
							
					if (opc2==1){
						if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=100)){
										boleto.saldo_utilizado=100;
										perfil.saldo= perfil.saldo-100;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

				break;
						
			case 3:
				system("cls");
				printf("Este boleto vale $100\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
													
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=100)){
										boleto.saldo_utilizado=100;
										perfil.saldo= perfil.saldo-100;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}

				break;
				
			case 4:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
							
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
				break;
				
			case 5:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
								
					if (opc2==1){
						if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
				break;
			
			case 6:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
								
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
				break;
				
			case 7:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
								
				if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
				break;
				
			case 8:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
							
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 	 	boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  		boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
										if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo= perfil.saldo-200;
										}else{
											printf("\nNo tiene saldo disponible\n");
											getch();
											menu();											
											break;
										}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
						}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
			
				break;
				
			case 9:
				system("cls");
				printf("Este boleto vale $200\n");
				printf("\nDesea pagar: \n1)pagar\n2)cancelar\n");
				printf("Ingrese la opcion: ");
				scanf("%d",&opc2);
								
					if (opc2==1){
					 	if ((arch2 = fopen("cuenta.dat","r+b")) != NULL) {
      					  while (fread(&perfil, sizeof(perfil),1,arch2) == 1) {
          					  if (perfil.DNI_cuen==dniglobal) {
          					 		boleto.DNI=dniglobal;
          					 		boleto.telefono=tel;
          					  		if(persona.tipo!=1){
          					  			boleto.saldo_utilizado=0;	
          					 	 	break;
										}	
									if(	(perfil.saldo>=200)){
										boleto.saldo_utilizado=200;
										perfil.saldo=perfil.saldo-200;
									}else{
										printf("\nNo tiene saldo disponible\n");
										getch();
										menu();											
										break;
									}
					                fseek(arch2,-sizeof(perfil),SEEK_CUR);
					                fwrite(&perfil,sizeof(perfil),1,arch2);
					                break;
            					}
       						 }	

					       fclose(arch2);
					    }else {
					        printf("Error de apertura de archivo\n");
							}
						
						fecha_boleto();
						hora_actual_boleto();
						printf("\nMuchas gracias por viajar con nosotros\n");		
					
					if((archivo_movimientos1=fopen("movimientos.dat","ab"))!=NULL){
						fwrite(&boleto,sizeof(boleto),1,archivo_movimientos1);
						fclose(archivo_movimientos1);
					}else{
						printf("Error de apertura del archivo 'movimientos'\n");
					}
					getch();
					system("cls");
					menu();
				}else{
					menu();
				}
				break;
				
			default:
				printf("Opcion ingresada incorrecta\n");
					
		}
			
		}else{
			printf("\nNnumero incorrecto.\n");
			getch();
			menu();
		}
		
}

void volver(){
	int opcion;
	system("cls");
	printf("Desea volver al Menu de inicio o volver al Menu principal?\n");
	printf("Menu de inicio [1] || Menu principal [2] || Salir [0]\n");
	printf("Elija la opcion que desea: ");
	scanf("%d", &opcion);
	if(opcion==1){
		system("cls");
		main();
	}else if(opcion==2){
		system("cls");
		menu();
	}else if(opcion==0){
		printf("Programa finalizado\n");
		exit(1);
	}else{
		printf("La opcion ingresada es incorrecta\n");
	}
}

void consultas(){
	
	FILE *archivo_mov, *archivo, *arch4, *arch5, *arch6, *arch7, *arch8, *arch9;
	char name[50];
	int a=0, b=0, auxi, c, cont1m=0, cont1t=0, ops, cont=0, maxPasajeros = 0, mes, contadorPasajeros[18] = {0}; // Inicializamos el contador de pasajeros por chofer a cero
	struct Chofer chofer2[18]; 
    struct Colectivo colectivo2[18];
    long DNI_maxPasajeros, dnichof;
    sleep(1);
	system("cls");
	printf("\nBienvenido al Menu de Admin\n");
	printf("\n1) Listado de todos los usuarios\n2) Movimientos registrados entre dos fechas\n3) Lista de recargas de un usuario en particular\n4) Movimientos registrados por un usuario en particular\n5) Chofer/es con mas pasajeros\n6) Porcentaje de pasajeros que viajan en el primer turno\n7) Cantidad de usuarios con beneficios\n8) Registro de choferes\n9) Registro de colectivos\n0) Volver\n");
	printf("Ingrese la opcion que desea: ");
	scanf("%d",&ops);
	 
	switch(ops){
		
		
		case 1:		system("cls");
			archivo = fopen("usuarios.dat", "r+b");
    		if (archivo == NULL) {
        		printf("No se pudo abrir el archivo.\n");
    			}else{fread(&persona,sizeof(persona),1,archivo);
   					 while(!feof(archivo)){
        				printf("\n--------------------------------------\n");
           				printf("\nDNI: %ld ", persona.DNI);
						printf("\nNOMBRE: %s ", persona.nombre);
						if(persona.tipo==1){
							printf("\nTipo: Normal");
						}
							if(persona.tipo==2){
							printf("\nTipo: Beneficio Boleto Estudiantil Gratuito");
							}
								if(persona.tipo==3){
								printf("\nTipo: Beneficio por discapacidad");
								}
									if(persona.tipo==4){
									printf("\nTipo: Beneficio de Mayor de Edad");
									}
										if(persona.tipo==5){
										printf("\nTipo: Beneficio Ex-Combatiente de Malvinas");
										}
				printf("\nDIRECCION: %s ", persona.direccion);
				printf("\nFECHA: %d/%d/%d", persona.fecha_nacimiento.dia, persona.fecha_nacimiento.mes, persona.fecha_nacimiento.anio);
				printf("\n--------------------------------------\n");
              	fread(&persona,sizeof(persona),1,archivo);
              	
   			 }  
				fclose(archivo);
					}
					printf("\n Pulse Enter para continuar");
					getch();
					system("cls");
					volver_consultas();
			break;
		
		case 2:
			movimientos_fecha();
			break;
		
		case 3:
			system("cls");
			listar_recarga();
			//getch();
		//	volver_consultas();
			break;
		
		case 4:
			printf("\nIngrese el nombre que desea buscar: ");
			fflush(stdin);
			gets(name);
			
				if((archivo=fopen("usuarios.dat", "rb"))!=NULL){
					fread(&persona,sizeof(persona),1,archivo);
					while(!feof(archivo)){
						a=0;
						if (strcmp(name, persona.nombre) == 0){//compara las cadenas
						b=1;// la b esta por si el nombre no se encontro
						printf("\nMovimientos de %s con DNI: %ld :", name, persona.DNI);
							if((archivo_mov=fopen("movimientos.dat","rb"))!=NULL){
								fread(&boleto,sizeof(boleto),1,archivo_mov);
								while(!feof(archivo_mov)){
										if(boleto.DNI==persona.DNI){
											a=1;// la a esta por si no se registraron movimientos
											
											printf("\n--------------------------------------");
											printf("\nDNI: %ld",boleto.DNI);
											if(boleto.tipo==1){
												printf("\nSUBE");
												printf("\nNRO TARJETA: %ld",boleto.nro_tarjeta);
											}else if(boleto.tipo==2){
												printf("\nBilletera Electronica");
												printf("\nTELEFONO: %lld",boleto.telefono);
											}
											if(boleto.viaje==1){
												printf("\nVIAJE: Dentro de Posadas\n");
											}else if(boleto.viaje==2){
												printf("\nVIAJE: Dentro de Garupa\n");
											}else if(boleto.viaje==3){
												printf("\nVIAJE: Dentro de Candelaria\n");
											}else if(boleto.viaje==4){
												printf("\nVIAJE: Posadas-Garupa\n");
											}else if(boleto.viaje==5){
												printf("\nVIAJE: Posadas-Candelaria\n");
											}else if(boleto.viaje==6){
												printf("\nVIAJE: Garupa-Posadas\n");
											}else if(boleto.viaje==7){
												printf("\nVIAJE: Garupa-Posadas\n");
											}else if(boleto.viaje==8){
												printf("\nVIAJE: Candelaria-Posadas\n");
											}else if(boleto.viaje==9){
												printf("\nVIAJE: Candelaria-Garupa\n");
											} 
											printf("PRECIO DEL BOLETO: %.2f",boleto.saldo_utilizado);
											printf("\nFECHA: %d/%d/%d | HORARIO: %d:%d",boleto.fecha_boleto.dia, boleto.fecha_boleto.mes, boleto.fecha_boleto.anio, boleto.tiempo_boleto.hora, boleto.tiempo_boleto.minuto);
											printf("\n--------------------------------------\n");
										}
										fread(&boleto,sizeof(boleto),1,archivo_mov);
										}
										if(a==0){
											printf("\nEl usuario %s con DNI: %ld  no registra movimientos", persona.nombre, persona.DNI);
										}
									fclose(archivo_mov);
									}else{
										printf("Error de apertura del archivo 'movimientos'\n");
									}
							
						}
						fread(&persona,sizeof(persona),1,archivo);	
					}
					if(b==0){
						printf("No se ha encontrado el nombre");
						}
					fclose(archivo);
				}
				else{
				printf("Error de apertura de archivo usuarios");
				}
			getch();
			system("cls");
			volver_consultas();
			break;
		
		case 5:
			
			// Obtener el mes por teclado
		    printf("Ingrese el mes (1-12): ");
		    scanf("%d", &mes);
		
		    // Abrir el archivo binario de movimientos
		    arch7 = fopen("movimientos.dat", "rb");
		    if (arch7 == NULL) {
		        perror("Error al abrir el archivo de movimientos");
		    }
		
		    // Abrir el archivo binario de choferes
		    arch8 = fopen("choferes.dat", "rb");
		    if (arch8 == NULL) {
		        perror("Error al abrir el archivo de choferes");
		        fclose(arch7);
		    }
		
		    // Abrir el archivo binario de colectivos
		    arch9 = fopen("colectivos.dat", "rb");
		    if (arch9 == NULL) {
		        perror("Error al abrir el archivo de colectivos");
		        fclose(arch7);
		        fclose(arch8);
		    }
		
		    // Leer los datos de los choferes desde el archivo 'choferes.dat'
		    for (int i = 0; i < 18; i++) {
		        fread(&chofer2[i], sizeof(chofer2), 1, arch8);
		    }
		
		    // Leer los datos de los colectivos
		    for (int i = 0; i < 18; i++) {
		        fread(&colectivo2[i], sizeof(colectivo2), 1, arch9);
		    }
		
		    // Leer los datos de los boletos y contar pasajeros por chofer en el mes especificado
		    while (fread(&boleto, sizeof(boleto), 1, arch7) == 1) {
		        if (boleto.fecha_boleto.mes == mes) {
		            int indiceChofer = -1;
		
		            // Encontrar el índice del chofer correspondiente al colectivo y turno
		            for (int i = 0; i < 18; i++) {
		                if ((boleto.viaje == colectivo2[boleto.viaje - 1].nro_unidad) &&
		                    (boleto.tiempo_boleto.hora >= 0 && boleto.tiempo_boleto.hora < 12) && (colectivo2[boleto.viaje - 1].turno == 1)) {
		                    indiceChofer = i;
		                    break;
		                } else if ((boleto.viaje == colectivo2[boleto.viaje - 1].nro_unidad) &&
		                           (boleto.tiempo_boleto.hora >= 12 && boleto.tiempo_boleto.hora < 24) && (colectivo2[boleto.viaje - 1].turno == 2)) {
		                    indiceChofer = i;
		                    break;
		                }
		            }
		
		            if (indiceChofer != -1) {
		                contadorPasajeros[indiceChofer]++;
		            }
		        }
		    }
		
		    // Encontrar el chofer con más pasajeros
		    for (int i = 0; i < 18; i++) {
		        if (contadorPasajeros[i] > maxPasajeros) {
		            maxPasajeros = contadorPasajeros[i];
		            DNI_maxPasajeros = chofer2[i].DNI;
		            char name[30];
					strcpy(name,chofer.nombre);
		        }
		    }
		    
		    // Mostrar el resultado
		    
		    printf("El chofer con mas pasajeros en el mes %d es el/la chofer %s con DNI: %ld\n", mes, name, DNI_maxPasajeros);
		
		    // Cerrar los archivos
		    fclose(arch7);
		    fclose(arch8);
		    fclose(arch9);
			
			getch();
			system("cls");
			volver_consultas();
			break;
			
		case 6:
			system("cls");
			if ((arch6 = fopen("movimientos.dat", "rb")) != NULL) {
			    fread(&boleto, sizeof(boleto), 1, arch6);
			
			    while (!feof(arch6)) {
			        if (boleto.viaje == 1 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 1 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 2 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 2 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 3 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 3 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 4 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 4 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 5 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 5 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 6 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 6 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 7 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 7 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 8 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 8 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
			        if (boleto.viaje == 9 && boleto.tiempo_boleto.hora < 13) {
			            cont1m++;
			        } else if (boleto.viaje == 9 && boleto.tiempo_boleto.hora >= 13) {
			            cont1t++;  
			        }
				fread(&boleto, sizeof(boleto), 1, arch6);
				}
			    fclose(arch6);
			}
			//printf("%d",cont1m);
			//printf("%d",cont1t);
			
			float cont_total=cont1m+cont1t;
			
			float contprom=(cont1m*100)/cont_total;
				
			printf("El promedio de viajes a la maniana es del %.2f porciento\n",contprom);
			getch();
			system("cls");
			volver_consultas();
			
			break;
		
		case 7: 
			system("cls");
			archivo = fopen("usuarios.dat", "r+b");
    		if (archivo == NULL) {
        		printf("No se pudo abrir el archivo.\n");
    		}else{
				fread(&persona,sizeof(persona),1,archivo);
   				while(!feof(archivo)){
        			if (persona.tipo!=1){
        				cont++;
					}
              		fread(&persona,sizeof(persona),1,archivo);
   				}  
				printf("Existe/en %d Usuario/s con beneficio/s.\n",cont);
				printf("\n Pulse Enter para continuar");
				fclose(archivo);
			}
			getch();
			system("cls");
			volver_consultas();
			break;
		
		case 8:
			system("cls");
					 
	       	do{
		   	 	printf("Ingrese su DNI: ");
		   		scanf("%ld", &dnichof);
		   		auxi=0;
		   		c=0;
		    
		   		if((arch4 = fopen("choferes.dat","rb")) != NULL) {
		    		fread(&chofer,sizeof(chofer),1,arch4);
		      		while(!feof(arch4)){
		    
		           		if(dnichof == chofer.DNI && c==0) {
		                printf("El DNI ya esta en uso. Intente de nuevo \n");
		               	auxi=1;
		               	c=1;
		              
		           		}	
						fread(&chofer,sizeof(chofer),1,arch4);	
		        	}
		       
		       	fclose(arch4);
		   		}
	        
	    	}while(auxi==1);
	    	
	    	chofer.DNI=dnichof;
	       	
  			arch4 = fopen("choferes.dat", "ab");

   			if (arch4 == NULL) {
     			printf("No se pudo abrir el archivo.\n");
       			break;
 			}

	        getchar();
	        printf("Ingrese el nombre del chofer: " );
	        fflush(stdin);
	        gets(chofer.nombre);
	        printf("Ingrese la fecha de nacimiento del chofer (dia): ");
	        scanf("%d",&chofer.fecha_nacimiento.dia);
	        printf("Ingrese la fecha de nacimiento del chofer (mes): ");
	        scanf("%d", &chofer.fecha_nacimiento.mes);
	        printf("Ingrese la fecha de nacimiento del chofer (anio): " );
	        scanf("%d",&chofer.fecha_nacimiento.anio);
	        getchar();
	        printf("Ingrese la direccion del chofer: ");
	        fflush(stdin);
	        gets(chofer.direccion);
	        printf("Ingrese el telefono del chofer: ");
	        scanf("%lld", &chofer.telefono);
	        getchar();
	        printf("Ingrese el email del chofer: ");
	        fflush(stdin);
	        gets(chofer.email);

        	fwrite(&chofer, sizeof(chofer ), 1, arch4);
        	printf("\n--------------------------------------");
        	printf("\nLos datos de chofer ingresados son los siguientes:\n");
        	printf("NOMBRE: %s",chofer.nombre);
        	printf("\nDNI: %ld",chofer.DNI);
        	printf("\nTELEFONO: %lld",chofer.telefono);
        	printf("\nFECHA DE NACIMIENTO: %d/%d/%d",chofer.fecha_nacimiento.dia, chofer.fecha_nacimiento.mes, chofer.fecha_nacimiento.anio);
        	printf("\nEMAIL: %s",chofer.email);
        	printf("\n--------------------------------------\n");
   		 	fclose(arch4);
   		 	getchar();
   		 	system("cls");
			volver_consultas();
			break; 
		
		case 9:
			system("cls");		 
  			arch5 = fopen("colectivos.dat", "ab");

   			if (arch5 == NULL) {
     			printf("No se pudo abrir el archivo.\n");
       			break;
 			}

		   	printf("Ingrese el numero de unidad del colectivo: ");
		   	scanf("%ld",&colectivo.nro_unidad);
			printf("Ingrese el DNI del chofer: ");
			scanf("%ld",&colectivo.DNIC);
			printf("Ingrese el turno: ");
			scanf("%d",&colectivo.turno);
			getchar();
			printf("Ingrese la marca del colectivo: ");
			fflush(stdin);
			gets(colectivo.marca);
			printf("Ingrese el modelo del colectivo: ");
			fflush(stdin);
			gets(colectivo.modelo);
			printf("Infrese la cantidad de asientos que tiene el colectivo: ");
			scanf("%d",&colectivo.asientos);
			printf("Ingrese el km: ");
			scanf("%fd",&colectivo.kilometraje);
			printf("Ingrese la fecha de alta(dia): ");
			scanf("%d",&colectivo.fecha_alta.dia);
		    printf("Ingrese la fecha de alta (mes): ");
		    scanf("%d", &colectivo.fecha_alta.mes);
		    printf("Ingrese la fecha de alta (anio): " );
			scanf("%d",&colectivo.fecha_alta.anio);
		    printf("Ingrese si es apto para discapacitados SI[1] | NO[0] ");
		    scanf("%d",&colectivo.discapacidad);
		    
        	fwrite(&colectivo, sizeof(colectivo ), 1, arch5);
			printf("\n--------------------------------------");
			printf("NRO UNIDAD: %ld", colectivo.nro_unidad);
			printf("\nTURNO: %ld", colectivo.turno);
			printf("\nDNI CHOFER: %ld", colectivo.DNIC);
			printf("\nMARCA: %ld", colectivo.marca);
			printf("\nMODELO: %s", colectivo.modelo);
			printf("\nFECHA DE ALTA: %d/%d/%d", colectivo.fecha_alta.dia, colectivo.fecha_alta.mes, colectivo.fecha_alta.anio);
			printf("\nKILOMETRAJE: %ld", colectivo.kilometraje);
			printf("\nNRO DE ASIENTOS: %d", colectivo.asientos);
			printf("\nHABILITADO PARA DISCAPACITADOS: %ld", colectivo.discapacidad);
			printf("\n--------------------------------------\n");
   		 	fclose(arch5);
   		 	getch();
			system("cls");
			volver_consultas();
			break;
		
		case 0: 
			system("cls");
			printf("\n");
			volver_consultas();
			break;
	}
	 
}

void volver_consultas(){
	int opcion;
	
	printf("Desea volver al Menu de inicio o salir del programa?\n");
	printf("Menu de inicio [1] || Salir [0]\n");
	printf("Elija la opcion que desea: ");
	scanf("%d", &opcion);
	if(opcion==1){
		main();
	}else if(opcion==0){
		printf("\nPrograma finalizado\n");
		exit(1);
	}else{
		printf("La opcion ingresada es incorrecta\n");
	}
	system("cls");
}

void listar_recarga(){
	FILE *archivo;
	long dni;
	
	printf("Ingrese un DNI: ");
	scanf("%ld",&dni);
	if((archivo=fopen("recarga.dat","rb"))!=NULL){
		fread(&recarga,sizeof(recarga),1,archivo);
		while(!feof(archivo)){
			if(dni==recarga.DNI_recarga){
				printf("\n--------------------------------------\n");
				printf("DNI: %ld", dni);
				printf("\nMONTO: %.2f", recarga.monto);
				printf("\nNRO CONTROL: %d", recarga.num_con);
				printf("\nBOCA DE PAGO: %s",recarga.boca);
				printf("\nFecha y hora: %s", recarga.buffer);
				printf("\n--------------------------------------\n");
			}
			fread(&recarga,sizeof(recarga),1,archivo);
		}
		fclose(archivo);
	}else{
		printf("Error de apertura de archivo");
	}
	getch();
	system("cls");
	volver_consultas();
}

void hora_actual_boleto(){
 
	printf("\n\nIngrese la hora actual (HH/MM)\n");
	printf("Ingrese la hora: ");
	scanf("%d",&boleto.tiempo_boleto.hora);

	while(boleto.tiempo_boleto.hora<0 || boleto.tiempo_boleto.hora>23){
		printf("\nHora no valida, ingrese otra vez: ");
		scanf("%d",&boleto.tiempo_boleto.hora);
	}

	printf("Ingrese los minutos: ");
	scanf("%d",&boleto.tiempo_boleto.minuto);
	while(boleto.tiempo_boleto.minuto<0 || boleto.tiempo_boleto.minuto>59){
		printf("\nMinuto no valido, ingreselo otra vez: ");
		scanf("%d",&boleto.tiempo_boleto.minuto);
	}
	
	//return boleto.tiempo_boleto.hora;
}

void fecha_boleto(){

	printf("Ingrese la fecha de hoy (DD/MM/AAAA):\n");
	printf("Ingrese el dia: ");
	scanf("%d", &boleto.fecha_boleto.dia);
	while(boleto.fecha_boleto.dia<1 || boleto.fecha_boleto.dia>31){
		printf("\nDia no valido, ingreselo otra vez: ");
		scanf("%d",&boleto.fecha_boleto.dia);
	}
	
	printf("Ingrese el mes: ");
	scanf("%d", &boleto.fecha_boleto.mes);
	while(boleto.fecha_boleto.mes<1 || boleto.fecha_boleto.mes>12){
		printf("\nMes no valido, ingreselo otra vez: ");
		scanf("%d",&boleto.fecha_boleto.mes);
	}
	
	printf("Ingrese el anio: ");
	scanf("%d", &boleto.fecha_boleto.anio);
	while(boleto.fecha_boleto.anio>2023){
		printf("\nAnio no valido, ingreselo otra vez: ");
		scanf("%d",&boleto.fecha_boleto.anio);
	}
}

void movimientos_fecha(){
	
	FILE *archivo;
	struct Fecha fecha_inicio, fecha_fin;
	//puts("HOLA1");
	if((archivo=fopen("movimientos.dat","rb"))!=NULL){
		//puts("HOLA2");
		fread(&boleto, sizeof(boleto), 1, archivo);
		
		printf("Ingrese la primer fecha (DD/MM/AAAA):\n");
		printf("Ingrese el dia: ");
		scanf("%d", &fecha_inicio.dia);
		while(fecha_inicio.dia<1 || fecha_inicio.dia>31){
			printf("\nDia no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_inicio.dia);
		}
		
		printf("Ingrese el mes: ");
		scanf("%d", &fecha_inicio.mes);
		while(fecha_inicio.mes<1 || fecha_inicio.mes>12){
			printf("\nMes no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_inicio.mes);
		}
		
		printf("Ingrese el anio: ");
		scanf("%d", &fecha_inicio.anio);
		while(fecha_inicio.anio>2023){
			printf("\nAnio no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_inicio.anio);
		}
		
		printf("\nIngrese la segunda fecha (DD/MM/AAAA):\n");
		printf("Ingrese el dia: ");
		scanf("%d", &fecha_fin.dia);
		while(fecha_fin.dia<1 || fecha_fin.dia>31){
			printf("\nDia no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_fin.dia);
		}
		
		printf("Ingrese el mes: ");
		scanf("%d", &fecha_fin.mes);
		while(fecha_fin.mes<1 || fecha_fin.mes>12){
			printf("\nMes no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_fin.mes);
		}
		
		printf("Ingrese el anio: ");
		scanf("%d", &fecha_fin.anio);
		while(fecha_fin.anio>2023){
			printf("\nAnio no valido, ingreselo otra vez: ");
			scanf("%d",&fecha_fin.anio);
		}
		
		while(!feof(archivo)){
			//puts("HOLA3");
        	if ((boleto.fecha_boleto.anio > fecha_inicio.anio || (boleto.fecha_boleto.anio== fecha_inicio.anio && boleto.fecha_boleto.mes > fecha_inicio.mes ) ||
             (boleto.fecha_boleto.anio== fecha_inicio.anio && boleto.fecha_boleto.mes == fecha_inicio.mes&& boleto.fecha_boleto.dia >= fecha_inicio.dia)) &&
            (boleto.fecha_boleto.anio < fecha_fin.anio || (boleto.fecha_boleto.anio == fecha_fin.anio && boleto.fecha_boleto.mes < fecha_fin.mes) ||
             (boleto.fecha_boleto.anio == fecha_fin.anio && boleto.fecha_boleto.mes == fecha_fin.mes && boleto.fecha_boleto.dia
 				<= fecha_fin.dia))){
 					//puts("HOLA4");
            	
            	printf("\n--------------------------------------");
				printf("\nDNI: %ld",boleto.DNI);
				if(boleto.tipo==1){
					printf("\nSUBE");
					printf("\nNRO TARJETA: %ld",boleto.nro_tarjeta);
				}else if(boleto.tipo==2){
					printf("\nBilletera Electronica");
					printf("\nTELEFONO: %lld",boleto.telefono);
				}
				if(boleto.viaje==1){
					printf("\nVIAJE: Dentro de Posadas\n");
				}else if(boleto.viaje==2){
					printf("\nVIAJE: Dentro de Garupa\n");
				}else if(boleto.viaje==3){
					printf("\nVIAJE: Dentro de Candelaria\n");
				}else if(boleto.viaje==4){
					printf("\nVIAJE: Posadas-Garupa\n");
				}else if(boleto.viaje==5){
					printf("\nVIAJE: Posadas-Candelaria\n");
				}else if(boleto.viaje==6){
					printf("\nVIAJE: Garupa-Posadas\n");
				}else if(boleto.viaje==7){
					printf("\nVIAJE: Garupa-Posadas\n");
				}else if(boleto.viaje==8){
					printf("\nVIAJE: Candelaria-Posadas\n");
				}else if(boleto.viaje==9){
					printf("\nVIAJE: Candelaria-Garupa\n");
				} 
				printf("PRECIO DEL BOLETO: %.2f",boleto.saldo_utilizado);
				printf("\nFECHA: %d/%d/%d | HORARIO: %d:%d",boleto.fecha_boleto.dia, boleto.fecha_boleto.mes, boleto.fecha_boleto.anio, boleto.tiempo_boleto.hora, boleto.tiempo_boleto.minuto);
				printf("\n--------------------------------------\n");
            
        	}
        	fread(&boleto, sizeof(boleto), 1, archivo);
    	}
		 
	}else{
		printf("Error de apertura del archivo 'movimientos'\n");
	}
	getch();
	system("cls");
	volver_consultas();
}