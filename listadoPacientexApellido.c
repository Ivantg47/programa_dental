/*
Programa: listadoPacientexApellido.c
Autor: Magín Gómez Nancy Vanessa
Objetivo: Listado de Paciente por orden alfabetico (apellido)
Fecha: 25-04-19
Version: 1.0
*/

void listadoPacientexApellido();

void listadoPacientexApellido(){
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Imperio Dental S.A. de C.V. Listado de Paciente por orden alfab%ctico (Apellido).", 130);
	moverCursor(4, 5);
	printf("Apellido Paterno");
	moverCursor(4, 23);
	printf("Nombres");
	moverCursor(4, 32);
	printf("ID Paciente");
	
	moverCursor(6, 5);
	printf("A[20]");
	moverCursor(6, 23);
	printf("A[20]");
	moverCursor(6, 32);
	printf("P9999");
	
    
    fflush(stdin);
    getchar();  
}

