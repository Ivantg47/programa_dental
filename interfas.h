/*Programa: interfas.h 
Autor: Ivan Tronco
Objetivo: Mostrar una innterfas
Fecha: 09-05-19
*/

#include<windows.h>

void cambiarColor();
void moverCursor(int eRenglon, int eColumna);
void dibujarMarco();
int centrar(int eRenglon, char *cCadena);

void cambiarColor(){
	
	system("color 17");
	system("cls");
}

void moverCursor(int eRenglon, int eColumna){
	COORD coord;
	
	coord.Y = eRenglon;
	coord.X = eColumna;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarMarco(){
	
	int eRenglon, eColumna;
	
	cambiarColor();
	
	printf("%c", 201); //218 - 201
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 187); //191 - 187 apertura marco inferior
	
	for (eRenglon = 2; eRenglon < 29; eRenglon++){
		printf("%c                                       "
			"                                        %c\n", 186, 186); //179 - 186
	}
	
	printf("%c", 200); //192 - 200
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c", 188); //217 - 188
	
	
	//Marco interno
	moverCursor(2,3);
	printf("%c", 201); //218 - 201
	
	for(eColumna = 1; eColumna < 74; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 187); //191 - 187 apertura marco inferior
	
	
	for (eRenglon = 3; eRenglon < 24; eRenglon++){
		moverCursor(eRenglon,3);
		printf("%c                                     "
			"                                    %c\n", 186, 186); //179 - 186
	}
	
	moverCursor(24,3);
	printf("%c", 200); //192 - 200
	
	for(eColumna = 1; eColumna < 74; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c", 188); //217 - 188
	
}

int centrar(int eRenglo, char *cCadena){
    moverCursor(eRenglo, (80 - (int)strlen(cCadena))/2);/*Se posiciona el cursor en el renglón recibido y 
	a 121(lo que mide la ventana), le resta la longitud de la cadena entre 2*/
    printf("%s", cCadena);//Impreme la cadena
}
