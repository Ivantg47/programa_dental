/*Programa: ConsultaCitas.c  
Autror: Rivera Jiménez Leonardo 
Objetivo: Sistema dental Menu principal y sub menus
Fecha: 25-04-19
Version: 1.0
*/


void consultaCitas();

void consultaCitas(){
	
	char cPaterno[20], cMaterno[20], cNombre[20], cNumCita[10], cTurno[5], cID_Doctor[50], cHora[50], cFecha[15]; 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Consulta de Citas.");
	moverCursor(4, 5);
	printf("Apellido Paterno: ");
	moverCursor(6, 5);
	printf("Apellido Materno: ");
	moverCursor(8, 5);
	printf("Nombres: ");
	moverCursor(10, 5);
	printf("N%cmero de cita: ", 163);
	moverCursor(12, 5);
	printf("ID_Doctor");
	moverCursor(14, 5);
	printf("Turno: ");
	moverCursor(16, 5);
	printf("Hora: ");
	moverCursor(18, 5);
	printf("Fecha: ");
	moverCursor(20, 5);
	
	getchar();
}

