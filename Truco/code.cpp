#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int palos[3][2], nums[3][2], p, selec = 1, disp[3] = {1, 1, 1};
int reales[10] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
void dar(), aux(int x, int y), mostrar(), val(), tomar_tecla();
char cadena(int i), car;
int main() {
	dar();
	mostrar();
	tomar_tecla();
	aux(0, 20);
	return 0;
}
void tomar_tecla(){
	aux(0, 16);
	printf("                                                        ");
	aux((selec == 0) ? 1 : (selec == 1) ? 21 : (selec == 2) ? 41 : 1, 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
	car = 0;
	while(car != 75 && car != 77)
	car = getch();
	if(car == 75){
		if(selec == 2){
			selec = 1;
		}else{
			if(selec == 1){
				selec = (disp[0] == 1) ? 0 : selec;
			}
		}
	}
	if(car == 77){
		if(selec == 0){
			selec = (disp[1] == 1) ? 1 : (disp[2] == 1) ? 2 : selec;
		}else{
			if(selec == 1){
				selec = (disp[2] == 1) ? 2 : selec;
			}
		}
	}
	tomar_tecla();
}
void mostrar(){
	int suma;
	for(int i = 0; i < 3; i++){
											//<Esto dibuja la forma de la carta>
		suma = (i == 1) ? 20 : (i == 2) ? 40 : 0;
		aux(1 + suma, 2); printf("---------------");
		aux(2 + suma, 3); printf("%d", reales[nums[i][0]]);
		aux(suma, 3); printf("|"); aux(suma, 4); printf("|"); aux(suma, 5); printf("|");
		aux(suma, 6); printf("|"); aux(suma, 7); printf("|"); aux(suma, 8); printf("|");
		aux(suma, 9); printf("|"); aux(suma, 10); printf("|"); aux(suma, 11); printf("|");
		aux(suma, 12); printf("|"); aux(suma, 13); printf("|"); aux(suma, 14); printf("|");
		
		aux(15 + suma, 3); printf("|"); aux(15 + suma, 4); printf("|"); aux(15 + suma, 5); printf("|");
		aux(15 + suma, 6); printf("|"); aux(15 + suma, 7); printf("|"); aux(15 + suma, 8); printf("|");
		aux(15 + suma, 9); printf("|"); aux(15 + suma, 10); printf("|"); aux(15 + suma, 11); printf("|");
		aux(15 + suma, 12); printf("|"); aux(15 + suma, 13); printf("|"); aux(15 + suma, 14); printf("|");
		aux(1 + suma, 15); printf("---------------");
												//</Esto dibuja la forma de la carta>
												//<Esto dibuja el palo de la carta>
		p = palos[i][0];
		 aux(4 + suma, 6); printf("%s", (p == 0) ? "LLLLLL" : (p == 1) ? "FFFFFF  " : (p == 2) ? " CCCCCC " : (p == 3) ? " LLLLLLL" : "");
		 aux(4 + suma, 7); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF   FF " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
		 aux(4 + suma, 8); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF  FF  " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
		 aux(4 + suma, 9); printf("%s", (p == 0) ? "LLLL  " : (p == 1) ? "FFFFF   " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
		aux(4 + suma, 10); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF  FFF " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
		aux(4 + suma, 11); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF    FF" : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
		aux(4 + suma, 12); printf("%s", (p == 0) ? "LLLLLL" : (p == 1) ? "FFFFFFF " : (p == 2) ? " CCCCCC " : (p == 3) ? " LLLLLLL" : "");
												//</Esto dibuja el palo de la carta>
												//<Esto dibuja la línea de selección>
												//<Esto dibuja la línea de selección>
												//<Esto muestra los controles>
		aux(60, 3);  printf("ESC: al mazo");
		aux(60, 5);  printf("FLECHAS: seleccionar carta");
		aux(60, 7);  printf("ENTER: jugar");
		aux(60, 9);  printf("Q: truco");
		aux(60, 11); printf("W: retruco");
		aux(60, 13); printf("E: VALE CUATRO");
		aux(60, 15); printf("A: envido");
		aux(60, 17); printf("S: real envido");
		aux(60, 19); printf("D: falta envido");
		aux(60, 21); printf("F: FLOR");
	}
}
void dar(){
	srand(time(NULL));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			palos[j][i] = rand() % 4;
			nums[j][i] = rand() % 10;
			val();
			printf("%d", nums[j][i]);
			printf("%d  ", palos[j][i]);
		}
	}
}
void val(){
	bool iguales;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 3; l++){
					if(i != k || j != l){
						if(nums[j][i] == nums[l][k] && palos[j][i] == palos[l][k]){
							nums[l][k] = rand() % 10;
						}
					}
				}
			}
		}
	}
	if(iguales == true){
		val();
	}
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}

