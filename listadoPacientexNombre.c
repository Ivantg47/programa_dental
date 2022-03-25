/*
Programa: listadoPacientexNombre.c
Autor: Magín Gómez Nancy Vanessa
Objetivo: Listado de Paciente por orden alfabetico (nombre)
Fecha: 25-04-19
Version: 1.0
*/

void listadoPacientexNombre();

void listadoPacientexNombre(){
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Listado de Paciente por orden alfab%ctico (Nombre).", 130);
	moverCursor(4, 14);
	printf("Nombres");
	moverCursor(4, 32);
	printf("Apellido Paterno");
	moverCursor(4, 45);
	printf("ID Paciente");
	
	moverCursor(6, 14);
	printf("A[20]");
	moverCursor(6, 32);
	printf("A[20]");
	moverCursor(6, 45);
	printf("P9999");

    
    fflush(stdin);
    getchar();  
}

