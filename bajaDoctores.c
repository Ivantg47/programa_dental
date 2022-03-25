/*Programa: bajaDoctores.c
Autror: Magín Gómez Nancy Vanessa
Objetivo: Baja de doctores
Fecha: 25-04-19
Version: 1.0
*/

void bajaDoctores();

void bajaDoctores(){ 
	
	system("cls");
	dibujarMarco2();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Baja de doctores.");
	moverCursor(4, 5);
	printf("ID del doctor: ");
	moverCursor(6, 5);
	printf("Nombre del doctor: ");
	
	moverCursor(10, 5);
	printf("Ingrese los datos solicitados. Cualquier dato en blanco = salir");
	
	getchar();

}
