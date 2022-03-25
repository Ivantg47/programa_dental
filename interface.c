int centrar(int, char *cCadena);
void cambiarColor();
void moverCursor(int, int);
void dibujarMarco();
void dibujarMarco2();
void dibujarMarco3();

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
	
	printf("%c", 177); //218 - 201
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 177); //196 - 205
	}
	
	printf("%c\n", 177); //191 - 187
	
	for (eRenglon = 2; eRenglon < 29; eRenglon++){
		printf("%c%c                                      "
		"                                       %c%c\n", 177, 177, 177, 177); //179 - 186
	}
	
	printf("%c", 177); //192 - 200
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 177); //196 - 205
	}
	
	printf("%c", 177); //217 - 188
}

int centrar(int eRenglon, char *cCadena){
    moverCursor(eRenglon, (80 - (int)strlen(cCadena))/2);/*Se posiciona el cursor en el renglón recibido y 
	a 121(lo que mide la ventana), le resta la longitud de la cadena entre 2*/
    printf("%s", cCadena);//Impreme la cadena
}

void dibujarMarco2(){
	
	int eRenglon, eColumna;
	
	cambiarColor();
	
	printf("%c", 201); //218 - 201
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 187); //191 - 187
	
	for (eRenglon = 2; eRenglon < 3; eRenglon++){
		printf("%c                                       "
			"                                        %c\n", 186, 186); //179 - 186 cierre marco superior
	}
	
	printf("%c", 204); //218 - 201 principio inicio marco inferior-superior
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 185); //191 - 187 fin inicio marco inferior-superior
	
	for (eRenglon = 2; eRenglon < 28; eRenglon++){
		printf("%c                                       "
			"                                        %c\n", 186, 186); //179 - 186 intermedio marco inferior
	}
	
	printf("%c", 200); //192 - 200 inicio cierre marco inferior
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c", 188); //217 - 188 fin cierre marco inferior
}

void dibujarMarco3(){
	
	int eRenglon, eColumna;
	
	cambiarColor();
	
	printf("%c", 201); //218 - 201
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 187); //191 - 187
	
	for (eRenglon = 2; eRenglon < 5; eRenglon++){
		printf("%c                                       "
			"                                        %c\n", 186, 186); //179 - 186 cierre marco superior
	}
	
	printf("%c", 204); //218 - 201 principio inicio marco inferior-superior
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c\n", 185); //191 - 187 fin inicio marco inferior-superior
	
	for (eRenglon = 2; eRenglon < 26; eRenglon++){
		printf("%c                                       "
			"                                        %c\n", 186, 186); //179 - 186 intermedio marco inferior
	}
	
	printf("%c", 200); //192 - 200 inicio cierre marco inferior
	
	for(eColumna = 1; eColumna < 80; eColumna++){
		printf("%c", 205); //196 - 205
	}
	
	printf("%c", 188); //217 - 188 fin cierre marco inferior
}
