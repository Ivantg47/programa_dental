/*Programa: bajaPacientes.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Baja de Pacientes
Fecha: 25-04-19
Version: 1.0
*/

void bajaPacientes();

void bajaPacientes(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Baja de pacientes.");
	moverCursor(4, 5);
	printf("ID del paciente: ");
	
	moverCursor(8, 5);
	printf("Ingrese el dato solicitado. ID del paciente en blanco = salir");
	
	getchar();
}
