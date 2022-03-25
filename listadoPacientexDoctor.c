/*
Programa: listadoPacientexDoctor.c
Autor: Magín Gómez Nancy Vanessa
Objetivo: Listado de Paciente por ID del doctor que atiende
Fecha: 25-04-19
Version: 1.0
*/

void listadoPacientexDoctor();

void listadoPacientexDoctor(){
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Sistema Dental. Listado de Paciente por ID del doctor.");
	moverCursor(4, 5);
	printf("ID Doctor");
	moverCursor(4, 16);
	printf("Apellido Paterno");
	moverCursor(4, 34);
	printf("Nombres");
	moverCursor(4, 43);
	printf("ID Paciente");
	
	moverCursor(6, 5);
	printf("D9999");
	moverCursor(6, 16);
	printf("A[20]");
	moverCursor(6, 34);
	printf("A[20]");
	moverCursor(6, 43);
	printf("P9999");
	
    
    fflush(stdin);
    getchar();  
}

