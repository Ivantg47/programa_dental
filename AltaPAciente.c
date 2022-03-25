/*Programa: P23AltaCliente
Autor: Ivan Tronco
Objetivo: Dar de alta los datos de un cliente
Versiom: 1.4
Fecha: 11-05-19
*/

void AltaPaciente();


void AltaPaciente(){
	
	//struct Fecha eFecha;
	char cPaterno[15], cMaterno[20], cNombre[20], cRFC[13], cIDDoc[5], cSexo, cFNac[8], cDomicilio[50], cTelCel[10], cTelEmer[10], cTSan[3], cContinuar;
	
	do{
		
		borrar(35, 5, 76, 20);
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
		moverCursor(12, 22);
		printf("Sexo:");
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
		moverCursor(27, 7);
		printf("Ingrese los datos del paciente. Apellido P. en blanco = salir");
		
 
		do{						// Solicita apellido paterno
			
			borrar(30, 5, 76, 5);
			moverCursor(4,30);
			fflush(stdin);
			gets(cPaterno);
			if(strlen(cPaterno) == 0){
				pacientes();
			}
			
		}while(validarAPaterno(cPaterno) != 0);
	
	/*	
		do{						// Solicita Nombre cliente
			
			borrar(35, 7, 76, 7);
			moverCursor(7,35);
			fflush(stdin);
			gets(cNombre);
			
		}while(validarCadena(cNombre) != 0);
			
		do{						// Solicita domicilio
			
			borrar(35, 9, 76, 9);
			moverCursor(9,35);
			fflush(stdin);
			gets(cDomicilio);
			
		}while(validarLongitudeCadena(cDomicilio, 30) != 0);
		
		do{						// Solicita telefono
			
			borrar(35, 11, 76, 11);
			moverCursor(11,35);
			fflush(stdin);
			gets(cTelefono);
			
		}while(validarTelefono(cTelefono) != 0);
	
		do{						// Solicita fecha nacimiento
			
			borrar(35, 13, 76, 13);		
			moverCursor(13,35);
			fflush(stdin);
			scanf("%d/%d/%d", &eFecha.dia, &eFecha.mes, &eFecha.anio);
		
		}while(validarFecha(eFecha) != 0);
		
		do{						// Solicita saldo
			
			borrar(35, 15, 76, 15);
			moverCursor(15,35);
			fflush(stdin);
			gets(sSaldo);
			
		}while(validarSaldo(sSaldo) != 0);
		
		do{						// Solicita tipo de cliente
			
			borrar(35, 17, 76, 17);
			moverCursor(17,35);
			scanf("%c", &cTipoCliente);
			
		}while(validarCliente(cTipoCliente) == '1');
	
	*/	
		do{
			
			fflush(stdin);
			borrar(1, 26, 79, 28);
			centrar(27, "¿Desea agregar otro cliente? [S/N]: ");
			scanf("%c", &cContinuar);
			
		}while(ValidarCaracter(cContinuar) == '1');
		

	}while(cContinuar != 'N' && cContinuar != 'n');
	
}


