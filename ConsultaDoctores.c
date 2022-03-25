/*Programa: ConsultaDoctores.c  
Autror: Rivera Jiménez Leonardo 
Objetivo: Sistema dental Menu principal y sub menus
Fecha: 25-04-19
Version: 1.0
*/


void consultaDoctores();

void consultaDoctores(){
	
	char cPaterno[20], cMaterno[20], cNombre[20], cRFC[13], cTurno[5], cCorreo[50], cDomicilio[50], cTel[10], cNumCedula[10]; 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Consulta de Doctores.");
	moverCursor(4, 5);
	printf("Apellido Paterno: ");
	moverCursor(6, 5);
	printf("Apellido Materno: ");
	moverCursor(8, 5);
	printf("Nombres: ");
	moverCursor(10, 5);
	printf("N%cmero de C%cdula Profecional: ", 163, 130);
	moverCursor(12, 5);
	printf("RFC: ");
	moverCursor(14, 5);
	printf("Turno: ");
	moverCursor(16, 5);
	printf("Telefono: ");
	moverCursor(18, 5);
	printf("Correo: ");
	moverCursor(20, 5);
	printf("Domicilio: ");
	moverCursor(4, 27);
	
	gets(cPaterno);
}


