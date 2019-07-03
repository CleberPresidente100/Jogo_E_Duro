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

#include "tela.h"
#include "carro.h"
#include "pista.h"


/* Constantes */

#define QUANTIDADE_MAXIMA_DE_BURACOS 3

const unsigned char BURACO[3][3][3] =	{
											{
												{' ', ' ', ' '},
												{' ', 219, ' '},
												{' ', ' ', ' '}
											},
											{
												{' ', 219, 219},
												{' ', 219, 219},
												{' ', ' ', ' '}
											},
											{
												{' ', 219, ' '},
												{219, 177, 219},
												{' ', 219, ' '}
											}/*
											{
												{' ', ' ', 219, ' ', ' '},
												{' ', 219, 177, 219, ' '},
												{219, 177, 176, 177, 219}
												{' ', 219, 177, 219, ' '},
												{' ', ' ', 219, ' ', ' '},
											}*/
										};


/* Estruturas */


/* Variáveis Globais */
	unsigned char reta[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];
	unsigned char curva_direita[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];
	unsigned char curva_esquerda[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];
	//unsigned char pista_a_ser_exibida[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];


void Cria_Pistas()
{
	int indice = 0;
	
	Cria_Pista_Reta();
	
		
}



void Cria_Pista_Reta()
{
	int linha = 0;
	int coluna = 0;
	
	int centro_tela = TAMANHO_TELA_COLUNAS / 2;
	
	/* Inicializa a Matriz */
	for(linha = 0; linha < TAMANHO_PISTA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PISTA_COLUNAS; coluna++)
		{
			reta[linha][coluna] = 0;
		}
	}
	
	
	/* Preenche a Matriz com a Pista */
	for(linha = 0; linha < TAMANHO_PISTA_LINHAS; linha++)
	{
		/* Borda Esquerda da Pista */
		reta[linha][centro_tela - (linha)]		= 177;
		reta[linha][centro_tela - (linha + 1)]	= 219;
		
		/* Borda Direita da Pista */
		reta[linha][centro_tela + (linha + 1)]	= 177;
		reta[linha][centro_tela + (linha + 2)]	= 219;
	}
}



void Atualiza_Pista(char pista[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS], int pista_linha_falha)
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_PISTA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PISTA_COLUNAS; coluna++)
		{
			if(linha != pista_linha_falha)
			{
				/* Temporário até as curvas serem implementadas */
				pista[linha][coluna] = reta[linha][coluna];
			}
			else
			{
				pista[linha][coluna] = 0;
			}
		}
	}
}



int Verifica_Colisao_Pista(int posicao_carro)
{
	/* Temporário até as curvas serem implementadas */
	if	(
			(posicao_carro == -22) ||
			(posicao_carro == 23)
		)
	{
		return 1;
	}
	
	return 0;
}



int Verifica_Colisao_Buraco(int posicao_carro)
{
	/* Temporário até as curvas serem implementadas */
	return 0;
}







