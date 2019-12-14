#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char car;
void aux(int x, int y);
int main() {
	car = getch();
	aux(rand() % 70, rand() % 20);printf("%c", car);
	if(car != 27){main();}
	return 0;
}

void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
