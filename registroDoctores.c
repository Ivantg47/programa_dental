/*Programa: registroDoctores.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Registro doctores
Fecha: 25-04-19
Version: 1.0
*/

void altaDoctor();

void altaDoctor(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Registro de doctores.");
	moverCursor(4, 5);
	printf("Apellito Paterno:");
	moverCursor(6, 5);
	printf("Apellido Materno:");
	moverCursor(8, 5);
	printf("Nombres:");
	moverCursor(10, 5);
	printf("Sexo:");
	moverCursor(12, 5);
	printf("Fecha de nacimiento:");
	moverCursor(14, 5);
 	printf("Domicilio:");
	moverCursor(16, 5);
	printf("Turno:");
	moverCursor(18, 5);
	printf("RFC:");
	moverCursor(20, 5);
	printf("N%cmero de c%cdula profesional:", 163, 130);
	moverCursor(22, 5);
	printf("Telefono de emergencia:");
	moverCursor(24, 5);
	printf("Correo electr%cnico:", 162);
	moverCursor(27, 5);
	printf("Ingrese los datos del empleado. Apellido P. en blanco = salir");
	moverCursor(26, 5);
	
}



