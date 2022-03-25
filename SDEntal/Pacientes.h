/*
	Progrma: Pacientes.h
	Autor: Ivan Tronco
	Objetivo: controla todos los registros relacionados con pacientes 
	Version: 1.6
	Fecha: 12/06/19
*/

//Prototipos

void MenuPacientes (TaPacientes aPacientes, int *eTotalPa, TaDoctores aDoctores, int eTotalDoc);
TrPaciente LeerPaciente ();
void InsertarPaciente (TaPacientes aPacientes, int *eTotalPa, TrPaciente rPaciente);
int  BuscarPacientePorId (TaPacientes aPacientes, int eTotalPa, int eIdP);
int  GenerarIdPaciente ();
void ListarPacientesPorId (TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void ObtenerTipoSangre  (int eSangre, char *cSangre);
void MostrarDatosPaciente (TrPaciente rPaciente, TaDoctores aDoctores, int eTotalDoc);
void ConsultarPacientePorId (TaPacientes aPacientes, int eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc);
int  LeerIdPaciente (char *cOperacion, int eTotalPa, int eUltimoId);
void ModificarPaciente(TaPacientes aPacientes, int eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc);
void BorrarPaciente (TaPacientes aPacientes, int *eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc);
int  BuscarPorApellido(TaPacientes aPacientes, int eTotalPa, char *cOperacion);
int  MenuBuscarPaciente(TaPacientes aPacientes, int eTotalPa, char *cOperacion);
void LeerApellidoPaciente (char *cOperacion, int eTotalPa, TaCadena *cApellido);
void MenuListadoPaciente(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void OrdenamientoBurbujaPorApellido(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void ListarPorApellido(TaPacientes aPacienteAp, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void OrdenamientoBurbujaPorDoctor(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);
void ListarPorDoctor(TaPacientes aPacienteAp, int eTotalPa, TaDoctores aDoctores, int eTotalDoc);



void MenuPacientes (TaPacientes aPacientes, int *eTotalPa, TaDoctores aDoctores, int eTotalDoc){

/*
	Nombre del módulo: Procedimiento MenuPacientes
	Autor: Ivan Tronco
	Objetivo: mostrar las opciones a realizar con registro de pacientes 
	Parámetros de entrada: no recibe
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 05/06/19
*/	
	
	int eOps, eId;
	TrPaciente rPaciente;
	
		
	do{
		eOps = 0;
		system("cls");
		dibujarMarco();
		centrar(1, "Menu Pacientes");
		moverCursor(7, 10);
		printf("1. Registrar paciente");
		moverCursor(9, 10);
		printf("2. Actualizar datos de paciente");
		moverCursor(11, 10);
		printf("3. Baja  de paciente");
		moverCursor(13, 10);
		printf("4. Consulta de paciente");
		moverCursor(15, 10);
		printf("5. Listado de Pacientes");
		moverCursor(17, 10);
		printf("6. Men%c Principal", 163);
		moverCursor(22, 10);
		printf("Seleccione una opci%cn: ", 162);
			
		moverCursor(22, 33);
		fflush(stdin);
		scanf("%d", &eOps);		
			
		
		switch(eOps){
			case 1: //Registrar paciente
					rPaciente = LeerPaciente(aDoctores, eTotalDoc);
					InsertarPaciente (aPacientes, &(*eTotalPa), rPaciente);
					break;
			case 2: //Modificar datos de paciente							
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Actualizar datos de Paciente.");
					if (*eTotalPa == -1){							
						error(16);
					}else{
						eId = MenuBuscarPaciente(aPacientes, *eTotalPa, "actualizar");
							
						if (eId > -1){										
							ModificarPaciente(aPacientes, *eTotalPa, eId, aDoctores, eTotalDoc);
						}
					}
					fflush(stdin);
					break;
			case 3: //Baja  de paciente
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Baja de Paciente.");
					if (*eTotalPa == -1){							
						error(16);
					}else{
						eId = MenuBuscarPaciente(aPacientes, *eTotalPa, "borrar");
							
						if (eId > -1){										
							BorrarPaciente(aPacientes, &(*eTotalPa), eId, aDoctores, eTotalDoc);
						}
					}
					fflush(stdin);
					break;
			case 4: //Consulta de paciente
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Consulta de Paciente.");
					if (*eTotalPa == -1){							
						error(16);
					}else{
						eId = MenuBuscarPaciente(aPacientes, *eTotalPa, "consultar");
								
						if (eId > -1){										
							ConsultarPacientePorId(aPacientes, *eTotalPa, eId, aDoctores, eTotalDoc);
						}
					}
					fflush(stdin);
					break;
			case 5: //Listado de Pacientes
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Listado de Pacientes.");
					if (*eTotalPa == -1){							
						error(16);
					}else{
						MenuListadoPaciente(aPacientes, *eTotalPa, aDoctores, eTotalDoc);
					}
					break;
			case 6: //regresa al menu principal	
					break;
					
			default:
				  	 error(15);
				  	 break;
					
		}
			
		
	}while(eOps != 6);
}

TrPaciente LeerPaciente (){
/*
	Nombre del módulo:  Funcion  LeerPaciente
	Autor: Ivan Tronco
	Objetivo: leer los datos del paciente y generar un Id 
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: registro del paciente (rPaciente)
	Fecha de creación: 07/06/19
*/	
	TrPaciente rPaciente;
	char cSangre[3];
		
	system("cls");
	dibujarMarco();
	
	centrar(1, "Sistema Dental. Registro de Paciente.");
	moverCursor(4, 10);
	printf("Apellido Paterno:");
	moverCursor(6, 10);
	printf("Apellido Materno:");
	moverCursor(8, 19);
	printf("Nombres:");
	moverCursor(10, 7);
	printf("Fecha de Nacimiento:");
	moverCursor(12, 17);
	printf("Sexo[F/M]:");
	moverCursor(14, 12);
	printf("Tipo de Sangre:");
	moverCursor(16, 17);
	printf("ID Doctor:");
	moverCursor(18, 17);
	printf("Domicilio:");
	moverCursor(20, 18);
	printf("Telefono:");
	moverCursor(22, 7);
	printf("Telefono Emergencia:");
	moverCursor(24, 23);
	printf("RFC:");
	moverCursor(28, 27);
	printf("Ingrese los datos del paciente.");
		
 
	do{						// Solicita apellido paterno
			
		borrar(30, 4, 76, 4);
		moverCursor(4,30);
		fflush(stdin);
		gets(rPaciente.cPaterno);
			
	}while(validarApellido(rPaciente.cPaterno) != 0);
	
		
	do{						// Solicita apellido materno
			
		borrar(30, 6, 76, 6);
		moverCursor(6,30);
		fflush(stdin);
		gets(rPaciente.cMaterno);
			
	}while(validarApellido(rPaciente.cMaterno) != 0);
		
	do{						// Solicita apellido materno
			
		borrar(30, 8, 76, 8);
		moverCursor(8,30);
		fflush(stdin);
		gets(rPaciente.cNombre);
		
	}while(validarApellido(rPaciente.cNombre) != 0);
		
	do{						// Solicita fecha nacimiento
			
		borrar(30, 10, 76, 10);		
		moverCursor(10,30);
		fflush(stdin);
		scanf("%d/%d/%d", &rPaciente.rFecha.eDia, &rPaciente.rFecha.eMes, &rPaciente.rFecha.eAnio);
		
	}while(validarFecha(rPaciente.rFecha) != 0);
		
	do{						// Solicita sexo
			
		borrar(30, 12, 76, 12);		
		moverCursor(12,30);
		fflush(stdin);
		scanf("%c", &rPaciente.cSexo);
		
	}while(validarSexo(rPaciente.cSexo) == '1');
		
	do{						// Solicita tipo de sangre
		borrar(1, 27, 79, 29);
		escribirMensaje("1 = O+, 2 = O-, 3 = A+, 4 = A-, 5 = B+, 6 = B-, 7 = AB+, 8 = AB-", 29);	
		borrar(30, 14, 76, 14);		
		moverCursor(14,30);
		fflush(stdin);
		scanf("%d", &rPaciente.eTSangre);
		if(rPaciente.eTSangre < 0 || rPaciente.eTSangre > 9){
			error(17);
		}
			
	}while(rPaciente.eTSangre < 0 || rPaciente.eTSangre > 9);
	
	borrar(1, 27, 79, 29);
	ObtenerTipoSangre(rPaciente.eTSangre, cSangre);
	borrar(30, 14, 76, 14);
	moverCursor(14,30);
	printf("%s", cSangre);

	
	do{						// Solicita ID doctor
			
		borrar(30, 16, 76, 16);
		moverCursor(16,30);
		fflush(stdin);
		scanf("%d", &rPaciente.eIdD);
		
	}while(rPaciente.eIdD <= 0);	
		
	do{						// Solicita domicilio
			
		borrar(30, 18, 76, 18);
		moverCursor(18,30);
		fflush(stdin);
		gets(rPaciente.cDomicilio);
			
	}while(validarLongitudeCadena(rPaciente.cDomicilio, 30) != 0);
		
	do{						// Solicita telefono
			
		borrar(30, 20, 76, 20);
		moverCursor(20,30);
		fflush(stdin);
		gets(rPaciente.cTelCel);
			
	}while(validarTelefono(rPaciente.cTelCel) != 0);
		
	do{						// Solicita telefono
			
		borrar(30, 22, 76, 22);
		moverCursor(22,30);
		fflush(stdin);
		gets(rPaciente.cEmer);
			
	}while(validarTelefono(rPaciente.cEmer) != 0);
	
	do{						// Solicita RFC
			
		borrar(30, 24, 76, 24);
		moverCursor(24,30);
		fflush(stdin);
		gets(rPaciente.cRFC);
			
	}while(validarRFC(rPaciente.cRFC) != 0);
	
	rPaciente.eIdP = GenerarIdPaciente ();
	//MostrarDatosPaciente(rPaciente, aDoctores, eTotalDoc);		
	return rPaciente;	
	
}

void InsertarPaciente (TaPacientes aPacientes, int *eTotalPa, TrPaciente rPaciente){
/*
	Nombre del módulo: Procedimiento InsertarPaciente
	Autor: Ivan Tronco
	Objetivo: intertar el registro de paciente al arreglo de pacientes 
	Parámetros de entrada: aPaciente, rPaciente, eTotal
	Parámetros de salida: eTotal
	Valor que retorna:
	Fecha de creación: 07/06/19
*/
	char *cCentrar, *cNom;
	int eRecorre, eCentrar;
	
	if(*eTotalPa == MAX_PACIENTES - 1) {
		borrar(1, 27, 79, 29);
		moverCursor(28, 38);
		printf("No se pueden agregar m%cs pacientes", 160);
	
	} else {
		
		if(*eTotalPa == -1 || rPaciente.eIdP > aPacientes[*eTotalPa].eIdP)	{
		
			(*eTotalPa)++;
			aPacientes[*eTotalPa] = rPaciente;
			
			borrar(1, 27, 79, 29);
			moverCursor(28, 20);
			printf("%s %s registrado correctamente con Id %003d", rPaciente.cPaterno, rPaciente.cNombre, rPaciente.eIdP);
		
		} else {
		
			if(BuscarPacientePorId(aPacientes, *eTotalPa, rPaciente.eIdP) != -1) {
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 7);
				printf("Ya existe %d", rPaciente.eIdP);
		
			} else {
				
				eRecorre = *eTotalPa;
				while (eRecorre >= 0 && aPacientes[eRecorre].eIdP > rPaciente.eIdP){
					aPacientes[eRecorre + 1] = aPacientes[eRecorre];
					eRecorre--;
				}
				aPacientes[eRecorre + 1] = rPaciente;
				(*eTotalPa)++;
				
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 20);
				printf("%s %s registrado correctamente con Id %003d", rPaciente.cPaterno, rPaciente.cNombre, rPaciente.eIdP);
			}
		}
	} 
	getchar();
} //InsertarPaciente

int BuscarPacientePorId (TaPacientes aPacientes, int eTotalPa, int eIdP){
/*
	Nombre del módulo:  Funcion  BuscarPacientePorId
	Autor: Ivan Tronco
	Objetivo: buscar Id e indicar la posision del arreglo en de un paciente
	Parámetros de entrada: aPaciente, eTotal, eIdP
	Parámetros de salida: no recibe
	Valor que retorna: la posicion en el arreglo (eMedio)
	Fecha de creación: 07/06/19
*/	
	int eMenor, eMayor, eMedio;
	
	if(eTotalPa == -1 ){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotalPa;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && aPacientes[eMedio].eIdP != eIdP){
			
			if( eIdP < aPacientes[eMedio].eIdP){
				eMayor = eMedio - 1;
			} else {
				eMenor = eMedio + 1;
			}
			
			eMedio = (eMayor + eMenor) / 2;
		}
		
		if ( eIdP == aPacientes[eMedio].eIdP){
			return eMedio;
		} else{
			return -1;
		}
	}
} //BuscarPacientePorId

int GenerarIdPaciente (){
/*
	Nombre del módulo:  Funcion GenerarIdPaciente
	Autor: 
	Objetivo: generar un id
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eSiguiente)
	Fecha de creación: 07/06/19
*/	
	static int eIdPaci = 1;
	
	return (eIdPaci++);
} //GenerarIdPaciente

void ListarPacientesPorId (TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){	
/*
	Nombre del módulo: Procedimiento ListarPacientesPorId
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden acendente de id 
	Parámetros de entrada: aPaciente, eTotal
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 07/06/19
*/	
	static int eRen = 5;
	int eIdD;
	
	eIdD = BuscarDoctorPorId (aDoctores, eTotalDoc, aPacientes[eTotalPa].eIdD);
		
	if (eTotalPa != -1){
		
		ListarPacientesPorId(aPacientes, eTotalPa - 1, aDoctores, eTotalDoc);
        
		moverCursor(eRen, 6);        
		printf("%c  %003d", 179, aPacientes[eTotalPa].eIdP);
		moverCursor(eRen, 14);
		printf("%c %s %s %s", 179, aPacientes[eTotalPa].cPaterno, 
		aPacientes[eTotalPa].cMaterno, 
		aPacientes[eTotalPa].cNombre); 
		moverCursor(eRen, 48); 
		printf("%c %s ", 179, aDoctores[aPacientes[eTotalPa].eIdD - 1].cPaterno);
		moverCursor(eRen, 61);
		printf("%c %s %c", 179, aPacientes[eTotalPa].cTelCel, 179);
		
		(eRen++);
		
	}
	
	if(eTotalPa < 0){
		eRen = 5;
	}
	
} //ListarPacientesPorId

void ObtenerTipoSangre (int eSangre, char *cSangre){
/*
	Nombre del módulo: Procedimiento ObtenerTipoSangre
	Autor: Ivan Tronco
	Objetivo: cambia el valor nomerico del tipo de sangre por una cadena
	Parámetros de entrada: eSangre
	Parámetros de salida: cSangre
	Valor que retorna: tipo de sangre en tipo cadena(cSangre)
	Fecha de creación: 07/06/19
*/	
	switch(eSangre){
		case O_POS: strcpy(cSangre, "O+");
				break;
		case O_NEG: strcpy(cSangre, "O-");
				break;	 
		case A_POS: strcpy(cSangre, "A+");
				break;
		case A_NEG: strcpy(cSangre, "A-");
				break;
		case B_POS: strcpy(cSangre, "B+");
				break;
		case B_NEG: strcpy(cSangre, "B-");
				break;
		case AB_POS: strcpy(cSangre, "AB+");
				break;
		case AB_NEG: strcpy(cSangre, "AB-");
				break;
		default: strcpy(cSangre, "Indefinido");
				break;
	}	
} //ObtenerTipoSangre 

void MostrarDatosPaciente (TrPaciente rPaciente, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento MostrarDatosPaciente
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un paciente
	Parámetros de entrada: rPaciente
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 07/06/19
*/	
	int eIdD;
	char cSangre[3];
	
	eIdD = BuscarDoctorPorId (aDoctores, eTotalDoc, rPaciente.eIdD);
	borrar(4, 4, 76, 25);
	moverCursor(3, 8); 
	printf("Datos del paciente: %003d ", rPaciente.eIdP);
	ObtenerTipoSangre(rPaciente.eTSangre, cSangre);

	moverCursor(5, 10);
	printf("Apellido Paterno: %s", rPaciente.cPaterno);
	moverCursor(6, 10);
	printf("Apellido Materno: %s", rPaciente.cMaterno);
	moverCursor(7, 19);
	printf("Nombres: %s", rPaciente.cNombre);
	moverCursor(8, 7);
	printf("Fecha de Nacimiento: %02d/%02d/%d", rPaciente.rFecha.eDia, rPaciente.rFecha.eMes, rPaciente.rFecha.eAnio);
	moverCursor(9, 22);
	printf("Sexo: %c", rPaciente.cSexo);
	moverCursor(10, 12);
	printf("Tipo de Sangre: %s", cSangre);
	moverCursor(11, 17);
	printf("ID Doctor: %s", aDoctores[rPaciente.eIdD - 1].cPaterno);
	moverCursor(12, 17);
	printf("Domicilio: %s", rPaciente.cDomicilio);
	moverCursor(13, 18);
	printf("Telefono: %-10s", rPaciente.cTelCel);
	moverCursor(14, 7);
	printf("Telefono Emergencia: %s", rPaciente.cEmer);
	moverCursor(15, 23);
	printf("RFC: %s", rPaciente.cRFC);
	
	
	
} //MostrarDatosPaciente

void ConsultarPacientePorId(TaPacientes aPacientes, int eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento ConsultarPacientePorId
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un paciente mediante su Id
	Parámetros de entrada: aPacientes, eTotal, eId
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 07/06/19
*/
	int ePos;

	ePos = BuscarPacientePorId(aPacientes, eTotalPa, eId);
	
	if (ePos > -1){
	
		MostrarDatosPaciente(aPacientes[ePos], aDoctores, eTotalDoc);	
		moverCursor(28, 7);
		system("pause");
		
	} else {
		borrar(1, 27, 79, 29);
		printf("%c", 07);
		moverCursor(28, 7);
		printf("No se encontr%c el id %d", 162, eId);
		moverCursor(29,20);
		system("pause");
		borrar(1, 27, 79, 29);
	}
} //ConsultarPacienteoPorId

int LeerIdPaciente (char *cOperacion, int eTotalPa, int eUltimoId){
/*
	Nombre del módulo: Funcion LeerIdPaciente
	Autor: Ivan Tronco
	Objetivo: leer y validar un Id
	Parámetros de entrada: cOperacion, eTotal, eUltimoId
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eId)
	Fecha de creación: 07/06/19
*/		
	int eId;
		
	if (eTotalPa == -1) {
		
		error(16);
		return -1;
		
	} else {

		do {
			borrar(4, 4, 76, 25);
			moverCursor(5, 7);
			printf("Ingrese el id del paciente a %s [0 = salir]: ", cOperacion);
			fflush(stdin);
			scanf("%d", &eId);
			
			if (eId == 0){
				
				return eId = -1;
				
			}else if (eId < 1 || eId > eUltimoId){
				
				borrar(1, 27, 79, 29);
				printf("%c", 07);
				moverCursor(27,31);
				printf("No existe el id %003d.", eId);
				moverCursor(29,20);
				system("pause");
				
			}
		
		} while (eId < 1 || eId > eUltimoId);
	
		return eId;
	} 
} //LeerIdPaciente

void ModificarPaciente(TaPacientes aPacientes, int eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento ModificarPaciente
	Autor: Ivan Tronco
	Objetivo: permitir seleccionar el dato que se desea modificar
	Parámetros de entrada: aPacientes, eTotal, eId
	Parámetros de salida: aPacientes
	Valor que retorna: 
	Fecha de creación: 09/06/19
*/	
	int ePos, eDato, eAutor; 
	char cSangre[3];
	
	if (eTotalPa == -1){
		
		escribirMensaje("No hay pacientes resgistrados", 29);
		
	} else {
		
		ePos = BuscarPacientePorId(aPacientes, eTotalPa, eId);
		
		if (ePos == -1) {
			
			moverCursor(28,31);
			printf("No existe el id %003d.", eId);
			
			
		} else {

			do {
					
				MostrarDatosPaciente(aPacientes[ePos], aDoctores, eTotalDoc);
				
				moverCursor(18,8);
				printf("1. Apellido Paterno");
				moverCursor(19,8);
				printf("2. Apellido Materno");
				moverCursor(20,8);
				printf("3. Nombres");
				moverCursor(21,8);
				printf("4. Fecha de Nacimiento");
				
				moverCursor(18,32);	
				printf("5. Sexo");
				moverCursor(19,32);	
				printf("6. Tipo de Sangre");	
				moverCursor(20,32);	
				printf("7. ID Doctor");
				moverCursor(21,32);	
				printf("8. Domicilio");
				
				moverCursor(18,51);			
				printf("9. Telefono");
				moverCursor(19,51);			
				printf("10.Telefono Emergencia");
				moverCursor(20,51);			
				printf("11.RFC");
				moverCursor(21,51);			
				printf("12.Regresar");
				
				moverCursor(24,8);
				printf("Seleccione el dato a modificar: ");
				scanf("%d", &eDato);
				
				switch(eDato){
					
					case 1: 
							do{						// Solicita apellido paterno
			
								borrar(28, 5, 76, 5);
								moverCursor(5,28);
								fflush(stdin);
								gets(aPacientes[ePos].cPaterno); 
									
							}while(validarApellido(aPacientes[ePos].cPaterno) != 0);
							break;
					
					case 2: 
							//printf("Nuevo Apellido Materno: ", 163);
							do{						// Solicita apellido materno
			
								borrar(28, 6, 76, 6);
								moverCursor(6,28);
								fflush(stdin);
								gets(aPacientes[ePos].cMaterno);
									
							}while(validarApellido(aPacientes[ePos].cMaterno) != 0);
							break;
							
					case 3: 
							//printf("Nuevo Nombre: "); 		
							do{						// Solicita y valida nombre
			
								borrar(28, 7, 76, 7);
								moverCursor(7,28);
								fflush(stdin);
								gets(aPacientes[ePos].cNombre);
								
							}while(validarApellido(aPacientes[ePos].cNombre) != 0);
							break;
		
					case 4: 
							//printf("Nueva Fecha de Nacimiento: ", 162);
							do{						// Solicita fecha nacimiento
			
								borrar(28, 8, 76, 8);		
								moverCursor(8,28);
								fflush(stdin);
								scanf("%d/%d/%d", &aPacientes[ePos].rFecha.eDia, &aPacientes[ePos].rFecha.eMes, &aPacientes[ePos].rFecha.eAnio);
								
							}while(validarFecha(aPacientes[ePos].rFecha) != 0);
							break;
							
					case 5: 
							//printf("Nuevo Sexo: ", 164, 162);
							do{						// Solicita sexo
			
								borrar(28, 9, 76, 9);		
								moverCursor(9,28);
								fflush(stdin);
								scanf("%c", &aPacientes[ePos].cSexo);
								
							}while(validarSexo(aPacientes[ePos].cSexo) == '1');
							break;
		
					case 6: 
							//printf("Nuevo Tipo de Sangre: ");
							do{						// Solicita tipo de sangre
			
								borrar(28, 10, 76, 10);		
								moverCursor(10,28);
								fflush(stdin);
								scanf("%d", &aPacientes[ePos].eTSangre);
								if(aPacientes[ePos].eTSangre < 0 || aPacientes[ePos].eTSangre > 9){
									error(17);
								}
									
							}while(aPacientes[ePos].eTSangre < 0 || aPacientes[ePos].eTSangre > 9);
							
							ObtenerTipoSangre(aPacientes[ePos].eTSangre, cSangre);
							borrar(28, 10, 76, 10);
							moverCursor(10,28);
							printf("%s", cSangre);
							break;
		/*/
					case 7: 
							//printf("Nuevo Id de Doctor: ");
							do{						// Solicita ID doctor
			
								borrar(28, 11, 76, 11);
								moverCursor(11,28);
								fflush(stdin);
								gets(cIDDoc);
								
							}while(validarDoctor(aPacientes[ePos].rPaciente) != 0);
							break;
		*/
					case 8:	
							//printf("Nuevo Domicilio: ");
							do{						// Solicita domicilio
			
								borrar(28, 12, 76, 12);
								moverCursor(12,28);
								fflush(stdin);
								gets(aPacientes[ePos].cDomicilio);
									
							}while(validarLongitudeCadena(aPacientes[ePos].cDomicilio, 30) != 0);
							break;
			
					case 9: 
							//printf("Nuevo Telefono: ", 130);
							do{						// Solicita telefono
			
								borrar(28, 13, 76, 13);
								moverCursor(13,28);
								fflush(stdin);
								gets(aPacientes[ePos].cTelCel);
									
							}while(validarTelefono(aPacientes[ePos].cTelCel) != 0);
							break;
		
					case 10:
							//printf("Nuevo Telefono Emergencia: ", 163);
							do{						// Solicita telefono
			
								borrar(28, 14, 76, 14);
								moverCursor(14,28);
								fflush(stdin);
								gets(aPacientes[ePos].cEmer);
									
							}while(validarTelefono(aPacientes[ePos].cEmer) != 0);
							break;
							
					case 11: 
							//printf("Nuevo RFC: ", 163);
							do{						// Solicita RFC
			
								borrar(28, 15, 76, 15);
								moverCursor(15,28);
								fflush(stdin);
								gets(aPacientes[ePos].cRFC);
									
							}while(validarRFC(aPacientes[ePos].cRFC) != 0);
							break;
							
					case 12: 
							 printf("Registro modificado correctamente");
							 break;
					
					default: error(15); 
							 break;
				}
			} while (eDato != 12);
			
		}
	}
} //ModificarPaciente

void BorrarPaciente (TaPacientes aPacientes, int *eTotalPa, int eId, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento BorrarPaciente
	Autor: Ivan Tronco
	Objetivo: elminar un paciente del registro
	Parámetros de entrada: aPacientes, eTotal, eId
	Parámetros de salida: aPacientes, eTotal
	Valor que retorna: 
	Fecha de creación: 09/06/19
*/	
	int ePos, eRecorre;
	char cConfirma; 
	
	if (*eTotalPa == -1){
		
		error(16);
		
	} else {
		
		ePos = BuscarPacientePorId(aPacientes, *eTotalPa, eId);
		
		if (ePos == -1) {
			
			moverCursor(28,20);
			printf("El id %d no existe.", eId);
			moverCursor(29,20);
			system("pause");
			borrar(1, 27, 79, 29);
					
		} else {

			MostrarDatosPaciente(aPacientes[ePos], aDoctores, eTotalDoc);
			
			moverCursor(19,20);
			printf("%cDesea borrar el registro?[S/N]: ", 168);
			fflush(stdin);
			cConfirma = getchar(); 
			
			if (cConfirma == 's' || cConfirma == 'S'){
			
				for (eRecorre = ePos; eRecorre < *eTotalPa; eRecorre++){
					
					aPacientes[eRecorre] = aPacientes[eRecorre + 1];
				}
				
				(*eTotalPa)--;
				escribirMensaje("Paciente borrado correctamente", 28);
				moverCursor(29,20);
				system("pause");
				borrar(1, 27, 79, 29);
			}
		}
	}
} //BorrarPaciente 

int BuscarPorApellido(TaPacientes aPacientes, int eTotalPa, char *cOperacion){
/*
	Nombre del módulo: Funcion BuscarPorApellido
	Autor: Ivan Tronco
	Objetivo: Permite realisar una busqueda de paciente por apellido
	Parámetros de entrada: aPacientes, eTotal, cOperacion
	Parámetros de salida: no recibe
	Valor que retorna: posision en el arreglo (ePos)
	Fecha de creación: 10/06/19
*/	
	TaCadena cApellido;
	int ePos = 0;
		
	if(eTotalPa == -1){
		
		error(16);
		return -1;
		
	}else{	
		
		LeerApellidoPaciente(cOperacion, eTotalPa, &cApellido);
		
		if(strcmp(cApellido, "x") != 0 || strcmp(cApellido, "X") != 0){
		
			while(ePos <= eTotalPa && strcmp(cApellido, aPacientes[ePos].cPaterno) != 0){
			
				ePos++;
			
			}
			if(ePos > eTotalPa){
			
				return -1;
			
			}else{
			
				return ePos + 1;
			}
		}
		
		return -1;
		
	}
}

int MenuBuscarPaciente(TaPacientes aPacientes, int eTotalPa, char *cOperacion){
/*
	Nombre del módulo: Funcion MenuBuscarPaciente
	Autor: Ivan Tronco
	Objetivo: despligar opciones de busqueda de pacientes
	Parámetros de entrada: aPacientes, eTotal, cOperacion
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eId)
	Fecha de creación: 10/06/19
*/	
	int eOps, eId;


	do{
		eOps = 0;	
		borrar(4, 4, 76, 25);
		moverCursor(6, 10);
		printf("Buscar:");
		moverCursor(8, 10);
		printf("1. Por Id de paciente");
		moverCursor(10, 10);
		printf("2. Por apallido de paciente");
		moverCursor(12, 10);
		printf("3. Regresar");
		moverCursor(14, 10);
		printf("Seleccione una opci%cn: ", 162);
		scanf("%d", &eOps);
			
		switch(eOps){
			
			case 1:	
					return eId = LeerIdPaciente(cOperacion, eTotalPa, aPacientes[eTotalPa].eIdP);	
					break;
			case 2:
					return eId = BuscarPorApellido(aPacientes, eTotalPa, cOperacion);
					break;
			case 3:
					return eId = -1;
					break;
			default:
					error(15);
					break;
		}
	}while(eOps !=3);

}

void MenuListadoPaciente(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento MenuListadoPaciente
	Autor: Ivan Tronco
	Objetivo: despligar opciones para listado de pacientes
	Parámetros de entrada: aPacientes, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/	
	int eOps;
	
	do{
		eOps = 0;	
		borrar(4, 4, 76, 25);
		moverCursor(6, 10);
		printf("Listar:");
		moverCursor(8, 10);
		printf("1. Por Id de paciente");
		moverCursor(10, 10);
		printf("2. Por apallido de paciente");
		moverCursor(12, 10);
		printf("3. Por doctor");
		moverCursor(14, 10);
		printf("4. Regresar");
		moverCursor(16, 10);
		printf("Seleccione una opci%cn: ", 162);
		scanf("%d", &eOps);
			
		switch(eOps){
			
			case 1:	
					borrar(4, 4, 76, 25);
					moverCursor(4, 6);
					printf("%c Id P. %c Nombre del paciente             %c Doctor     %c Telefono   %c", 179, 179, 179, 179, 179);	
					ListarPacientesPorId(aPacientes, eTotalPa, aDoctores, eTotalDoc);
					fflush(stdin);
					moverCursor(29,20);
					system("pause");
					borrar(1, 27, 79, 29);		
					break;
			case 2:
					borrar(4, 4, 76, 25);
					moverCursor(4, 6);
					printf("%c Nombre del paciente             %c Id P. %c Doctor     %c Telefono   %c", 179, 179, 179, 179, 179);	
					OrdenamientoBurbujaPorApellido(aPacientes, eTotalPa, aDoctores, eTotalDoc);
					fflush(stdin);
					moverCursor(29,20);
					system("pause");
					borrar(1, 27, 79, 29);
					break;
			case 3:
					borrar(4, 4, 76, 25);
					moverCursor(4, 6);
					printf("%c Doctor     %c Id P. %c Nombre del paciente             %c Telefono   %c", 179, 179, 179, 179, 179);	
					OrdenamientoBurbujaPorDoctor(aPacientes, eTotalPa, aDoctores, eTotalDoc);
					fflush(stdin);
					moverCursor(29,20);
					system("pause");
					borrar(1, 27, 79, 29);
					break;
			case 4:
					break;
					
			default:
					error(15);
		}
	}while(eOps != 4);
	
}

void LeerApellidoPaciente (char *cOperacion, int eTotalPa, TaCadena *cApellido){
/*
	Nombre del módulo: Procedimiento LeerApellidoPaciente
	Autor: Ivan Tronco
	Objetivo: lee y valida el apellido de paciente
	Parámetros de entrada: cOperacion, eTotal, cApellido
	Parámetros de salida: cApellido
	Valor que retorna: apellido validado (cApellido)
	Fecha de creación: 11/06/19
*/		
	if (eTotalPa == -1) {
		
		error(16);
		
	} else {

		do {
			system("cls");
			dibujarMarco();
			moverCursor(4, 10);
			printf("Ingrese el apellido del paciente a %s [X = salir]: ", cOperacion);
			fflush(stdin);
			gets(*cApellido);
				
			
		
		} while (validarApellido(*cApellido) != 0);
	
	} 
}  //LeerApellidoPaciente

void OrdenamientoBurbujaPorApellido(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento OrdenamientoBurbujaPorApellido
	Autor: Ivan Tronco
	Objetivo: ordenar en orden alfabetico decendente apartir del apellido
	Parámetros de entrada: aPacientes, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/	
	TaPacientes aPacienteAp;
	TrPaciente eTemp;
	int eCon1, eCon2;
	
	if (eTotalPa == -1) {
		
		error(16);
		
	} else {
		
		for(eCon1 = 0; eCon1 <= eTotalPa; eCon1++){
			
			aPacienteAp[eCon1] = aPacientes[eCon1];
			
		}
		
		for(eCon1 = 0; eCon1 < eTotalPa; eCon1++){
		
			for(eCon2 = eCon1 + 1; eCon2 <= eTotalPa; eCon2++){
				
				if(strcmp(aPacienteAp[eCon1].cPaterno, aPacienteAp[eCon2].cPaterno) > 0){
					
					eTemp = aPacienteAp[eCon1];
					aPacienteAp[eCon1] = aPacienteAp[eCon2];
					aPacienteAp[eCon2] = eTemp;
					
				}
				
			}
			
		}
		
		ListarPorApellido(aPacienteAp, eTotalPa, aDoctores, eTotalDoc);	
			
	}
		
}

void OrdenamientoBurbujaPorDoctor(TaPacientes aPacientes, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento OrdenamientoBurbujaPorDoctor
	Autor: Ivan Tronco
	Objetivo: ordenar en orden decendente apartir del Id del doctor
	Parámetros de entrada: aPacientes, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/	
	TaPacientes aPacienteAp;
	TrPaciente eTemp;
	int eCon1, eCon2;
	
	if (eTotalPa == -1) {
		
		error(16);
		
	} else {
		
		for(eCon1 = 0; eCon1 <= eTotalPa; eCon1++){
			
			aPacienteAp[eCon1] = aPacientes[eCon1];
			
		}
		
		for(eCon1 = 0; eCon1 < eTotalPa; eCon1++){
		
			for(eCon2 = eCon1 + 1; eCon2 <= eTotalPa; eCon2++){
				
				if(aPacienteAp[eCon1].eIdD > aPacienteAp[eCon2].eIdD){
					
					eTemp = aPacienteAp[eCon1];
					aPacienteAp[eCon1] = aPacienteAp[eCon2];
					aPacienteAp[eCon2] = eTemp;
					
				}
				
			}
			
		}
		
		ListarPorDoctor(aPacienteAp, eTotalPa, aDoctores, eTotalDoc);	
			
	}
		
}

void ListarPorApellido(TaPacientes aPacienteAp, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento ListarPorApellido
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden alfabetico por apellido
	Parámetros de entrada: aPacienteAp, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/
	static int eRen = 5;
	int eIdD;
	
	eIdD = BuscarDoctorPorId (aDoctores, eTotalDoc, aPacienteAp[eTotalPa].eIdD);
		
	if (eTotalPa != -1){
		
		ListarPorApellido(aPacienteAp, eTotalPa - 1, aDoctores, eTotalDoc);
        
        moverCursor(eRen, 6);
		printf("%c %s %s %s", 179, aPacienteAp[eTotalPa].cPaterno,
		aPacienteAp[eTotalPa].cMaterno, 
		aPacienteAp[eTotalPa].cNombre); 
		moverCursor(eRen, 40);        
		printf("%c  %003d", 179, aPacienteAp[eTotalPa].eIdP); 
		moverCursor(eRen, 48); 
		printf("%c %s ", 179, aDoctores[aPacienteAp[eTotalPa].eIdD - 1].cPaterno);
		moverCursor(eRen, 61);
		printf("%c %s %c", 179, aPacienteAp[eTotalPa].cTelCel, 179);
		
		(eRen++);
		
	}
	
	if(eTotalPa < 0){
		eRen = 5;
	}
		
}

void ListarPorDoctor(TaPacientes aPacienteAp, int eTotalPa, TaDoctores aDoctores, int eTotalDoc){
/*
	Nombre del módulo: Procedimiento ListarPorDoctor
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden acendente de Id de doctor
	Parámetros de entrada: aPacienteAp, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/	
	static int eRen = 5;
	int eIdD;
	
	eIdD = BuscarDoctorPorId (aDoctores, eTotalDoc, aPacienteAp[eTotalPa].eIdD);
		
	if (eTotalPa != -1){
		
		ListarPorDoctor(aPacienteAp, eTotalPa - 1, aDoctores, eTotalDoc);
        
        moverCursor(eRen, 6);
        printf("%c %s ", 179, aDoctores[aPacienteAp[eTotalPa].eIdD - 1].cPaterno);
        moverCursor(eRen, 19);
        printf("%c  %003d", 179, aPacienteAp[eTotalPa].eIdP); 
		moverCursor(eRen, 27); 
		printf("%c %s %s %s", 179, aPacienteAp[eTotalPa].cPaterno,
		aPacienteAp[eTotalPa].cMaterno, 
		aPacienteAp[eTotalPa].cNombre);
		moverCursor(eRen, 61);
		printf("%c %s %c", 179, aPacienteAp[eTotalPa].cTelCel, 179);
		
		(eRen++);
		
	}
	
	if(eTotalPa < 0){
		eRen = 5;
	}
		
}
