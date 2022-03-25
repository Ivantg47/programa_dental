/*Programa: modificarPaciente.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Modificar los datos del paciente
Fecha: 25-04-19
Version: 1.0
*/


void modificarPaciente();

void modificarPaciente(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Modificar datos personales del paciente.");
	moverCursor(3, 5);
	printf("1) Apellito Paterno:");
	moverCursor(5, 5);
	printf("2) Apellido Materno:");
	moverCursor(7, 5);
	printf("3) Nombres:");
	moverCursor(9, 5);
	printf("4) Sexo:");
	moverCursor(11, 5);
	printf("5) Fecha de nacimiento:");
	moverCursor(13, 5);
 	printf("6) Domicilio:");
	moverCursor(15, 5);
	printf("7) RFC:");
	moverCursor(17, 5);
	printf("9) N%cmero de expediente:", 163);
	moverCursor(19, 5);
	printf("10) Tel%cfono de emergencia:", 130);
	moverCursor(21, 5);
	printf("11) Tel%cfono de celular:", 130);
	moverCursor(23, 5);
	printf("12) ID del doctor que lo atiende:", 162);
	moverCursor(25, 5);
	printf("13) ID del paciente:", 162);
	moverCursor(28, 5);	
	printf("Seleccione el campo a modificar:");
	
	getchar();

}

	

