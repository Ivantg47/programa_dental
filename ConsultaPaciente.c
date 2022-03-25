/*Programa: ConsultaPaciente.c  
Autror: Rivera Jiménez Leonardo 
Objetivo: Sistema dental Menu principal y sub menus
Fecha: 25-04-19
Version: 1.0
*/

 
void consultaPaciente();

void consultaPaciente(){
	
	char cID_Paciente[50], cID_Cita[50], cID_Doctor[50], cMotivoCon[50]; 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Consulta de Paciente.");
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
	moverCursor(26, 5);
	
	getchar();
	
}

