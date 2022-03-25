/*Programa: bajaCitas.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Baja de citas
Fecha: 25-04-19
Version: 1.0
*/

void bajaCitas();

void bajaCitas(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Cancelaci%cn de cita.", 162);
	moverCursor(4, 5);
	printf("Nombre del paciente: ");
	moverCursor(6, 5);
	printf("Fecha de la cita: ");
	moverCursor(8, 5);
	printf("Hora de la cita: ");
	
	moverCursor(12, 5);
	printf("Ingrese los datos solicitados. Cualquier dato en blanco = salir");
	getchar();
	
}
