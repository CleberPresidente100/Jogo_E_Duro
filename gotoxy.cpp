/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2� Semestre Ci�ncia da Computa��o
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





