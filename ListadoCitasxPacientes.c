/*Programa: SistemaDentalListadoCitaxPaciente.c
Autror: Ivan Tronco
Objetivo: Mostrar listado de las citas por paciente. 
Fecha: 25-04-19
Version: 1.1
*/

void ListadoCitaxPaciente();

void ListadoCitaxPaciente(){
    
char cFecha[8], cIDCita[6], cHora[5]; 
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Imperio Dental S.A. de C.V. Listado de Citas por Paciente.");
	moverCursor(3, 5);
	printf("Nombre Paciente");
	moverCursor(3, 30);
	printf("ID de cita");
	moverCursor(3, 44);
	printf("Fecha");
	moverCursor(3, 55);
	printf("Hora");
	
	moverCursor(5, 5);
	printf("A[20]");
	moverCursor(5, 30);
	printf("C9999");
	moverCursor(5, 44);
	printf("99/99/99");
	moverCursor(5, 55);
	printf("99:99");
	
    
    fflush(stdin);
    getchar();
    
}


