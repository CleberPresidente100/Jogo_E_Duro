/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/


/* Bibliotecas */
#include <windows.h>




void gotoxy( int linha, int coluna )
{
   COORD coord;
   coord.X = (short)coluna;
   coord.Y = (short)linha;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





