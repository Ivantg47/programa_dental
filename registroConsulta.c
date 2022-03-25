/*Programa: registroConsulta.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Registro consulta
Fecha: 25-04-19
Version: 1.0
*/

void registroConsulta();

void registroConsulta(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Registro de consulta.");
	moverCursor(4, 5);
	printf("ID del paciente:");
	moverCursor(6, 5);
	printf("ID de la cita:");
	moverCursor(8, 5);
	printf("ID del doctor:");
	moverCursor(10, 5);
	printf("Trabajo / tratamiento a realizar:");
	moverCursor(27, 5);
	printf("Ingrese los datos del empleado. ID paciente en blanco = salir");
	
	getchar();
	
}
