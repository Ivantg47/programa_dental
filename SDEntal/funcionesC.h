/*
	Progrma: Funciones.h
	Autor: Ivan Tronco
	Objetivo: Biblioteca de funciones
	Version: 1.11
	Fecha: 06/06/19
*/	
//Bibliotecas
#include<windows.h>
#include<string.h>
#include<stdlib.h>

//Constante
#define MAX_PACIENTES 15
#define MAX_DOCTORES 5
#define MAX_CITAS 100

//Tipos
typedef struct{
	int eHora, eMin;
}TrHora;

typedef struct{
    int eDia;
    int eMes;
    int eAnio;
}TrFecha;

typedef char TaTelefono[10];

typedef enum{
	O_POS = 1, O_NEG, A_POS, A_NEG, B_POS, B_NEG, AB_POS, AB_NEG
}TeTSangre;

typedef struct{
	char cPaterno[15], cMaterno[15], cNombre[15], cEspecialidad[20], cDomicilio[50];
	TaTelefono cTelCel;
	TrFecha rFecha;
	int eIdD;
	char cCedula[8];
}TrDoctor;

typedef struct{
	TrFecha rFecha;
	char cSexo, cDomicilio[30];
	char cPaterno[15], cMaterno[15], cNombre[15], cRFC[13];
	TeTSangre eTSangre;
	TaTelefono cTelCel;
	int eIdP, eIdD;
	TaTelefono cEmer;
}TrPaciente;

typedef struct{
	TrHora rHora;
	TrFecha rFecha;
	int eIdC, eIdP, eIdD;
}TrCita;

typedef TrDoctor TaDoctores[MAX_DOCTORES];

typedef TrPaciente TaPacientes[MAX_PACIENTES];

typedef TrCita TaCita[MAX_CITAS];

typedef char TaCadena[10];


//Prototipos
void cambiarColor();
void moverCursor(int eRenglon, int eColumna);
void dibujarMarco();
int centrar(int eRenglon, char *cCadena);
int validarRFC(char cCadena[]);
int error(int codigo);
int validarCadena(char cCadena[]);
int validarApellido(char cCadena[]);
char ValidarCaracter(char cCaracter);
void borrar(int eCol1, int eRen1, int eCol2, int eRen2);
void escribirMensaje(char *sMensaje, int eRenglon);
int validarTelefono(char *cCadena);
int validarCedula(char *cCadena);
char validarSexo(char cCaracter);
int validarNumero(char cCadena[]);
int validarFecha(TrFecha rFecha);
int validarHora(TrHora rHora);


void cambiarColor(){  //cambia el color de letra y fondo de la terminal la terminal
	
	system("color 17");//17 f0
	system("cls");
}

void moverCursor(int eRenglon, int eColumna){  //mueve el curso a una posicion determinada en ejes 'X' y 'Y'
	COORD coord;
	
	coord.Y = eRenglon;
	coord.X = eColumna;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarMarco(){   //genera los recuadros de la interfas
/*Función: dibujarMarco
Autor: Ivan Tronco
Objetivo: muestra un margen alrededor de un área especificada con cuatro parámetros que indican la esquina superior izquierda y la esquina inferior derecha.
Fecha: 10-05-19
*/
	
	int eRenglon, eColumna, i;
	
	cambiarColor();
	
	//marco externo
	for(i=1; i<=30; i++){
	
		moverCursor (i, 0);
		printf ("%c", 186);
		moverCursor (i, 80);
		printf ("%c", 186);
	
	}
	
	for(i=1; i<=80; i++){
	
		moverCursor (0, i);
		printf ("%c", 205);
		moverCursor (30, i);
		printf ("%c", 205);
	
	}
	
	moverCursor (0, 0);
	printf ("%c", 201);	
	moverCursor (0, 80);
	printf ("%c", 187);
	moverCursor (30, 0);
	printf ("%c", 200);
	moverCursor (30, 80);
	printf ("%c", 188);
	
	//marco interno
	for(i=3; i<=26; i++){
	
		moverCursor (i, 3);
		printf ("%c", 186);
		moverCursor (i, 77);
		printf ("%c", 186);
	
	}
	
	for(i=3; i<=77; i++){
	
		moverCursor (2, i);
		printf ("%c", 205);
		moverCursor (26, i);
		printf ("%c", 205);
	
	}
	
	moverCursor (2, 3);
	printf ("%c", 201);	
	moverCursor (2, 77);
	printf ("%c", 187);
	moverCursor (26, 3);
	printf ("%c", 200);
	moverCursor (26, 77);
	printf ("%c", 188);
	
}

int centrar(int eRenglon, char *cCadena){  //Centra una cadena vasada en su longitud
    moverCursor(eRenglon, (80 - (int)strlen(cCadena))/2);/*Se posiciona el cursor en el renglón recibido y 
	a 121(lo que mide la ventana), le resta la longitud de la cadena entre 2*/
    printf("%s", cCadena);//Impreme la cadena
}

int validarRFC(char cCadena[]){  //valida que la secuencia del RFC sea correcta
/*Función: validarRFC
Autor: Ivan Tronco
Objetivo: validar el rfc
Fecha: 09-05-19
*/

	int i;
	
	if (validarLongitudeCadena(cCadena, 13) != 0){
		
		return 1;
	}
	
    for(i=0 ; i<4; i++){
        
		if(!(cCadena[i]>=65 && cCadena[i]<=90 || cCadena[i]>=97 && cCadena[i]<=122)){
        
			return error(11);
		
		} 
    }
    
    for(i = 4; i < 10; i++){
    		
		if(!(cCadena[i]>=48 && cCadena[i]<=57)){
           
        return error(11);
        
		}
	}
	
	for(i = 10; i < 13; i++){
    		
		if(!(cCadena[i]>=48 && cCadena[i]<=57 || cCadena[i]>=65 && cCadena[i]<=90 || cCadena[i]>=97 && cCadena[i]<=122)){
           
           	return error(11);
        
		}
	}
	
	
    return 0;  

}

int error(int codigo){  //Muestra los mensaje de error
/*Función: F16error
Autor: Ivan Tronco
Objetivo: Mostrar un mensaje de error y reproducir un sonido
Fecha: 09-05-19
*/
	
	borrar(1, 27, 79, 29);
	moverCursor(27,23);
	printf("%c", 07);
	switch(codigo){
		case 1:
			escribirMensaje("Unicamente se aceptan digitos", 28);
			break;
		case 2:
			escribirMensaje("No se aceptan digitos o simbolos", 28);
			break;
		case 3:
			escribirMensaje("Solo se acepta S o N", 28);
			break;
		case 4:
			escribirMensaje("Excedio el maximo de caracteres permitidos", 28);
			break;
		case 5:
			escribirMensaje("Fecha invalido utilize formado dd/mm/aaaa separado por /", 28);
			break;
		case 6:
			escribirMensaje("Valor invalido", 28);
			break;
		case 7:
			escribirMensaje("Numero invalido", 28);
			break;
		case 8:
			escribirMensaje("Solo se acepta M o F", 28);
			break;
		case 9:
			escribirMensaje("La cadena solo acepta letras", 28);
			break;
		case 10:
			escribirMensaje("Error, caracter no valido", 28);
			break;
		case 11:
			escribirMensaje("RFC invalido", 28);
			break;
		case 12:
			escribirMensaje("Mes invalido", 28);
			break;
		case 13:
			escribirMensaje("Dia invalido", 28);
			break;
		case 14:
			escribirMensaje("No es posible registrar cliente menor de 18 o mayor de 100 annos", 28);
			break;
		case 15:
			escribirMensaje("Opcion invalida", 28);
			break;
		case 16:
			escribirMensaje("No hay pacientes resgistrados", 28);
			break;
		case 17:
			escribirMensaje("Valor invalido", 28);
			escribirMensaje("1 = O+, 2 = O-, 3 = A+, 4 = A-, 5 = B+, 6 = B-, 7 = AB+, 8 = AB-", 29);
			break;
		case 18:
			escribirMensaje("Hora invalido utilize formado 24 Hrs separado por :", 28);
			break;
	}
	moverCursor(29,20);
	system("pause");
	borrar(1, 27, 79, 29);
	
	return 1;
}

int validarCadena(char cCadena[]){  //Valida que el nombre no contenga digitos ni simbolos
/*Programa: validarCadena
Objetivo: Función que permita leer cadenas sólo de caracteres alfabéticos 
y retorne la cadena leída sólo hasta que sea correcta
Autor: Martínez Carranza Alexa S.
Fecha: 5/05/19
*/

    int i;
    
    if (validarLongitudeCadena(cCadena, 30) != 0){
		
		return error(4);
		
	}
	
    for(i=0 ; i<strlen(cCadena); i++){
        if(!(cCadena[i]>=65 && cCadena[i]<=90 || cCadena[i]>=97 && cCadena[i]<=122 || cCadena[i]==32)){
           return error(2);
        }
    }
    return 0;
}

int validarApellido(char cCadena[]){  //Valida que el apellido paterno no contenga digitos ni simbolos
/*Programa: validarApellido
Objetivo: Función que valida una cadenas sólo de caracteres alfabéticos 
y retorne la cadena leída sólo hasta que sea correcta
Autor: Martínez Carranza Alexa S.
Fecha: 5/05/19
*/
    int i;
    
    if (validarLongitudeCadena(cCadena, 15) != 0){
		
		return error(4);
		
	}
	
    for(i=0 ; i<strlen(cCadena); i++){
        if(!(cCadena[i]>=65 && cCadena[i]<=90 || cCadena[i]>=97 && cCadena[i]<=122 || cCadena[i]==32)){
           return error(2);
        }
    }
    return 0;
}

char ValidarCaracter(char cCaracter){  //valida si se ingreso un SI o  un NO
/*
Programa: ValidarCaracter
AUTOR: Duarte Sierra Pamela
FECHA: 09 / 05 / 2019
OBJETIVO: Que permita leer sólo S o N y retorne verdadero 
si fue S o falso si fue N sólo hasta que sea S o N.*/
        
        cCaracter = toupper(cCaracter);
        
        if( cCaracter == 'S'){
            
            return cCaracter;

        }else if ( cCaracter == 'N'){
            
            return cCaracter;

        } else {
            error(3);
            return '1';
        
        }
    

}

int validarLongitudeCadena(char cCadena[], int eLong){  //Valida que el nombre no contenga digitos ni simbolos
/*Programa: F4.c
Objetivo:  Función que valida que una cadena no supere un determinado número de caracteres cualesquiera y retorna la cadena leída sólo hasta que sea correcta
ni menos de 15) y retorne la cadena leída sólo hasta que sea correcta.
Autor: Martínez Carranza Alexa.
Fecha 9/05/19
*/
   
    if(eLong >= strlen(cCadena)){
		return 0;
	}
	error(4);
}

void borrar(int eCol1, int eRen1, int eCol2, int eRen2){  //borra un espacio en pantalla
/*Función: F17borrar
Autor: Ivan Tronco
Objetivo: Borrar un área específica de pantalla
Fecha: 10-05-19
*/
	
	int  i, j;
	

		for(i=0; i<=eRen2 - eRen1; i++){
			for(j=0; j<=eCol2 - eCol1; j++){
				moverCursor (eRen1 + i, eCol1 + j);
				printf (" ");
			}
		}
}

void escribirMensaje(char *sMensaje, int eRenglon){   //centra y escribe un mensaje en renglon determinado
/*
Programa: escribirMensaje
Autor: Magín Gómez Nancy Vanessa
Objetivo: Crear una función que reciba como parámetros un mensaje y  lo muestre centrado en la línea 25 de la pantalla 
Fecha: 5 de mayo de 2019
*/
	
	COORD coord;
 	coord.Y = (eRenglon - 1);
 	coord.X = (80 - (int)strlen(sMensaje))/2;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
 	printf("%s", sMensaje);
}//escribirMensaje

int validarTelefono(char *cCadena){  //valida que el numero telefonico solo sean digitos y este conformado de 10 digitos
	
	int i;
	
	if (10 != strlen(cCadena)){
		
		return error(7);
		
	}
	
    if (validarNumero(cCadena) == 0){
	
    	return 0;    
    }
    
}

int validarCedula(char *cCadena){  //valida que el numero telefonico solo sean digitos y este conformado de 10 digitos
	
	int i;
	
	if (8 != strlen(cCadena)){
		
		return error(7);
		
	}
	
    if (validarNumero(cCadena) == 0){
	
    	return 0;    
    }
    
}

char validarSexo(char cCaracter){  //valida si se ingreso un SI o  un NO
 /*
Programa: F3.c
AUTOR: Duarte Sierra Pamela
FECHA: 09 / 05 / 2019
OBJETIVO: Que permita leer sólo M o F */
       
        cCaracter = toupper(cCaracter);
        
        if( cCaracter == 'M'){
            
            return cCaracter;

        }else if ( cCaracter == 'F'){
            
            return cCaracter;

        } else {
            error(8);
            return '1';
        
        }
    
}


int validarNumero(char cCadena[]){  //Valida que una cadena sea de solo digitos
/*Programa: validarNumero
Objetivo: Función que permita leer cadenas sólo de caracteres numericos 
y retorne la cadena leída sólo hasta que sea correcta
Autor: Martínez Carranza Alexa S.
Fecha: 5/05/19
*/

    int i;
    
    for(i=0 ; i<strlen(cCadena); i++){
    	
        if(!(cCadena[i]>=48 && cCadena[i]<=57 || cCadena[i] == 46)){
            
           return error(1);
        }
        return 0;
	}
}

int validarFecha(TrFecha rFecha){
/*
Programa: validarFecha
Autor: Rivera Jiménez Leonardo 
Fecha: 10-05-2019
Objetivo: Programa que permita leer una fecha correctamente (dd/mm/aaaa)
y la retorne sólo hasta que sea correcta (debe validar que al menos el día y el mes sean correctos)
*/

	if(rFecha.eAnio == 1){
		return error(5);
	}else {
	
		switch(rFecha.eMes){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(rFecha.eDia >= 1 && rFecha.eDia <= 31){
					return 0;//fecha correcta
				}else{
					return error(13);				
				}
				break;			
			case 4:
			case 6:
			case 9:
			case 11:
				if(rFecha.eDia >= 1 && rFecha.eDia <= 30){			
					return 0;				
				}else{				
					return error(13);				
				}
				break;		
			case 2:
				if(rFecha.eAnio % 4 == 0 && rFecha.eAnio % 100 != 0 || rFecha.eAnio % 400 == 0){
					if(rFecha.eDia >= 1 && rFecha.eDia <= 29){					
						return 0;
					}else{					
						return error(13);
					}
					if(rFecha.eDia >= 1 && rFecha.eDia <= 28){					
					}else{					
						return error(13);
					}
				}
				break;
			default :
				return error(12);
		}
	}
	return 0;
}

int validarHora(TrHora rHora){
	
	if(rHora.eHora <= 23 && rHora.eHora >= 0){
		
		if(rHora.eMin <=59 && rHora.eMin >= 0){
			
			return 0;
		}else{
			
			return error(18);
		}
	}else{
		
		return error(18);
		
	}
}
