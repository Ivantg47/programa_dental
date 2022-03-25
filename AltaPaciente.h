/*Programa: P23AltaCliente
Autor: Ivan Tronco
Objetivo: Dar de alta los datos de un cliente
Versiom: 1.4
Fecha: 11-05-19
*/

int AltaPaciente();


int AltaPaciente(){
	
	TrFecha eFecha;
	char cPaterno[15], cMaterno[15], cNombre[15], cRFC[13], cIDDoc[5], cSexo, cDomicilio[50], cTelCel[10], cTelEmer[10], cTSan[3], cContinuar;
	
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
		moverCursor(28, 7);
		printf("Ingrese los datos del paciente. Apellido P. en blanco = salir");
		
 
		do{						// Solicita apellido paterno
			
			borrar(30, 4, 76, 4);
			moverCursor(4,30);
			fflush(stdin);
			gets(cPaterno);
			if(strlen(cPaterno) == 0){
				return 0;
			}
			
		}while(validarApellido(cPaterno) != 0);
	
		
		do{						// Solicita apellido materno
			
			borrar(30, 6, 76, 6);
			moverCursor(6,30);
			fflush(stdin);
			gets(cMaterno);
			
		}while(validarApellido(cMaterno) != 0);
		
		do{						// Solicita apellido materno
			
			borrar(30, 8, 76, 8);
			moverCursor(8,30);
			fflush(stdin);
			gets(cNombre);
			
		}while(validarApellido(cNombre) != 0);
		
		do{						// Solicita fecha nacimiento
			
			borrar(30, 10, 76, 10);		
			moverCursor(10,30);
			fflush(stdin);
			scanf("%d/%d/%d", &eFecha.eDia, &eFecha.eMes, &eFecha.eAnio);
		
		}while(validarFecha(eFecha) != 0);
		
		do{						// Solicita sexo
			
			borrar(30, 12, 76, 12);		
			moverCursor(12,30);
			scanf("%c", &cSexo);
			
		}while(validarSexo(cSexo) == '1');
	/*	
		do{						// Solicita tipo de sangre
			
			borrar(30, 14, 76, 14);		
			moverCursor(14,30);
			scanf("%c", &cTSan);
			
		}while(validarTipoSangre(cTSan) == '1');
	*/	/*
	
		do{						// Solicita ID doctor
			
			borrar(30, 16, 76, 16);
			moverCursor(16,30);
			fflush(stdin);
			gets(cIDDoc);
			
		}while(validarDoctor(cIDDoc) != 0);	
	*/	
		do{						// Solicita domicilio
			
			borrar(30, 18, 76, 18);
			moverCursor(18,30);
			fflush(stdin);
			gets(cDomicilio);
			
		}while(validarLongitudeCadena(cDomicilio, 30) != 0);
		
		do{						// Solicita telefono
			
			borrar(30, 20, 76, 20);
			moverCursor(20,30);
			fflush(stdin);
			gets(cTelCel);
			
		}while(validarTelefono(cTelCel) != 0);
		
		do{						// Solicita telefono
			
			borrar(30, 22, 76, 22);
			moverCursor(22,30);
			fflush(stdin);
			gets(cTelEmer);
			
		}while(validarTelefono(cTelEmer) != 0);
	
		do{						// Solicita RFC
			
			borrar(30, 24, 76, 24);
			moverCursor(24,30);
			fflush(stdin);
			gets(cRFC);
			
		}while(validarRFC(cRFC) != 0);
			
		
		do{
			
			fflush(stdin);
			borrar(1, 26, 79, 28);
			centrar(27, "¿Desea agregar otro cliente? [S/N]: ");
			scanf("%c", &cContinuar);
			
		}while(ValidarCaracter(cContinuar) == '1');
		

	}while(cContinuar != 'N' && cContinuar != 'n');
	
}


