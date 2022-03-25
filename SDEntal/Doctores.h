/*
	Progrma: Doctores.h
	Autor: Ivan Tronco
	Objetivo: controla todos los registros relacionados con doctores
	Version: 1.5
	Fecha: 11/06/19
*/


//Prototipos

void MenuDoctores (TaDoctores aDoctores, int *eTotal);
TrDoctor LeerDoctor ();
void InsertarDoctor (TaDoctores aDoctores, int *eTotal, TrDoctor rDoctor);
int  BuscarDoctorPorId (TaDoctores aDoctores, int eTotal, int eIdD);
int  GenerarIdDoctor ();
void ListarDoctorPorId (TaDoctores aDoctores, int eTotal);
void MenuListadoDoctor(TaDoctores aDoctores, int eTotal);
int  MenuBuscarDoctor(TaDoctores aDoctores, int eTotal, char *cOperacion);
void BorrarDoctor (TaDoctores aDoctores, int *eTotal, int eId);
void MostrarDatosDoctor (TrDoctor rDoctor);
void ConsultarDoctorPorId (TaDoctores aDoctores, int eTotal, int eId);
void LeerApellidoDoctor (char *cOperacion, int eTotal, TaCadena *cApellido);
int  LeerIdDoctor (char *cOperacion, int eTotal, int eUltimoId);
void OrdenamientoBurbujaPorApellidoDoc(TaDoctores aDoctores, int eTotal);
void ListarPorApellidoDoc(TaDoctores aDoctorAp, int eTotal);
int  BuscarPorApellidoDoc(TaDoctores aDoctores, int eTotal, char *cOperacion);
void ModificarDoctor(TaDoctores aDoctores, int eTotal, int eId);


void MenuDoctores (TaDoctores aDoctores, int *eTotal){

/*
	Nombre del módulo: Procedimiento MenuDoctores
	Autor: Ivan Tronco
	Objetivo: mostrar las opciones a realizar con registro de doctores 
	Parámetros de entrada: no recibe
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 12/06/19
*/	
	
	int eOps, eId;
	TrDoctor rDoctor;
	
		
	do{
		eOps = 0;
		system("cls");
		dibujarMarco();
		centrar(1, "Menu Doctores");
		moverCursor(7, 10);
		printf("1. Registrar doctor");
		moverCursor(9, 10);
		printf("2. Actualizar datos de doctor");
		moverCursor(11, 10);
		printf("3. Baja  de doctor");
		moverCursor(13, 10);
		printf("4. Consulta de doctor");
		moverCursor(15, 10);
		printf("5. Listado de doctors");
		moverCursor(17, 10);
		printf("6. Men%c Principal", 163);
		moverCursor(22, 10);
		printf("Seleccione una opci%cn: ", 162);
			
		moverCursor(22, 33);
		fflush(stdin);
		scanf("%d", &eOps);		
			
		
		switch(eOps){
			case 1: //Registrar paciente
					rDoctor = LeerDoctor();
					InsertarDoctor (aDoctores, &(*eTotal), rDoctor);
					break;
			case 2: //Modificar datos de paciente							
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Actualizar datos de Doctor.");
					if (*eTotal == -1){							
						error(16);
					}else{
						eId = MenuBuscarDoctor(aDoctores, *eTotal, "actualizar");
							
						if (eId > -1){										
							ModificarDoctor(aDoctores, *eTotal, eId);
						}
					}
					fflush(stdin);
					break;
			case 3: //Baja  de paciente
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Baja de Doctor.");
					if (*eTotal == -1){							
						error(16);
					}else{
						eId = MenuBuscarDoctor(aDoctores, *eTotal, "borrar");
							
						if (eId > -1){										
							BorrarDoctor(aDoctores, &(*eTotal), eId);
						}
					}
					fflush(stdin);
					break;
			case 4: //Consulta de paciente
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Consulta de Doctor.");
					if (*eTotal == -1){							
						error(16);
					}else{
						eId = MenuBuscarDoctor(aDoctores, *eTotal, "consultar");
								
						if (eId > -1){										
							ConsultarDoctorPorId(aDoctores, *eTotal, eId);
						}
					}
					fflush(stdin);
					break;
			case 5: //Listado de Pacientes
					borrar(4, 4, 76, 25);
					centrar(1, "Sistema Dental. Listado de Doctores.");
					if (*eTotal == -1){							
						error(16);
					}else{
						 MenuListadoDoctor(aDoctores, *eTotal);
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

TrDoctor LeerDoctor (){
/*
	Nombre del módulo:  Funcion  LeerDoctor
	Autor: Ivan Tronco
	Objetivo: leer los datos del paciente y generar un Id 
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: registro del paciente (rDoctor)
	Fecha de creación: 12/06/19
*/	
	TrDoctor rDoctor;
		
	system("cls");
	dibujarMarco();
	
	centrar(1, "Sistema Dental. Registro de Paciente.");
	moverCursor(5, 10);
	printf("Apellido Paterno:");
	moverCursor(7, 10);
	printf("Apellido Materno:");
	moverCursor(9, 19);
	printf("Nombres:");
	moverCursor(11, 7);
	printf("Fecha de Nacimiento:");
	moverCursor(13, 8);
	printf("Cedula profesional:");
	moverCursor(15, 14);
	printf("Especialidad:");
	moverCursor(17, 17);
	printf("Domicilio:");
	moverCursor(19, 18);
	printf("Telefono:");
	moverCursor(28, 25);
	printf("Ingrese los datos del doctor.");
		
 
	do{						// Solicita apellido paterno
			
		borrar(30, 5, 76, 5);
		moverCursor(5,30);
		fflush(stdin);
		gets(rDoctor.cPaterno);
			
	}while(validarApellido(rDoctor.cPaterno) != 0);
	
		
	do{						// Solicita apellido materno
			
		borrar(30, 7, 76, 7);
		moverCursor(7,30);
		fflush(stdin);
		gets(rDoctor.cMaterno);
			
	}while(validarApellido(rDoctor.cMaterno) != 0);
		
	do{						// Solicita apellido materno
			
		borrar(30, 9, 76, 9);
		moverCursor(9,30);
		fflush(stdin);
		gets(rDoctor.cNombre);
		
	}while(validarApellido(rDoctor.cNombre) != 0);
		
	do{						// Solicita fecha nacimiento
			
		borrar(30, 11, 76, 11);		
		moverCursor(11,30);
		fflush(stdin);
		scanf("%d/%d/%d", &rDoctor.rFecha.eDia, &rDoctor.rFecha.eMes, &rDoctor.rFecha.eAnio);
		
	}while(validarFecha(rDoctor.rFecha) != 0);
		
	do{						// Solicita cedula profesional
			
		borrar(30, 13, 76, 13);		
		moverCursor(13,30);
		fflush(stdin);
		gets(rDoctor.cCedula);
		
	}while(validarCedula(rDoctor.cCedula) != 0);
	
	do{						// Solicita especialidad
			
		borrar(30, 15, 76, 15);
		moverCursor(15,30);
		fflush(stdin);
		gets(rDoctor.cEspecialidad);
		
	}while(validarCadena(rDoctor.cEspecialidad) != 0);	
		
	do{						// Solicita domicilio
			
		borrar(30, 17, 76, 17);
		moverCursor(17,30);
		fflush(stdin);
		gets(rDoctor.cDomicilio);
			
	}while(validarLongitudeCadena(rDoctor.cDomicilio, 30) != 0);
		
	do{						// Solicita telefono
			
		borrar(30, 19, 76, 19);
		moverCursor(19,30);
		fflush(stdin);
		gets(rDoctor.cTelCel);
			
	}while(validarTelefono(rDoctor.cTelCel) != 0);

	rDoctor.eIdD = GenerarIdDoctor ();

			
	return rDoctor;	
	
}

void InsertarDoctor (TaDoctores aDoctores, int *eTotal, TrDoctor rDoctor){
/*
	Nombre del módulo: Procedimiento InsertarDoctor
	Autor: Ivan Tronco
	Objetivo: intertar el registro de paciente al arreglo de pacientes 
	Parámetros de entrada: aPaciente, rDoctor, eTotal
	Parámetros de salida: eTotal
	Valor que retorna:
	Fecha de creación: 12/06/19
*/
	char *cCentrar, *cNom;
	int eRecorre, eCentrar;
	
	if(*eTotal == MAX_DOCTORES - 1) {
		borrar(1, 27, 79, 29);
		moverCursor(28, 38);
		printf("No se pueden agregar m%cs goctores", 160);
	
	} else {
		
		if(*eTotal == -1 || rDoctor.eIdD > aDoctores[*eTotal].eIdD)	{
		
			(*eTotal)++;
			aDoctores[*eTotal] = rDoctor;
			
			borrar(1, 27, 79, 29);
			moverCursor(28, 20);
			printf("%s %s registrado correctamente con Id %003d", rDoctor.cPaterno, rDoctor.cNombre, rDoctor.eIdD);
		
		} else {
		
			if(BuscarDoctorPorId(aDoctores, *eTotal, rDoctor.eIdD) != -1) {
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 7);
				printf("Ya existe %d", rDoctor.eIdD);
		
			} else {
				
				eRecorre = *eTotal;
				while (eRecorre >= 0 && aDoctores[eRecorre].eIdD > rDoctor.eIdD){
					aDoctores[eRecorre + 1] = aDoctores[eRecorre];
					eRecorre--;
				}
				aDoctores[eRecorre + 1] = rDoctor;
				(*eTotal)++;
				
				
				borrar(1, 27, 79, 29);
				moverCursor(28, 20);
				printf("%s %s registrado correctamente con Id %003d", rDoctor.cPaterno, rDoctor.cNombre, rDoctor.eIdD);
			}
		}
	} 
	getchar();
} //InsertarDoctor

int BuscarDoctorPorId (TaDoctores aDoctores, int eTotal, int eIdD){
/*
	Nombre del módulo:  Funcion  BuscarDoctorPorId
	Autor: Ivan Tronco
	Objetivo: buscar Id e indicar la posision del arreglo en de un paciente
	Parámetros de entrada: aPaciente, eTotal, eIdD
	Parámetros de salida: no recibe
	Valor que retorna: la posicion en el arreglo (eMedio)
	Fecha de creación: 12/06/19
*/	
	int eMenor, eMayor, eMedio;
	
	if(eTotal == -1 ){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotal;
		eMedio = (eMayor + eMenor) / 2;
		
		while ( eMenor < eMayor && aDoctores[eMedio].eIdD != eIdD){
			
			if( eIdD < aDoctores[eMedio].eIdD){
				eMayor = eMedio - 1;
			} else {
				eMenor = eMedio + 1;
			}
			
			eMedio = (eMayor + eMenor) / 2;
		}
		
		if ( eIdD == aDoctores[eMedio].eIdD){
			return eMedio;
		} else{
			return -1;
		}
	}
} //BuscarDoctorPorId

int GenerarIdDoctor (){
/*
	Nombre del módulo:  Funcion GenerarIdDoctor
	Autor: 
	Objetivo: generar un id
	Parámetros de entrada: no recibe
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eSiguiente)
	Fecha de creación: 12/06/19
*/	
	static int eIdDoc = 1;
	
	return (eIdDoc++);
} //GenerarIdDoctor

void ListarDoctorPorId (TaDoctores aDoctores, int eTotal){	
/*
	Nombre del módulo: Procedimiento ListarDoctorPorId
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden acendente de id 
	Parámetros de entrada: aPaciente, eTotal
	Parámetros de salida: 
	Valor que retorna:
	Fecha de creación: 12/06/19
*/	
	static int eRen = 5;
		
	if (eTotal != -1){
		
		ListarDoctorPorId(aDoctores, eTotal - 1);
        
		moverCursor(eRen, 6);        
		printf("%c %003d", 179, aDoctores[eTotal].eIdD);
		moverCursor(eRen, 12);
		printf("%c %s %s %s", 179, aDoctores[eTotal].cPaterno, 
		aDoctores[eTotal].cMaterno, 
		aDoctores[eTotal].cNombre); 
		moverCursor(eRen, 43); 
		printf("%c %s", 179, aDoctores[eTotal].cEspecialidad);
		moverCursor(eRen, 61);
		printf("%c %s %c", 179, aDoctores[eTotal].cTelCel, 179);
		
		(eRen++);
		
	}
	
	if(eTotal < 0){
		eRen = 5;
	}
	
} //ListarDoctorPorId

void MenuListadoDoctor(TaDoctores aDoctores, int eTotal){
/*
	Nombre del módulo: Procedimiento MenuListadoDoctor
	Autor: Ivan Tronco
	Objetivo: despligar opciones para listado de pacientes
	Parámetros de entrada: aDoctores, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/	
	int eOps;
	
	do{
		eOps = 0;	
		borrar(4, 4, 76, 25);
		moverCursor(6, 10);
		printf("Listar:");
		moverCursor(8, 10);
		printf("1. Por Id de doctor");
		moverCursor(10, 10);
		printf("2. Por apellido de doctor");
		moverCursor(12, 10);
		printf("3. Regresar");
		moverCursor(14, 10);
		printf("Seleccione una opci%cn: ", 162);
		scanf("%d", &eOps);
			
		switch(eOps){
			
			case 1:	
					borrar(4, 4, 76, 25);
					moverCursor(4, 6);
					printf("%cId D.%c Nombre del doctor            %c Especialidad    %c Telefono   %c", 179, 179, 179, 179, 179);	
					ListarDoctorPorId(aDoctores, eTotal);
					fflush(stdin);
					moverCursor(29,20);
					system("pause");
					borrar(1, 27, 79, 29);		
					break;
			case 2:
					borrar(4, 4, 76, 25);
					moverCursor(4, 6);
					printf("%c Nombre del doctor            %cId D.%c Especialidad    %c Telefono   %c", 179, 179, 179, 179, 179);	
					OrdenamientoBurbujaPorApellidoDoc(aDoctores, eTotal);
					fflush(stdin);
					moverCursor(29,20);
					system("pause");
					borrar(1, 27, 79, 29);
					break;
			case 3:
					break;
					
			default:
					error(15);
		}
	}while(eOps != 3);
	
}

int MenuBuscarDoctor(TaDoctores aDoctores, int eTotal, char *cOperacion){
/*
	Nombre del módulo: Funcion MenuBuscarDoctor
	Autor: Ivan Tronco
	Objetivo: despligar opciones de busqueda de pacientes
	Parámetros de entrada: aDoctores, eTotal, cOperacion
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eId)
	Fecha de creación: 12/06/19
*/	
	int eOps, eId;


	do{
		eOps = 0;	
		borrar(4, 4, 76, 25);
		moverCursor(6, 10);
		printf("Buscar:");
		moverCursor(8, 10);
		printf("1. Por Id de doctor");
		moverCursor(10, 10);
		printf("2. Por apallido de doctor");
		moverCursor(12, 10);
		printf("3. Regresar");
		moverCursor(14, 10);
		printf("Seleccione una opci%cn: ", 162);
		scanf("%d", &eOps);
			
		switch(eOps){
			
			case 1:	
					return eId = LeerIdDoctor(cOperacion, eTotal, aDoctores[eTotal].eIdD);	
					break;
			case 2:
					return eId = BuscarPorApellidoDoc(aDoctores, eTotal, cOperacion);
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

int LeerIdDoctor (char *cOperacion, int eTotal, int eUltimoId){
/*
	Nombre del módulo: Funcion LeerIdDoctor
	Autor: Ivan Tronco
	Objetivo: leer y validar un Id
	Parámetros de entrada: cOperacion, eTotal, eUltimoId
	Parámetros de salida: no recibe
	Valor que retorna: numero de Id (eId)
	Fecha de creación: 12/06/19
*/		
	int eId;
		
	if (eTotal == -1) {
		
		error(16);
		return -1;
		
	} else {

		do {
			borrar(4, 4, 76, 25);
			moverCursor(5, 7);
			printf("Ingrese el id del doctor a %s [0 = salir]: ", cOperacion);
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
} //LeerIdDoctor

void BorrarDoctor (TaDoctores aDoctores, int *eTotal, int eId){
/*
	Nombre del módulo: Procedimiento BorrarDoctor
	Autor: Ivan Tronco
	Objetivo: elminar un paciente del registro
	Parámetros de entrada: aDoctores, eTotal, eId
	Parámetros de salida: aDoctores, eTotal
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/	
	int ePos, eRecorre;
	char cConfirma; 
	
	if (*eTotal == -1){
		
		error(16);
		
	} else {
		
		ePos = BuscarDoctorPorId(aDoctores, *eTotal, eId);
		
		if (ePos == -1) {
			
			moverCursor(28,20);
			printf("El id %d no existe.", eId);
			moverCursor(29,20);
			system("pause");
			borrar(1, 27, 79, 29);
					
		} else {

			MostrarDatosDoctor(aDoctores[ePos]);
			
			moverCursor(19,20);
			printf("%cDesea borrar el registro?[S/N]: ", 168);
			fflush(stdin);
			cConfirma = getchar(); 
			
			if (cConfirma == 's' || cConfirma == 'S'){
			
				for (eRecorre = ePos; eRecorre < *eTotal; eRecorre++){
					
					aDoctores[eRecorre] = aDoctores[eRecorre + 1];
				}
				
				(*eTotal)--;
				escribirMensaje("Doctor borrado correctamente", 28);
				moverCursor(29,20);
				system("pause");
				borrar(1, 27, 79, 29);
			}
		}
	}
} //BorrarDoctor 

void MostrarDatosDoctor (TrDoctor rDoctor){
/*
	Nombre del módulo: Procedimiento MostrarDatosDoctor
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un paciente
	Parámetros de entrada: rDoctor
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/	
	
	
	borrar(4, 4, 76, 25);
	moverCursor(3, 8); 
	printf("Datos del doctor: %003d ", rDoctor.eIdD);
	

	moverCursor(5, 10);
	printf("Apellido Paterno: %s", rDoctor.cPaterno);
	moverCursor(6, 10);
	printf("Apellido Materno: %s", rDoctor.cMaterno);
	moverCursor(7, 19);
	printf("Nombres: %s", rDoctor.cNombre);
	moverCursor(8, 7);
	printf("Fecha de Nacimiento: %02d/%02d/%d", rDoctor.rFecha.eDia, rDoctor.rFecha.eMes, rDoctor.rFecha.eAnio);
	moverCursor(9, 8);
	printf("Cedula profesional: %s", rDoctor.cCedula);
	moverCursor(10, 14);
	printf("Especialidad: %s", rDoctor.cEspecialidad);
	moverCursor(11, 17);
	printf("Domicilio: %s", rDoctor.cDomicilio);
	moverCursor(12, 18);
	printf("Telefono: %s", rDoctor.cTelCel);
	
	
	
	
	
} //MostrarDatosDoctor

void ConsultarDoctorPorId(TaDoctores aDoctores, int eTotal, int eId){
/*
	Nombre del módulo: Procedimiento ConsultarDoctorPorId
	Autor: Ivan Tronco
	Objetivo: mostrar todos los datos de un paciente mediante su Id
	Parámetros de entrada: aDoctores, eTotal, eId
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 12/06/19
*/
	int ePos;

	ePos = BuscarDoctorPorId(aDoctores, eTotal, eId);
	
	if (ePos > -1){
	
		MostrarDatosDoctor(aDoctores[ePos]);	
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
} //ConsultarDoctoroPorId

int BuscarPorApellidoDoc(TaDoctores aDoctores, int eTotal, char *cOperacion){
/*
	Nombre del módulo: Funcion BuscarPorApellidoDoc
	Autor: Ivan Tronco
	Objetivo: Permite realisar una busqueda de paciente por apellido
	Parámetros de entrada: aDoctores, eTotal, cOperacion
	Parámetros de salida: no recibe
	Valor que retorna: posision en el arreglo (ePos)
	Fecha de creación: 12/06/19
*/	
	TaCadena cApellido;
	int ePos = 0;
		
	if(eTotal == -1){
		
		error(16);
		return -1;
		
	}else{	
		
		LeerApellidoDoctor(cOperacion, eTotal, &cApellido);
		
		if(strcmp(cApellido, "x") != 0 || strcmp(cApellido, "X") != 0){
		
			while(ePos <= eTotal && strcmp(cApellido, aDoctores[ePos].cPaterno) != 0){
			
				ePos++;
			
			}
			if(ePos > eTotal){
			
				return -1;
			
			}else{
			
				return ePos + 1;
			}
		}
		
		return -1;
		
	}
} //BuscarPorApellidoDoc

void LeerApellidoDoctor (char *cOperacion, int eTotal, TaCadena *cApellido){
/*
	Nombre del módulo: Procedimiento LeerApellidoDoctor
	Autor: Ivan Tronco
	Objetivo: lee y valida el apellido de paciente
	Parámetros de entrada: cOperacion, eTotal, cApellido
	Parámetros de salida: cApellido
	Valor que retorna: apellido validado (cApellido)
	Fecha de creación: 12/06/19
*/		
	if (eTotal == -1) {
		
		error(16);
		
	} else {

		do {
			system("cls");
			dibujarMarco();
			moverCursor(4, 10);
			printf("Ingrese el apellido del doctor a %s [X = salir]: ", cOperacion);
			fflush(stdin);
			gets(*cApellido);
				
			
		
		} while (validarApellido(*cApellido) != 0);
	
	} 
}  //LeerApellidoDoctor

void OrdenamientoBurbujaPorApellidoDoc(TaDoctores aDoctores, int eTotal){
/*
	Nombre del módulo: Procedimiento OrdenamientoBurbujaPorApellidoDoc
	Autor: Ivan Tronco
	Objetivo: ordenar en orden alfabetico decendente apartir del apellido
	Parámetros de entrada: aDoctores, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/	
	TaDoctores aDoctorAp;
	TrDoctor eTemp;
	int eCon1, eCon2;
	
	if (eTotal == -1) {
		
		error(16);
		
	} else {
		
		for(eCon1 = 0; eCon1 <= eTotal; eCon1++){
			
			aDoctorAp[eCon1] = aDoctores[eCon1];
			
		}
		
		for(eCon1 = 0; eCon1 < eTotal; eCon1++){
		
			for(eCon2 = eCon1 + 1; eCon2 <= eTotal; eCon2++){
				
				if(strcmp(aDoctorAp[eCon1].cPaterno, aDoctorAp[eCon2].cPaterno) > 0){
					
					eTemp = aDoctorAp[eCon1];
					aDoctorAp[eCon1] = aDoctorAp[eCon2];
					aDoctorAp[eCon2] = eTemp;
					
				}
				
			}
			
		}
		
		ListarPorApellidoDoc(aDoctorAp, eTotal);	
			
	}
		
}//OrdenamientoBurbujaPorApellidoDoc

void ListarPorApellidoDoc(TaDoctores aDoctorAp, int eTotal){
/*
	Nombre del módulo: Procedimiento ListarPorApellido
	Autor: Ivan Tronco
	Objetivo: mostrar datos de pacientes en forma de lista en orden alfabetico por apellido
	Parámetros de entrada: aDoctorAp, eTotal
	Parámetros de salida: 
	Valor que retorna: 
	Fecha de creación: 11/06/19
*/
	static int eRen = 5;
		
	if (eTotal != -1){
		
		ListarPorApellidoDoc(aDoctorAp, eTotal - 1);
        
        moverCursor(eRen, 6);
		printf("%c %s %s %s", 179, aDoctorAp[eTotal].cPaterno,
		aDoctorAp[eTotal].cMaterno, 
		aDoctorAp[eTotal].cNombre); 
		moverCursor(eRen, 37);        
		printf("%c %003d", 179, aDoctorAp[eTotal].eIdD); 
		moverCursor(eRen, 43); 
		printf("%c %s ", 179, aDoctorAp[eTotal].cEspecialidad);
		moverCursor(eRen, 61);
		printf("%c %s %c", 179, aDoctorAp[eTotal].cTelCel, 179);
		
		(eRen++);
		
	}
	
	if(eTotal < 0){
		eRen = 5;
	}
		
}//ListarPorApellidoDoc

void ModificarDoctor(TaDoctores aDoctores, int eTotal, int eId){
/*
	Nombre del módulo: Procedimiento ModificarDoctor
	Autor: Ivan Tronco
	Objetivo: permitir seleccionar el dato que se desea modificar
	Parámetros de entrada: aDoctores, eTotal, eId
	Parámetros de salida: aDoctores
	Valor que retorna: 
	Fecha de creación: 09/06/19
*/	
	int ePos, eDato, eAutor; 
	char cSangre[3];
	
	if (eTotal == -1){
		
		escribirMensaje("No hay pacientes resgistrados", 29);
		
	} else {
		
		ePos = BuscarDoctorPorId(aDoctores, eTotal, eId);
		
		if (ePos == -1) {
			
			moverCursor(28,31);
			printf("No existe el id %003d.", eId);
			
			
		} else {

			do {
					
				MostrarDatosDoctor(aDoctores[ePos]);
				
				moverCursor(18,8);
				printf("1. Apellido Paterno");
				moverCursor(19,8);
				printf("2. Apellido Materno");
				moverCursor(20,8);
				printf("3. Nombres");
				moverCursor(21,8);
				printf("4. Fecha de Nacimiento");
				
				moverCursor(18,32);	
				printf("5. Cedula profesional");
				moverCursor(19,32);	
				printf("6. Especialidad");	
				moverCursor(20,32);	
				printf("7. Domicilio");
				moverCursor(21,32);	
				printf("8. Telefono");
				
				moverCursor(18,53);			
				printf("9. Regresar");
				
				
				moverCursor(24,8);
				printf("Seleccione el dato a modificar: ");
				scanf("%d", &eDato);
				
				switch(eDato){
					
					case 1: 
							do{						// Solicita apellido paterno
			
								borrar(28, 5, 76, 5);
								moverCursor(5,28);
								fflush(stdin);
								gets(aDoctores[ePos].cPaterno); 
									
							}while(validarApellido(aDoctores[ePos].cPaterno) != 0);
							break;
					
					case 2: 
							do{						// Solicita apellido materno
			
								borrar(28, 6, 76, 6);
								moverCursor(6,28);
								fflush(stdin);
								gets(aDoctores[ePos].cMaterno);
									
							}while(validarApellido(aDoctores[ePos].cMaterno) != 0);
							break;
							
					case 3: 		
							do{						// Solicita y valida nombre
			
								borrar(28, 7, 76, 7);
								moverCursor(7,28);
								fflush(stdin);
								gets(aDoctores[ePos].cNombre);
								
							}while(validarApellido(aDoctores[ePos].cNombre) != 0);
							break;
		
					case 4: 
							do{						// Solicita fecha nacimiento
			
								borrar(28, 8, 76, 8);		
								moverCursor(8,28);
								fflush(stdin);
								scanf("%d/%d/%d", &aDoctores[ePos].rFecha.eDia, &aDoctores[ePos].rFecha.eMes, &aDoctores[ePos].rFecha.eAnio);
								
							}while(validarFecha(aDoctores[ePos].rFecha) != 0);
							break;
							
					case 5: 
							do{						// Solicita cedula profesional
			
								borrar(28, 9, 76, 9);		
								moverCursor(9,28);
								fflush(stdin);
								gets(aDoctores[ePos].cCedula);
								
							}while(validarCedula(aDoctores[ePos].cCedula) != 0);
							break;
		
					case 6: 
							do{						// Solicita especialidad
			
								borrar(28, 10, 76, 10);
								moverCursor(10,28);
								fflush(stdin);
								gets(aDoctores[ePos].cEspecialidad);
								
							}while(validarCadena(aDoctores[ePos].cEspecialidad) != 0);
							break;
					case 7: 
							do{						// Solicita domicilio
			
								borrar(28, 11, 76, 11);
								moverCursor(11,28);
								fflush(stdin);
								gets(aDoctores[ePos].cDomicilio);
									
							}while(validarLongitudeCadena(aDoctores[ePos].cDomicilio, 30) != 0);
							break;
							
					case 8:	
							do{						// Solicita telefono
			
								borrar(28, 12, 76, 12);
								moverCursor(12,28);
								fflush(stdin);
								gets(aDoctores[ePos].cTelCel);
									
							}while(validarTelefono(aDoctores[ePos].cTelCel) != 0);
							break;
			
					case 9: 
							printf("Registro modificado correctamente");
							break;
					
					default: error(15); 
							 break;
				}
			} while (eDato != 9);
			
		}
	}
} //ModificarDoctor
