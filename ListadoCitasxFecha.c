/*Programa: SistemaDentalListadoxCita.c
Autror: Ivan Tronco
Objetivo: Mostrar listado de las citas por fecha.
Fecha: 25-04-19
Version: 1.1
*/

void ListadoCitaxFecha();

void ListadoCitaxFecha(){
    
char cFecha[8], cIDCita[6], cHora[5]; 
	
	system("cls");
	dibujarMarco3();
	
	moverCursor(1, 5);
	printf("Imperio Dental S.A. de C.V. Listado de Citas por fecha.");
	moverCursor(3, 5);
	printf("Fecha", 163);
	moverCursor(3, 16);
	printf("ID de cita");
	moverCursor(3, 30);
	printf("Hora");
	moverCursor(3, 40);
	printf("Nombre Paciente");
	moverCursor(5, 5);
	printf("99/99/99", 163);
	moverCursor(5, 16);
	printf("C9999");
	moverCursor(5, 30);
	printf("99:99");
	moverCursor(5, 40);
	printf("A[20]");

	moverCursor(4, 27);
	
    
    fflush(stdin);
    getchar();
    
}

