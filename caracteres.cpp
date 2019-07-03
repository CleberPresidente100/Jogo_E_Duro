/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/


/* Bibliotecas */
#include <stdio.h>

#include "caracteres.h"


/* Constantes */

const unsigned char NUMERO_0[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{' ', 219, 219, ' '},
																						{219, ' ', ' ', 219},
																						{219, ' ', ' ', 219},
																						{219, ' ', ' ', 219},
																						{' ', 219, 219, ' '}
																					};

const unsigned char NUMERO_1[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{' ', ' ', ' ', 219},
																						{' ', ' ', 219, 219},
																						{' ', 219, ' ', 219},
																						{' ', ' ', ' ', 219},
																						{' ', ' ', ' ', 219}
																					};

const unsigned char NUMERO_2[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{219, 219, 219, ' '},
																						{' ', ' ', ' ', 219},
																						{' ', 219, 219, ' '},
																						{219, ' ', ' ', ' '},
																						{219, 219, 219, 219}
																					};

const unsigned char NUMERO_3[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{219, 219, 219, ' '},
																						{' ', ' ', ' ', 219},
																						{' ', 219, 219, ' '},
																						{' ', ' ', ' ', 219},
																						{219, 219, 219, ' '}
																					};

const unsigned char NUMERO_4[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{' ', ' ', 219, ' '},
																						{' ', 219, ' ', ' '},
																						{219, ' ', ' ', 219},
																						{219, 219, 219, 219},
																						{' ', ' ', ' ', 219}
																					};

const unsigned char NUMERO_5[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{219, 219, 219, 219},
																						{219, ' ', ' ', ' '},
																						{219, 219, 219, 219},
																						{' ', ' ', ' ', 219},
																						{219, 219, 219, ' '}
																					};

const unsigned char NUMERO_6[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{' ', 219, 219, 219},
																						{219, ' ', ' ', ' '},
																						{219, 219, 219, 219},
																						{219, ' ', ' ', 219},
																						{' ', 219, 219, ' '}
																					};

const unsigned char NUMERO_7[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{219, 219, 219, 219},
																						{' ', ' ', ' ', 219},
																						{' ', ' ', 219, ' '},
																						{' ', 219, ' ', ' '},
																						{' ', 219, ' ', ' '}
																					};

const unsigned char NUMERO_8[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{' ', 219, 219, ' '},
																						{219, ' ', ' ', 219},
																						{' ', 219, 219, ' '},
																						{219, ' ', ' ', 219},
																						{' ', 219, 219, ' '}
																					};

const unsigned char NUMERO_9[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS] =	{
																						{219, 219, 219, 219},
																						{219, ' ', ' ', 219},
																						{' ', 219, 219, 219},
																						{' ', ' ', ' ', 219},
																						{219, 219, 219, ' '}
																					};

/* Estruturas */


/* Funções Privadas */
void Exibir_na_Tela(const unsigned char Numero[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS]);
	


void Exibir_Numero(int numero)
{
	switch(numero)
	{
		case 0:
			Exibir_na_Tela(NUMERO_0);
		break;
		
		case 1:
			Exibir_na_Tela(NUMERO_1);
		break;
		
		case 2:
			Exibir_na_Tela(NUMERO_2);
		break;
		
		case 3:
			Exibir_na_Tela(NUMERO_3);
		break;
		
		case 4:
			Exibir_na_Tela(NUMERO_4);
		break;
		
		case 5:
			Exibir_na_Tela(NUMERO_5);
		break;
		
		case 6:
			Exibir_na_Tela(NUMERO_6);
		break;
		
		case 7:
			Exibir_na_Tela(NUMERO_7);
		break;
		
		case 8:
			Exibir_na_Tela(NUMERO_8);
		break;
		
		case 9:
			Exibir_na_Tela(NUMERO_9);
		break;
	}
}


void Exibir_na_Tela(const unsigned char Numero[TAMANHO_CARACTER_LINHAS][TAMANHO_CARACTER_COLUNAS])
{
	int linha = 0;
	int coluna = 0;
	
	for(linha = 0; linha < TAMANHO_CARACTER_LINHAS; linha++)
	{
		printf("\n");
		
		for(coluna = 0; coluna < TAMANHO_CARACTER_COLUNAS; coluna++)
		{
			printf("%c", Numero[linha][coluna]);
		}
	}
}



unsigned char Montar_Caractere(int numero, int linha, int coluna)
{
	
	switch(numero)
	{
		case 0:
			return NUMERO_0[linha][coluna];
		break;
		
		case 1:
			return NUMERO_1[linha][coluna];
		break;
		
		case 2:
			return NUMERO_2[linha][coluna];
		break;
		
		case 3:
			return NUMERO_3[linha][coluna];
		break;
		
		case 4:
			return NUMERO_4[linha][coluna];
		break;
		
		case 5:
			return NUMERO_5[linha][coluna];
		break;
		
		case 6:
			return NUMERO_6[linha][coluna];
		break;
		
		case 7:
			return NUMERO_7[linha][coluna];
		break;
		
		case 8:
			return NUMERO_8[linha][coluna];
		break;
		
		case 9:
			return NUMERO_9[linha][coluna];
		break;
	}
}






