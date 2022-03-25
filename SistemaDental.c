/*Programa: SistemaDental.c
Autror: Ivan Tronco
Objetivo: Sistema dental Menu principal y sub menus
Fecha: 25-04-19
Version: 1.5
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#include"interface.c"

//Modulos alta
#include"SistemaDentalAltaPaciente.c"
#include"agendarCitas.c"
#include"registroDoctores.c"
#include"registroConsulta.c"

//Modulos baja
#include"bajaCitas.c"
#include"bajaDoctores.c"
#include"bajaPacientes.c"

//Modulos cambio
#include"modificarPaciente.c"
#include"modificarDoctor.c"
#include"modificarCita.c"

//Modulos consulta
#include"ConsultaCitas.c"
#include"ConsultaDoctores.c"
#include"consultaPacientes.c"

//Modulos listado
#include"ListadoCitasxDoctor.c"
#include"ListadoCitasxPacientes.c"
#include"ListadoCitasxFecha.c"
#include"ListadoDeDoctores.c"
#include"listadoPacientexApellido.c"
#include"listadoPacientexDoctor.c"
#include"listadoPacientexNombre.c"

void pacientes();
void doctores();
void citas();
void menuListadoPaciente();
void menuListadoCitas();


int main(){
	
	int ops;
	
	do{
		system("cls");
		dibujarMarco();
		centrar(3, "Sistema Dental Imperio Dental S.A. de C.V");//llamada a la función que centra, el 3 es el renglón y lo otro es la cadena que se quiere centrar
		moverCursor(6, 10);
		printf("Men%c principal", 163);
		moverCursor(9, 10);
		printf("1. Pacientes");
		moverCursor(11, 10);
		printf("2. Doctores");
		moverCursor(13, 10);
		printf("3. Citas");
		moverCursor(15, 10);
		printf("4. Salir");
		moverCursor(19, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(19, 33);
		scanf("%d", &ops);
		fflush(stdin);
		
		switch(ops){
			case 1:
				pacientes();
				break;
			case 2:
				doctores();
				break;
			case 3:
				citas();
				break;
			case 4:
				moverCursor(27, 3);
				break;
			default:
				moverCursor(21, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(23, 5);
				system("pause");
				
		}
	}while(ops != 4);
	
	
	getchar();
	return 0;
}

void pacientes(){
	
	int ops;
	
	do{
		system("cls");
		dibujarMarco();
		centrar(3, "Menu Pacientes");
		moverCursor(7, 10);
		printf("1. Registrar paciente");
		moverCursor(9, 10);
		printf("2. Modificar datos de paciente");
		moverCursor(11, 10);
		printf("3. Baja  de paciente");
		moverCursor(13, 10);
		printf("4. Consulta de paciente");
		moverCursor(15, 10);
		printf("5. Listado de Pacientes");
		moverCursor(17, 10);
		printf("6. Men%c Principal", 163);
		moverCursor(22, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(22, 33);
		scanf("%d", &ops);
		fflush(stdin);
		
		
	
		switch(ops){
			case 1:
				registroPaciente();
				break;
			case 2:
				modificarPaciente();
				break;
			case 3:
				bajaPacientes();
				break;
			case 4:
				consultaPacientes();
				break;
			case 5:
				menuListadoPaciente();
				break;
			case 6:
				
				break;
			default:
				moverCursor(21, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(23, 5);
				system("pause");
				
		}
	}while(ops != 6);
}

void menuListadoPaciente(){
	
	int ops2;
	
	do{
		system("cls");
		dibujarMarco2();
		centrar(1, "Listado de Pacientes");
		moverCursor(7, 10);
		printf("1. Por Doctor");
		moverCursor(9, 10);
		printf("2. Orden alfab%ctico por nombre", 136);
		moverCursor(11, 10);
		printf("3. Orden alfab%ctico por apelllido", 136);
		moverCursor(13, 10);
		printf("4. Men%c Pacientes", 163);
		moverCursor(15, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(15, 33);
		scanf("%d", &ops2);
		fflush(stdin);
		
		
	
		switch(ops2){
			case 1:
				listadoPacientexDoctor();
				break;
			case 2:
				listadoPacientexNombre();
				break;
			case 3:
				listadoPacientexApellido();
				break;
			case 4:
				pacientes();
				break;
			
			default:
				moverCursor(21, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(23, 5);
				system("pause");
				
		}
	}while(ops2 != 4);
	
}

void doctores(){
	
	int ops;
	
	do{
		system("cls");
		dibujarMarco();
		centrar(3, "Menu Doctores");
		moverCursor(7, 10);
		printf("1. Registrar doctor");
		moverCursor(9, 10);
		printf("2. Modificar datos de doctor");
		moverCursor(11, 10);
		printf("3. Baja  de doctor");
		moverCursor(13, 10);
		printf("4. Consulta de doctor");
		moverCursor(15, 10);
		printf("5. Listado de doctores");
		moverCursor(17, 10);
		printf("6. Men%c Principal", 163);
		moverCursor(22, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(22, 33);
		scanf("%d", &ops);
		fflush(stdin);
	
		switch(ops){
			case 1:
				altaDoctor();
				break;
			case 2:
				modificarDoctor();
				break;
			case 3:
				bajaDoctores();
				break;
			case 4:
				consultaDoctores();
				break;
			case 5:
				ListarDoctores();
				break;
			case 6:
				moverCursor(21, 5);
				break;
			default:
				moverCursor(21, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(23, 5);
				system("pause");
				
		}
	}while(ops != 6);
	
}

void citas(){
	
	int ops;
	
	do{
		system("cls");
		dibujarMarco();
		centrar(3, "Menu Citas");
		moverCursor(7, 10);
		printf("1. Agendar cita");
		moverCursor(9, 10);
		printf("2. Cambiar cita");
		moverCursor(11, 10);
		printf("3. Cancelar cita");
		moverCursor(13, 10);
		printf("4. Consulta de citas");
		moverCursor(15, 10);
		printf("5. Listado de citas");
		moverCursor(17, 10);
		printf("6. Registrar Consulta");
		moverCursor(19, 10);
		printf("7. Men%c Principal", 163);
		moverCursor(24, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(24, 33);
		scanf("%d", &ops);
		
	
		switch(ops){
			case 1:
				agendarCitas();	
				break;
			case 2:
				modificarCita();
				break;
			case 3:
				bajaCitas();
				break;
			case 4:
				consultaCitas();
				break;
			case 5:
				menuListadoCitas();
				break;
			case 6:
				consultaPacientes();
				break;
			case 7:
				
				break;
			default:
				moverCursor(25, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(27, 5);
				system("pause");
				
		}
		
	}while(ops != 7);
}

void menuListadoCitas(){
	
	int ops2;
	
	do{
		system("cls");
		dibujarMarco2();
		centrar(1, "Listado de Citas");
		moverCursor(7, 10);
		printf("1. Por Doctor");
		moverCursor(9, 10);
		printf("2. Por paciente");
		moverCursor(11, 10);
		printf("3. Por fecha");
		moverCursor(13, 10);
		printf("4. Men%c Citas", 163);
		moverCursor(15, 10);
		printf("Seleccione una opci%cn: ", 162);
		
		moverCursor(15, 33);
		scanf("%d", &ops2);
		
		
		
	
		switch(ops2){
			case 1:
				ListarCitasPorDentista();
				break;
			case 2:
				ListadoCitaxPaciente();
				break;
			case 3:
				ListadoCitaxFecha();
				break;
			case 4:
				citas();
				break;
			default:
				moverCursor(21, 5);
				printf("Opci%cn invalida", 162);
				moverCursor(23, 5);
				system("pause");
				
		}
		fflush(stdin);
	}while(ops2 != 4);

}

	
