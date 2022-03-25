/*Programa: consultaPacientes.c  
Autor: Magín Gómez Nancy Vanessa
Objetivo: Consultar un paciente
Fecha: 25-04-19
Version: 1.0
*/


void consultaPacientes();

void consultaPacientes(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Consulta de pacientes.");
	moverCursor(4, 5);
	printf("ID del paciente: ");
	
	moverCursor(8, 5);
	printf("Ingrese el dato solicitado. ID del paciente en blanco = salir");
	
	getchar();
}

