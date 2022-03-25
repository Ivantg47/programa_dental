/*Programa: ListadoDeDoctores.c
Autror: Ivan Tronco
Objetivo: Mostrar un listado de los doctores
Fecha: 09-04-19
Version: 1.0
*/

void ListarDoctores();
    
void ListarDoctores(){
char cPaterno[20], cMaterno[20], cNombre[20], cFechaHora[16], cIDCita[6], cIDDentista[5], cIDPaciente[5]; 
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Imperio Dental S.A. de C.V. Listado de Doctores");
	moverCursor(3, 3);
	printf("ID Doctor");
	moverCursor(3, 15);
	printf("Nombre Doctor");
	moverCursor(3, 27);
	printf("Turno");
	moverCursor(3, 38);
	printf("Hora");
	moverCursor(3, 47);
	printf("Nombre Paciente");
	
	moverCursor(5, 3);
	printf("D9999");
	moverCursor(5, 15);
	printf("C9999");
	moverCursor(5, 27);
	printf("99/99/99");
	moverCursor(5, 38);
	printf("99:99");
	moverCursor(5, 47);
	printf("A[20]");
	

	moverCursor(25, 27);
	gets(cPaterno);
    
    fflush(stdin);
    getchar();
    
}

