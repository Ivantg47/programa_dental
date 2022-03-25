/*Programa: modificarCita.c
Autror: Ivan Tronco
Objetivo: Modificar los datos de la cita
Fecha: 25-04-19
Version: 1.0
*/


void modificarCita();

void modificarCita(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Modificar datos personales del Doctor.");
	moverCursor(3, 5);
	printf("1) IDPaciente");
	moverCursor(5, 5);
	printf("2) Fecha");
	moverCursor(7, 5);
	printf("3) Hora");
	moverCursor(9, 5);
	printf("4) ID Doctor");
	moverCursor(20, 5);	
	printf("Seleccione el campo a modificar:");
	
	getchar();

}

	

