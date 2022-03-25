/*Programa: SistemaDentalAltaPaciente.c
Autror: Ivan Tronco
Objetivo: Sistema dental Menu principal y sub menus
Fecha: 09-04-19
Version: 1.0
*/




void registroPaciente();

void registroPaciente(){
	
	char cPaterno[20], cMaterno[20], cNombre[20], cRFC[13], cIDDoc[5], cSexo, cFNac[8], cDomicilio[50], cTelCel[10], cTelEmer[10], cTSan[3]; 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Registro de Paciente.");
	moverCursor(4, 5);
	printf("Apellido Paterno:");
	moverCursor(6, 5);
	printf("Apellido Materno:");
	moverCursor(8, 5);
	printf("Nombres:");
	moverCursor(10, 5);
	printf("Fecha de Nacimiento:");
	moverCursor(12, 5);
	printf("Sexo:");
	moverCursor(14, 5);
	printf("Tipo de Sangre:");
	moverCursor(16, 5);
	printf("ID Doctor:");
	moverCursor(18, 5);
	printf("Domicilio:");
	moverCursor(20, 5);
	printf("Telefono:");
	moverCursor(22, 5);
	printf("Telefono Emergencia:");
	moverCursor(24, 5);
	printf("RFC:");
	moverCursor(27, 5);
	printf("Ingrese los datos del empleado. Apellido P. en blanco = salir");
	
	
	moverCursor(4, 27);
	gets(cPaterno);
}


