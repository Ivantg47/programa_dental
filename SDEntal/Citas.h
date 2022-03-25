/*
	Progrma: Citas.h
	Autor: Ivan Tronco
	Objetivo: controla todos los registros relacionados con citas
	Version: 1.0
	Fecha: 12/06/19
*/

//Prototipos

void MenuCitas (TaCita aCitas, int *eTotalCit, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
TrCita LeerCita (TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void InsertarCita (TaCita aCitas, int *eTotalCit, TrCita rCita);
int  BuscarCitaPorId (TaCita aCitas, int eTotalCit, int eIdC);
int  GenerarIdCita ();
void MostrarDatosCita (TrCita rCita, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void ConsultarCitaPorId(TaCita aCita, int eTotalCit, int eIdC, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
int  LeerIdCita (char *cOperacion, int eTotalCit, int eUltimoId);
void CancelarCita (TaCita aCita, int *eTotalCit, int eIdC, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void ListarCitaPorId (TaCita aCita, int eTotalCit, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void MenuListadoCita(TaCita aCita, int eTotalCit, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);



void MenuCitas (TaCita aCitas, int *eTotalCit, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){

/*
	Nombre del módulo: Procedimiento MenuCitas
	Autor: Ivan Tronco
	Objetivo: mostrar las opciones a realizar con registro de citas
	Parámetros de entrada: no recibe
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 12/06/19
*/	
	
	int eOps, eId;
	TrCita rCita;
	
		
	do{
		eOps = 0;
		system("cls");
		dibujarMarco();
		centrar(1, "Menu Citas");
		moverCursor(7, 10);
		printf("1. Agendar cita");
		moverCursor(9, 10);
		printf("2. Cancelar cita");
		moverCursor(11, 10);
		printf("3. Consulta de cita");
		moverCursor(13, 10);
		printf("4. Listado de cita");
		moverCursor(15, 10);
		printf("5. Men%c Principal", 163);
		moverCursor(20, 10);
		printf("Seleccione una opci%cn: ", 162);
			
		moverCursor(20, 33);
		fflush(stdin);
		scanf("%d", &eOps);		
			
		
		switch(eOps){
			case 1: //Registrar paciente
					rCita = LeerCita (aPacientes, eTotalPa, aDoctores, eTotalDoc);
					InsertarCita (aCitas, &(*eTotalCit), rCita);
					break;
			case 2: //cancelar cita
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Cancelar cita.");
					if (*eTotalCit == -1){							
						error(16);
					}else{
						eId = LeerIdCita ("cancelar", *eTotalCit, aCitas[*eTotalCit].eIdC);
							
						if (eId > -1){										
							CancelarCita(aCitas, &(*eTotalCit), eId, aPacientes, eTotalPa, aDoctores, eTotalDoc);
						}
					}
					fflush(stdin);
					break;
			case 3: //Consulta de paciente
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Consulta de Paciente.");
					if (*eTotalCit == -1){							
						error(16);
					}else{
						eId = LeerIdCita ("consultar", *eTotalCit, aCitas[*eTotalCit].eIdC);
								
						if (eId > -1){										
							ConsultarCitaPorId(aCitas, *eTotalCit, eId, aPacientes, eTotalPa, aDoctores, eTotalDoc);
						}
					}
					fflush(stdin);
					break;
			case 4: //Listado de Pacientes
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Listado de Citas.");
					if (*eTotalCit == -1){							
						error(16);
					}else{
						borrar(4, 4, 76, 25);
						moverCursor(4, 6);
						printf("%c Id C. %c Nombre del paciente    %c Doctor     %c Fecha      %c Hora  %c",179, 179, 179, 179, 179, 179);	
						ListarCitaPorId(aCitas, *eTotalCit, aPacientes, eTotalPa, aDoctores, eTotalDoc);
						fflush(stdin);
						moverCursor(29,20);
						system("pause");
						borrar(1, 27, 79, 29);
					}
					break;
			case 5: //regresa al menu principal	
					break;
			default:
				  	 error(15);
				  	 break;
					
		}
			
		
	}while(eOps != 5);
}

TrCita LeerCita (TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo:  Funcion  LeerPaciente
	Autor: Ivan Tronco
	Objetivo: leer los datos del paciente y generar un Id 
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: registro del paciente (rCita)
	Fecha de creación: 07/06/19
*/	
	TrCita rCita;
		
	system("cls");
	dibujarMarco();
	
	centrar(1, "Sistema Dental. Registro de Cita.");
	moverCursor(4, 15);
	printf("Id Paciente:");
	moverCursor(6, 17);
	printf("Id Doctor:");
	moverCursor(8, 13);
	printf("Fecha de Cita:");
	moverCursor(10, 14);
	printf("Hora de Hora:");
	
	moverCursor(28, 20);
	printf("Ingrese los datos de la cita.");
		
 
	do{						// Solicita apellido paterno
			
		borrar(30, 4, 76, 4);
		moverCursor(4,30);
		fflush(stdin);
		scanf("%d", &rCita.eIdP);
			
	}while(BuscarPacientePorId(aPacientes, eTotalPa, rCita.eIdP) != 0);
	
		
	do{						// Solicita apellido materno
			
		borrar(30, 6, 76, 6);
		moverCursor(6,30);
		fflush(stdin);
		scanf("%d", &rCita.eIdD);
			
	}while(BuscarDoctorPorId(aDoctores, eTotalDoc, rCita.eIdD) != 0);
		
	do{						// Solicita apellido materno
			
		borrar(30, 8, 76, 8);
		moverCursor(8,30);
		fflush(stdin);
		scanf("%d/%d/%d", &rCita.rFecha.eDia, &rCita.rFecha.eMes, &rCita.rFecha.eAnio);
		
	}while(validarFecha(rCita.rFecha) != 0);
		
	do{						// Solicita fecha nacimiento
			
		borrar(30, 10, 76, 10);		
		moverCursor(10,30);
		fflush(stdin);
		scanf("%d:%d", &rCita.rHora.eHora, &rCita.rHora.eMin);
		
	}while( validarHora(rCita.rHora) != 0);
		
	
	rCita.eIdC = GenerarIdCita ();
		
	return rCita;	
	
}

void InsertarCita (TaCita aCitas, int *eTotalCit, TrCita rCita){
/*
	Nombre del módulo: Procedimiento InsertarCita
	Autor: Ivan Tronco
	Objetivo: intertar el registro de paciente al arreglo de pacientes 
	Parámetros de entrada: aPaciente, rPaciente, eTotal
	Parámetros de salida: eTotal
	Valor que retorna:
	Fecha de creación: 07/06/19
*/

	int eRecorre;
	
	if(*eTotalCit == MAX_CITAS - 1) {
		borrar(1, 27, 79, 29);
		moverCursor(28, 38);
		printf("No se pueden agregar m%cs citas", 160);
	
	} else {
		
		if(*eTotalCit == -1 || rCita.eIdC > aCitas[*eTotalCit].eIdC)	{
		
			(*eTotalCit)++;
			aCitas[*eTotalCit] = rCita;
			
			borrar(1, 27, 79, 29);
			moverCursor(28, 15);
			printf("Cita %003d a las %02d:%02d del %02d/%02d/%d registrada correctamente", rCita.eIdC, rCita.rHora.eHora, rCita.rHora.eMin, 
					rCita.rFecha.eDia, rCita.rFecha.eMes, rCita.rFecha.eAnio);
		
		} else {
		
			if(BuscarCitaPorId(aCitas, *eTotalCit, rCita.eIdC) != -1) {
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 7);
				printf("Ya existe %d", rCita.eIdC);
		
			} else {
				
				eRecorre = *eTotalCit;
				while (eRecorre >= 0 && aCitas[eRecorre].eIdC > rCita.eIdC){
					aCitas[eRecorre + 1] = aCitas[eRecorre];
					eRecorre--;
				}
				aCitas[eRecorre + 1] = rCita;
				(*eTotalCit)++;
				
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 15);
				printf("Cita %003d a las %02d:%02d del %02d/%02d/%d registrada correctamente", rCita.eIdC, rCita.rHora.eHora, rCita.rHora.eMin, 
						rCita.rFecha.eDia, rCita.rFecha.eMes, rCita.rFecha.eAnio);
			}
		}
	} 
	fflush(stdin);
	getchar();
} //InsertarPaciente

int BuscarCitaPorId (TaCita aCitas, int eTotalCit, int eIdC){
/*
	Nombre del módulo:  Funcion  BuscarCitaPorId
	Autor: Ivan Tronco
	Objetivo: buscar Id e indicar la posision del arreglo en de un paciente
	Parámetros de entrada: aPaciente, eTotal, eIdP
	Parámetros de salida: no recibe
	Valor que retorna: la posicion en el arreglo (eMedio)
	Fecha de creación: 07/06/19
*/	
	int eMenor, eMayor, eMedio;
	
	if(eTotalCit == -1 ){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotalCit;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && aCitas[eMedio].eIdC != eIdC){
			
			if( eIdC < aCitas[eMedio].eIdC){
				eMayor = eMedio - 1;
			} else {
				eMenor = eMedio + 1;
			}
			
			eMedio = (eMayor + eMenor) / 2;
		}
		
		if ( eIdC == aCitas[eMedio].eIdC){
			return eMedio;
		} else{
			return -1;
		}
	}
} //BuscarCitaPorId

int GenerarIdCita (){
/*
	Nombre del módulo:  Funcion GenerarIdPaciente
	Autor: 
	Objetivo: generar un id
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eSiguiente)
	Fecha de creación: 07/06/19
*/	
	static int eCit = 1;
	
	return (eCit++);
} //GenerarIdPaciente

void MostrarDatosCita (TrCita rCita, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento MostrarDatosCita
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un Cita
	Parámetros de entrada: rPaciente
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/	
	char cSangre[3];
	
	borrar(4, 4, 76, 25);
	moverCursor(4, 8); 
	printf("Datos de la cita: %003d ", rCita.eIdC);
	

	moverCursor(7, 15);
	printf("Paciente: %s %s", aPacientes[rCita.eIdP - 1].cPaterno, aPacientes[rCita.eIdP - 1].cMaterno);
	moverCursor(9, 17);
	printf("Doctor: %s", aDoctores[rCita.eIdD - 1].cPaterno);
	moverCursor(11, 10);
	printf("Fecha de Cita: %02d/%02d/%d", rCita.rFecha.eDia, rCita.rFecha.eMes, rCita.rFecha.eAnio);
	moverCursor(13, 11);
	printf("Hora de Cita: %02d:%02d", rCita.rHora.eHora, rCita.rHora.eMin);
	
} //MostrarDatosCita

void ConsultarCitaPorId(TaCita aCita, int eTotalCit, int eIdC, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento ConsultarPacientePorId
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un cita mediante su Id
	Parámetros de entrada: aCita, eTotal, eId
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/
	int ePos;

	ePos = BuscarCitaPorId(aCita, eTotalCit, eIdC);
	
	if (ePos > -1){
	
		MostrarDatosCita(aCita[ePos], aPacientes, eTotalPa, aDoctores, eTotalDoc);	
		moverCursor(28, 7);
		system("pause");
		
	} else {
		borrar(1, 27, 79, 29);
		printf("%c", 07);
		moverCursor(28, 7);
		printf("No se encontr%c el id %d", 162, eIdC);
		moverCursor(29,20);
		system("pause");
		borrar(1, 27, 79, 29);
	}
} //ConsultarCitaPorId

int LeerIdCita (char *cOperacion, int eTotalCit, int eUltimoId){
/*
	Nombre del módulo: Funcion LeerIdCita
	Autor: Ivan Tronco
	Objetivo: leer y validar un Id
	Parámetros de entrada: cOperacion, eTotal, eUltimoId
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eIdC)
	Fecha de creación: 12/06/19
*/		
	int eIdC;
		
	if (eTotalCit == -1) {
		
		error(16);
		return -1;
		
	} else {

		do {
			borrar(4, 4, 76, 25);
			moverCursor(5, 7);
			printf("Ingrese el id de la cita a %s [0 = salir]: ", cOperacion);
			fflush(stdin);
			scanf("%d", &eIdC);
			
			if (eIdC == 0){
				
				return eIdC = -1;
				
			}else if (eIdC < 1 || eIdC > eUltimoId){
				
				borrar(1, 27, 79, 29);
				printf("%c", 07);
				moverCursor(27,31);
				printf("No existe el id %003d.", eIdC);
				moverCursor(29,20);
				system("pause");
				
			}
		
		} while (eIdC < 1 || eIdC > eUltimoId);
	
		return eIdC;
	} 
} //LeerIdCita

void CancelarCita (TaCita aCita, int *eTotalCit, int eIdC, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento CancelarCita
	Autor: Ivan Tronco
	Objetivo: elminar un paciente del registro
	Parámetros de entrada: aCita, eTotal, eId
	Parámetros de salida: aCita, eTotal
	Valor que retorna: 
	Fecha de creación: 09/06/19
*/	
	int ePos, eRecorre;
	char cConfirma; 
	
	if (*eTotalCit == -1){
		
		error(16);
		
	} else {
		
		ePos = BuscarCitaPorId(aCita, *eTotalCit, eIdC);
		
		if (ePos == -1) {
			
			moverCursor(28,20);
			printf("El id %d no existe.", eIdC);
			moverCursor(29,20);
			system("pause");
			borrar(1, 27, 79, 29);
					
		} else {

			MostrarDatosCita(aCita[ePos], aPacientes, eTotalPa, aDoctores, eTotalDoc);
			
			moverCursor(19,20);
			printf("%cDesea borrar el registro?[S/N]: ", 168);
			fflush(stdin);
			cConfirma = getchar(); 
			
			if (cConfirma == 's' || cConfirma == 'S'){
			
				for (eRecorre = ePos; eRecorre < *eTotalCit; eRecorre++){
					
					aCita[eRecorre] = aCita[eRecorre + 1];
				}
				
				(*eTotalCit)--;
				escribirMensaje("Paciente borrado correctamente", 28);
				moverCursor(29,20);
				system("pause");
				borrar(1, 27, 79, 29);
			}
		}
	}
} //CancelarCita 

void ListarCitaPorId (TaCita aCita, int eTotalCit, TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){	
/*
	Nombre del módulo: Procedimiento ListarCitaPorId
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden acendente de id 
	Parámetros de entrada: aPaciente, eTotal
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 12/06/19
*/	
	static int eRen = 5;
	int eIdC;
	
	eIdC = BuscarCitaPorId (aCita, eTotalCit, eIdC);
		
	if (eTotalCit != -1){
		
		ListarCitaPorId(aCita, eTotalCit - 1, aPacientes, eTotalPa, aDoctores, eTotalDoc);
        
		moverCursor(eRen, 6);        
		printf("%c  %003d", 179, aCita[eTotalCit].eIdC);
		moverCursor(eRen, 14);
		printf("%c %s %s",179, aPacientes[aCita[eTotalCit].eIdP - 1].cPaterno, aPacientes[aCita[eTotalCit].eIdP - 1].cMaterno); 
		moverCursor(eRen, 39); 
		printf("%c %s",179, aDoctores[aCita[eTotalCit].eIdD - 1].cPaterno);
		moverCursor(eRen, 52);
		printf("%c %02d/%02d/%0004d",179, aCita[eTotalCit].rFecha.eDia, aCita[eTotalCit].rFecha.eMes, aCita[eTotalCit].rFecha.eAnio);
		moverCursor(eRen, 65);
		printf("%c %02d:%02d %c",179, aCita[eTotalCit].rHora.eHora, aCita[eTotalCit].rHora.eMin, 179);
		
		(eRen++);
		
	}
	
	if(eTotalCit < 0){
		eRen = 5;
	}
	
} //ListarCitaPorId

