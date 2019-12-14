#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define vec_num 0
void aux(int x, int y), dibujar(), vec_form(int val), mover(), dib_sel();
void DLV(int x, int y, int lon), setcursor(bool visible, DWORD size);
int mesa[9], xP, yP, selec = 4, ex = 0;
int main(){
	srand(time(NULL));
	int jug1 = 1 + rand() % 2;
	vec_form(vec_num);
	setcursor(0, 0);
	dibujar();
	mover();
	return 0;
}
void mover(){
	char car = 0;
	while(ex == 0){
		while(car != 13 && car != 75 && car != 77 && car != 72 && car != 80) car = getch();
		switch(car){
			case 72:
				if(selec > 2 && mesa[selec - 2] == vec_num){
					selec -= 3;
				}
			break;
			case 80:
				if(selec < 6 && mesa[selec + 3] == vec_num){
					selec += 3;
				}
			break;
			case 75:
				
				if(selec%3 != 0 && mesa[selec - 1] == vec_num){
					selec--;
				}
			break;
			case 77:
				if((selec+1)%3 != 0 && mesa[selec + 1] == vec_num){
					selec ++;
				}
			break;
		}
		aux(0, 0); printf("%d", selec);
		dib_sel(true);
		car = 0;
	}
}
void dib_sel(bool dib){
	xP = (selec == 0 || selec == 3 || selec == 6) ? 11 : (selec == 1 || selec == 4 || selec == 7) ? 25 : 38;
	yP = (selec < 3) ? 4 : (selec < 6) ? 15 : 26;
	aux(xP, yP + 3); printf((dib == 1) ? " ------ " : "        ");
	aux(xP, yP + 4); printf((dib == 1) ? "|      |" : "        ");
	aux(xP, yP + 5); printf((dib == 1) ? "|      |" : "        ");
	aux(xP, yP + 6); printf((dib == 1) ? "|      |" : "        ");
	aux(xP, yP + 7); printf((dib == 1) ? "|      |" : "        ");
	aux(xP, yP + 8); printf((dib == 1) ? " ------ " : "        ");
}
void dibujar(){
	system("cls");
	aux(9, 15);printf("----------------------------------------");
	aux(9, 26);printf("----------------------------------------");
	DLV(22, 4, 34);
	DLV(35, 4, 34);
	for(int pos = 0; pos < 9; pos++){
		xP = (pos == 0 || pos == 3 || pos == 6) ? 11 : (pos == 1 || pos == 4 || pos == 7) ? 24 : 37;
		yP = (pos < 3) ? 4 : (pos < 6) ? 15 : 26;
		aux(xP, yP + 2); printf((mesa[pos] == 1) ? " X      X" :(mesa[pos] == 2) ? "    OO   " : "");
		aux(xP, yP + 3); printf((mesa[pos] == 1) ? "  X    X" : (mesa[pos] == 2) ? "  OO  OO  " : "");
		aux(xP, yP + 4); printf((mesa[pos] == 1) ? "   X  X" :  (mesa[pos] == 2) ? " OO    OO " : "");
		aux(xP, yP + 5); printf((mesa[pos] == 1) ? "    XX" :   (mesa[pos] == 2) ? "OO      OO" : "");
		aux(xP, yP + 6); printf((mesa[pos] == 1) ? "    XX" :   (mesa[pos] == 2) ? " OO    OO " : "");
		aux(xP, yP + 7); printf((mesa[pos] == 1) ? "   X  X" :  (mesa[pos] == 2) ? "  OO  OO  " : "");
		aux(xP, yP + 8); printf((mesa[pos] == 1) ? "  X    X" : (mesa[pos] == 2) ? "    OO    " : "");
		aux(xP, yP + 9); printf((mesa[pos] == 1) ? " X      X" :(mesa[pos] == 2) ? "          " : "");
	}
}
void DLV(int x, int y, int lon){
	for(int i =  y; i < lon + y; i++){
		aux(x, i);
		printf("|");
	}
}
void vec_form(int val){
	for(int i = 0; i < 9; i++){
		mesa[i] = val;
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
void setcursor(bool visible, DWORD size){ // set bool visible = 0 - invisible, bool visible = 1 - visible
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
