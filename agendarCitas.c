/*Programa: agendarCitas.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Agendar citas
Fecha: 25-04-19
Version: 1.0
*/

void agendarCitas();

void agendarCitas(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Agendar citas.");
	moverCursor(4, 5);
	printf("ID del paciente:");
	moverCursor(6, 5);
	printf("Fecha de la cita:");
	moverCursor(8, 5);
	printf("Hora de la cita:");
	moverCursor(10, 5);
	printf("ID del dentista a cargo:");
	moverCursor(27, 5);
	printf("Ingrese los datos del empleado. ID paciente en blanco = salir");
	
	getchar();
}
