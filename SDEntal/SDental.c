/*
	Progrma: Sistema Dental Imperio Dental
	Autor: Ivan Tronco
	Objetivo: programa principal 
	Version: 1.9
	Fecha: 12/06/19
*/

//Bibliotecas
#include<stdio.h>
#include"funcionesC.h"
#include"Pacientes.h"
#include"Doctores.h"
#include"Citas.h"

//Prototipos
void menuPrincipal();
void pacientes();
void doctores();
void citas();
void menuListadoPaciente();
void menuListadoCitas();

int main(){
	
	menuPrincipal();
	moverCursor(29, 0);	
	return 0;
}

void menuPrincipal(){
	
	static int eTotalPa = -1;
	static TaPacientes aPacientes;
	static int eTotalDoc = -1;
	static TaDoctores aDoctores;
	static int eTotalCit = -1;
	static TaCita aCitas;
	
	int ops;
	
	do{
		ops = 0;
		system("cls");
		dibujarMarco();
		centrar(1, "Sistema Dental Imperio Dental S.A. de C.V");//llamada a la función que centra, el 3 es el renglón y lo otro es la cadena que se quiere centrar
		centrar(4, "Menu principal");
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
			case 1: MenuPacientes(aPacientes, &eTotalPa, aDoctores, eTotalDoc);
				break;
				
			case 2: MenuDoctores (aDoctores, &eTotalDoc);
				break;
				
			case 3: 
					system("cls");
					dibujarMarco();
					centrar(1, "Sistema Dental. Registro de Cita.");
					if(eTotalPa == -1){
						
						error(16);
						
					}else{
						
						MenuCitas (aCitas, &eTotalCit, aPacientes, eTotalPa, aDoctores, eTotalDoc);
						
					}
				break;
				
			case 4: escribirMensaje("Cerrando Sistema Dental", 29);
				break;
			default: error(15);
				
		}
	}while(ops != 4);
	
}

