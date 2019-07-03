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
#include <locale.h>	/* Biblioteca para Acentuação */
#include <string.h>

#include "tela.h"
#include "carro.h"
#include "pista.h"
#include "gotoxy.h"
#include "caracteres.h"


/* Constantes */
/* PLACAR */
	#define POSICAO_PLACAR_DIGITO_1 0
	#define POSICAO_PLACAR_DIGITO_2 5
	#define POSICAO_PLACAR_DIGITO_3 10

/* TABELA DERROTA */
	#define DERROTA_NUMERO_LINHAS 9
	#define DERROTA_NUMERO_COLUNAS 29
	#define DERROTA_LINHA (TAMANHO_PLACAR_LINHAS + 1)
	#define DERROTA_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - 13)

/* TABELA COM O NOME DO JOGO E MENU */
	#define NOME_DO_JOGO_NUMERO_LINHAS 19
	#define NOME_DO_JOGO_NUMERO_COLUNAS 27
	#define NOME_DO_JOGO_LINHA (TAMANHO_PLACAR_LINHAS - 3)
	#define NOME_DO_JOGO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - 11)

/* TABELA DE NOVO RECORDE */
/*
	#define NOVO_RECORDE_LINHAS 6
	#define NOVO_RECORDE_COLUNAS 30
	#define NOVO_RECORDE_POSICAO_LINHA 3
	#define NOVO_RECORDE_POSICAO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - (NOVO_RECORDE_COLUNAS / 2) + 2)
	*/
	
/* TABELA DE RANKING */
/*
	#define ARQUIVO_RECORDS "records.txt"
	
	#define RANKING_LINHAS 17
	#define RANKING_COLUNAS 40
	#define RANKING_POSICAO_LINHA 3
	#define RANKING_POSICAO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - (RANKING_COLUNAS / 2) + 2)
*/



const unsigned char CARRO[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																			{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																			{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																			{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																			{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																			{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																			{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																		};


const unsigned char DERROTA[DERROTA_NUMERO_LINHAS][DERROTA_NUMERO_COLUNAS] =	{
																					{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																					{186, 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, 219, ' ', ' ', 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, 219, 219, ' ', 219, 219, 219, 186},
																					{186, 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
																					{186, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, 219, ' ', ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, 219, 219, 186},
																					{186, 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
																					{186, 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
																					{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
																					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
																					{' ', ' ', ' ', ' ', ' ', 'A', 'p', 'e', 'r', 't', 'e', ' ', 'E', 'S', 'C', ' ', 'p', 'a', 'r', 'a', ' ', 'S', 'a', 'i', 'r', ' ', ' ', ' ', ' '}
																				};


const unsigned char NOME_DO_JOGO[NOME_DO_JOGO_NUMERO_LINHAS][NOME_DO_JOGO_NUMERO_COLUNAS] =	{
																								{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																								{186, ' ', ' ', ' ', 223, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', 223, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', 219, 219, ' ', ' ', ' ', 219, ' ', ' ', 186},
																								{186, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 186},
																								{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', 186},
																								{186, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 186},
																								{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, ' ', ' ', ' ', 219, ' ', ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
																								{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
																								{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', '-', ' ', 'J', 'o', 'g', 'a', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ', '-', ' ', 'R', 'e', 'c', 'o', 'r', 'd', 'e', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', '3', ' ', '-', ' ', 'S', 'o', 'b', 'r', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', '4', ' ', '-', ' ', 'S', 'a', 'i', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																								{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
																							};


/*
{201, 205, 187},
{186, 186},
{200, 205,188}
*/


/* Estruturas */

struct struct_Carro
{
	//int pos_top_left_linha; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Carro
	//int pos_top_left_coluna; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Carro
	
	int posicao_atual_carro;
	unsigned char carro[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS];
} carro;
	
struct struct_Placar
{
	//int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Placar
	//int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Placar
	
	unsigned char placar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS];
} placar;

struct struct_Tela
{
	//int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	//int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	unsigned char tela_atual;
	unsigned char proxima_tela;
	char tela[NUMERO_DE_TELAS][TAMANHO_TELA_LINHAS][TAMANHO_TELA_COLUNAS];
} tela;


struct struct_Buraco
{
	int linha; // Linha em que o Buraco está.
	int coluna; // A qual Coluna ele Pertence.
	int regiao;
	int tamanho;
	int pontuacao;
	
	//char buraco[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];
} buraco;


int fim_de_jogo;
int pista_linha_falha;
char pista_a_ser_exibida[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];



/* Funções Privadas */


/* GERAIS */
void Realiza_Inicializacao_das_Estruturas()
{
	pista_linha_falha = -1;
	Cria_Carro();
	Cria_Pistas();
	Cria_Placar();
	Cria_Buraco();
	Alterar_Placar(0);
	Inicializa_Telas();
}



/* CARRO */
void Cria_Carro()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																	{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																	{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																	{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																	{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																	{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																	{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																};

	
	/* Carrega o Carro para dentro da Matriz carro */
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			carro.carro[linha][coluna] = auxiliar[linha][coluna];
		}
	}
	
	carro.posicao_atual_carro = 0;
}



void Move_Carro(int movimentar_carro)
{
	carro.posicao_atual_carro += movimentar_carro;
}



int Inserir_Carro_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	int colisao = 0;
	char auxiliar;
	
		
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			/* Verifica se o Carro Bateu em Algo */
			if(linha == TAMANHO_CARRO_LINHAS - 1)
			{
				auxiliar = tela.tela[tela.proxima_tela][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro];
				if((auxiliar != 0) && (auxiliar != BRANCO))
				/*		
				if	(
						(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != 0) &&
						(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != BRANCO) &&
						(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != carro.carro[linha][coluna])
						 
					)*/
				{
					colisao++;
				}
			}
			
			tela.tela[tela.proxima_tela][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] = carro.carro[linha][coluna];
		}
	}
	
	
	/* Verifica se o Carro Bateu em Algo */
	/*
	if	(
			Verifica_Colisao_Buraco(carro.posicao_atual_carro) ||
			Verifica_Colisao_Pista(carro.posicao_atual_carro)
		)*/
	if(colisao)
	{
		return 1;
	}
	
	return 0;	
}



/* PLACAR */
void Cria_Placar()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS] =	{
																		{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
																	};

	
	/* Define a Posição na Tela onde o Placar deve começar a ser desenhado */
	//placar.pos_top_left_linha = ESPESSURA_BORDA_TELA + 1;
	//placar.pos_top_left_coluna = ESPESSURA_BORDA_TELA + 1;
	
	/* Carrega o Placar para dentro da Matriz placar */
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			placar.placar[linha][coluna] = auxiliar[linha][coluna];
		}
	}
}



void Alterar_Placar(int pontuacao)
{
	int linha = 0;
	int coluna = 0;
	int digito = 0;
	int numero[3] = {0, 0, 0};
	
	/* Validação da Pontuação */
	if((pontuacao < 0) || (pontuacao > 999))
	{
		pontuacao = 0;
	}
	else
	{
		/* Separa os Dígitos da Pontuação */
		numero[0] = pontuacao / 100;
		numero[1] = (pontuacao - (numero[0] * 100)) / 10;
		numero[2] = (pontuacao - (numero[0] * 100) - (numero[1] * 10));
	}
	
		
	/* Insere a Pontuação */
	for(digito = 0; digito < 3; digito++)
	{
		for(linha = ESPESSURA_BORDA_PLACAR; linha < (TAMANHO_PLACAR_LINHAS - ESPESSURA_BORDA_PLACAR); linha++)
		{
			
			for(coluna = ESPESSURA_BORDA_PLACAR; coluna < (TAMANHO_CARACTER_COLUNAS + ESPESSURA_BORDA_PLACAR); coluna++)
			{
				switch(digito)
				{
					case 0:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_1] = Montar_Caractere(numero[0], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 1:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_2] = Montar_Caractere(numero[1], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 2:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_3] = Montar_Caractere(numero[2], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
				}
			}
		}
	}
}



void Inserir_Placar_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
		
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_PLACAR_LINHA][coluna + POSICAO_PLACAR_COLUNA] = placar.placar[linha][coluna];
		}
	}	
}



void Exibe_Placar()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			printf("%c", placar.placar[linha][coluna]);
		}
		
		printf("\n");
	}	
}



/* TELA */
void Inicializa_Telas()
{
	int indice = 0;
	
	/* Inicializa Variáveis */
	//tela.pos_top_left_linha = 0; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	//tela.pos_top_left_coluna = 0; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	tela.tela_atual = 0;
	tela.proxima_tela = 1;
	
	for(indice = 0; indice < NUMERO_DE_TELAS; indice++)
	{
		Limpa_Tela(indice);
	}	
}



void Limpa_Tela(unsigned char indice_tela)
{
	int linha = 0;
	int coluna = 0;
		
	
	/* Preenche a Tela com o caracter Espaço (Deixa a Tela "Em Branco") */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			tela.tela[indice_tela][linha][coluna] = BRANCO; // Caractere Espaço
		}
	}
	
	/* Coloca as Bordas Horizontais (Superior e Inferior) */
	for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
	{			
		tela.tela[indice_tela][0][coluna] = 205;
		tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][coluna] = 205;
	}
	
	/* Coloca as Bordas Verticais (Esquerda e Direita) */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{			
		tela.tela[indice_tela][linha][0] = 186;
		tela.tela[indice_tela][linha][TAMANHO_TELA_COLUNAS - 1] = 186;
	}
	
	/* Coloca as Bordas nos Vértices */
	tela.tela[indice_tela][0][0] = 201;
	tela.tela[indice_tela][0][TAMANHO_TELA_COLUNAS - 1] = 187;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][0] = 200;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][TAMANHO_TELA_COLUNAS - 1] = 188;
	
}



void Exibe_Tela()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			if(tela.tela[TELA_AUXILIAR][linha][coluna] != 0)
			{
				gotoxy(linha, coluna);
				printf("%c", tela.tela[TELA_AUXILIAR][linha][coluna]);
			}
		}
	}
}



int Atualizar_Tela()
{
	int fim_de_jogo = 0;
	
	Limpa_Tela(tela.proxima_tela);
	Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	Inserir_Buraco_na_Tela();
	fim_de_jogo = Inserir_Carro_na_Tela();
	if(fim_de_jogo)
	{
		Inserir_Mensagem_Derrota();
	}	
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
	
	/* Atualiza Índices */
	tela.tela_atual		= (~tela.tela_atual) & 0x01;
	tela.proxima_tela	= (~tela.proxima_tela) & 0x01;
	
	return fim_de_jogo;
}



void Comparar_Tela_Atual_com_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			if(tela.tela[tela.tela_atual][linha][coluna] != tela.tela[tela.proxima_tela][linha][coluna])
			{
				/* Se na Tela Atual existe um Caractere e na Próxima Tela ele foi Substituido
				por um Caractere Vazio, significa que este Caractere deve ser Apagado. */
				if((tela.tela[tela.tela_atual][linha][coluna] != 0) && (tela.tela[tela.proxima_tela][linha][coluna] == 0))
				{
					tela.tela[TELA_AUXILIAR][linha][coluna] = BRANCO;
				}
				else
				{
					tela.tela[TELA_AUXILIAR][linha][coluna] = tela.tela[tela.proxima_tela][linha][coluna];
				}
			}
			else
			{
				tela.tela[TELA_AUXILIAR][linha][coluna] = 0;
			}
		}
	}
	
}



void Inserir_Pista_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	/* Atualiza a Pista */	
	Atualiza_Pista(pista_a_ser_exibida, pista_linha_falha);
	
	/* Copia a Pista para a Próxima Tela */
	for(linha = 0; linha < TAMANHO_PISTA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PISTA_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_PISTA_LINHA][coluna + POSICAO_PISTA_COLUNA] = pista_a_ser_exibida[linha][coluna];
		}
	}
	
}



void Atualiza_Falha_Pista(int linha)
{
	pista_linha_falha = linha;
}



void Inserir_Mensagem_Derrota()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < DERROTA_NUMERO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < DERROTA_NUMERO_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + DERROTA_LINHA][coluna + DERROTA_COLUNA] = DERROTA[linha][coluna];
		}
	}
	
}


void Inserir_Nome_do_Jogo()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < NOME_DO_JOGO_NUMERO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < NOME_DO_JOGO_NUMERO_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + NOME_DO_JOGO_LINHA][coluna + NOME_DO_JOGO_COLUNA] = NOME_DO_JOGO[linha][coluna];
		}
	}
	
}



void Exibe_Menu_Principal()
{
	Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	Inserir_Carro_na_Tela();
	Inserir_Nome_do_Jogo();
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
}



void Exibe_Menu_Recordes()
{
	Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	Inserir_Carro_na_Tela();
	Inserir_Recordes();
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
}



void Exibe_Menu_Sobre()
{
	Inserir_Pista_na_Tela();
	Inserir_Carro_na_Tela();	
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
	Inserir_Texto_Sobre();
}



void Inserir_Recordes()
{
	int linha = 0;
	int coluna = 0;
	
	FILE * Arquivo;	
	char linha_arquivo [100];
	
	
	char tela_ranking [RANKING_LINHAS][RANKING_COLUNAS];
		
	
	/* Criação da Tabela de Raking em Branco e com Bordas */
	Criar_Tela_Branco_com_Bordas((char *)tela_ranking, RANKING_LINHAS, RANKING_COLUNAS);
	
	
	/* Abre Arquivo para Leitura */
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	if (Arquivo == NULL)
	{		
		/* Se o Arquivo não existir, cria um novo */
		Verifica_Arquivo_Recordes();
	}
	
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	
	
	/*	Tanto a Linha quanto a Coluna começam em 2 pois na posição 0 é colocada a borda
	e a posição 1 é o espaçamento entre a borda e o texto. */
	for(linha = 2; linha < RANKING_LINHAS - 1; linha++)
	{
		/* Lê a próxima linha do arquivo */
		fgets(linha_arquivo, (RANKING_COLUNAS - 2), Arquivo);
		
		/* Se o Fim do Arquivo não foi Alcançado, Insere a Linha Lida na Tabela de Ranking */
		if(!feof (Arquivo))
		{
			for(coluna = 2; coluna < RANKING_COLUNAS - 2; coluna++)
			{
				if((linha_arquivo[coluna - 2] == 0) || (linha_arquivo[coluna - 2] == '\n'))
				{
					break;
				}
				
				tela_ranking[linha][coluna] = linha_arquivo[coluna - 2];
			}
		}
		
	}
	
	
	/* Fecha Arquivo */
	fclose (Arquivo);
	
	
	/* Insere a Tabela na Próxima Tela a ser Exibida */
	for(linha = 0; linha < RANKING_LINHAS; linha++)
	{
		for(coluna = 0; coluna < RANKING_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + RANKING_POSICAO_LINHA][coluna + RANKING_POSICAO_COLUNA] = tela_ranking[linha][coluna];
		}
	}
	
	
}



void Inserir_Texto_Sobre()
{
	int linha = 0;
	int coluna = 0;
	int indice = 0;
	
	int linha_superior = 2;
	int linha_inferior = linha_superior + 15;
	int coluna_esquerda = 5;
	int coluna_direita = coluna_esquerda + 70;
	
	const char Texto [15][150] = {  //1234567890123456789012345678901234567890123456789012345678901234567890
									"                         Nome do Jogo: É Duro                         \0",
									"                  Desenvolvedor: Cleber da Silva Melo                 \0",
									"                                                                      \0",
									"                             Sobre o Jogo:                            \0",
									" Este é um projeto do Final do Semestre onde aplicaremos todos        \0"
									" os conhecimentos adquiridos em Linguagem C através das matérias      \0",
									" \"Algoritmos e Técnicas de Programação\" e                           \0", 
									" \"Algoritmos e Estrutura de Dados\".                                 \0",
									"                                                                      \0",
									" O objetivo deste projeto é criar um jogo similar ao Enduro do Atari  \0",
									" utilizando apenas os caracteres da tabela ASCII extendida.           \0",
									"                                                                      \0",
									" Obs.: Este projeto deve ser realizado em apenas 6 dias.              \0",
									"                                                                      \0",
									" Pressione ESC para Retornar ao Menu.                                 \0"
								};
	
	
	
	/* Permite o uso de Acentuação */
	setlocale(LC_ALL, "Portuguese");
	
		
	/* Imprime Texto */
	for(linha = 0; linha < 15; linha++)
	{
		gotoxy(linha + linha_superior + 1, coluna_esquerda + 1);
		
		for(coluna = 0; coluna < 150; coluna++)
		{
			if(Texto[linha][coluna] == '\0')
			{
				break;
			}
			
			printf("%c", Texto[linha][coluna]);
		}
	}
	
	
	
	/* Permite o uso de Caracteres da Tabela ASCII Extendida */
	setlocale(LC_ALL, "C");
	
	/* Bordas Superiores */
		/* Imprime Canto Borda Superior Esquerda */
		gotoxy(linha_superior, coluna_esquerda);
		printf("%c", 201);
		
		/* Imprime Centro Borda Superior */
		for(indice = 0; indice < 69; indice++)
		{
			printf("%c", 205);
		}
		
		/* Imprime Canto Borda Superior Direita */
		printf("%c", 187);
	
	
	/* Bordas Laterais */
		/* Imprime Bordas Laterais */
		for(indice = 0; indice < 15; indice++)
		{
			/* Borda Esquerda */
			gotoxy(linha_superior + 1 + indice, coluna_esquerda);
			printf("%c", 186);
			
			/* Borda Direita */
			gotoxy(linha_superior + 1 + indice, coluna_direita);
			printf("%c", 186);
		}
	
	
	/* Bordas Inferiores */
		/* Imprime Canto Borda Inferior Esquerda */
		gotoxy(linha_inferior, coluna_esquerda);
		printf("%c", 200);
		
		/* Imprime Centro Borda Inferior */
		for(indice = 0; indice < 69; indice++)
		{
			printf("%c", 205);
		}
		
		/* Imprime Canto Borda Inferior Direita */
		printf("%c", 188);
	
	
	
		
}



void Exibe_Tela_Novo_Recorde(int pontuacao)
{
	int linha = 0;
	int coluna = 0;
	int indice = 0;
	int pontuacao_ranking = 0;
	
	FILE * Arquivo;	
	char linha_arquivo [100];
	
	char nome_do_recordista[20];
	char pontuacao_string[3];
	char mensagem[3][29] =	{	//12345678901234567890123456789
								{"       NOVO RECORDE !  "},
								{"         XXX PONTOS    "},							
								{"     DIGITE O SEU NOME:"}
							};
	
	/*
		=========================
			NOVO RECORDE !
			XXX PONTOS
			DIGITE O SEU NOME:
			XXXXXXXXXXXXXXXX
			================
	*/
	
	char tela_novo_recorde [NOVO_RECORDE_LINHAS][NOVO_RECORDE_COLUNAS];
		
	
	/* Criação da Tabela de Novo Recorde em Branco e com Bordas */
	Criar_Tela_Branco_com_Bordas((char *)tela_novo_recorde, NOVO_RECORDE_LINHAS, NOVO_RECORDE_COLUNAS);
	
	/* Adiciona a Mensagem na Tela*/
	for(linha = 0; linha < 3; linha++)
	{
		for(coluna = 0; coluna < 29; coluna++)
		{
			if(mensagem[linha][coluna] != 0)
			{
				tela_novo_recorde[linha + 1][coluna + 1] = mensagem[linha][coluna];
			}
		}
	}
	
	/* Transforma a Pontuação em Caracteres */
	Transforma_Numero_em_String(pontuacao_string, pontuacao);
	
	
	/* Adiciona Pontuação na Tela */
	for(indice = 0, coluna = 10; indice < 3; coluna++, indice++)
	{
		tela_novo_recorde[2][coluna] = pontuacao_string[indice];
	}
	
	/* Insere a Tabela na Próxima Tela a ser Exibida */
	for(linha = 0; linha < NOVO_RECORDE_LINHAS; linha++)
	{
		for(coluna = 0; coluna < NOVO_RECORDE_COLUNAS; coluna++)
		{
			tela.tela[TELA_AUXILIAR][linha + NOVO_RECORDE_POSICAO_LINHA][coluna + NOVO_RECORDE_POSICAO_COLUNA] = tela_novo_recorde[linha][coluna];
		}
	}
	
	
}



void Criar_Tela_Branco_com_Bordas(char *tela, int NUMERO_DE_LINHAS, int NUMERO_DE_COLUNAS)
{
	int linha = 0;
	int coluna = 0;	
	
	const int VERTICE_SUPERIOR_ESQUERDO	= 0;
	const int VERTICE_SUPERIOR_DIREITO	= NUMERO_DE_COLUNAS - 1;
	const int VERTICE_INFERIOR_ESQUERDO	= (NUMERO_DE_LINHAS - 1) * NUMERO_DE_COLUNAS;
	const int VERTICE_INFERIOR_DIREITO	= (NUMERO_DE_LINHAS * NUMERO_DE_COLUNAS) - 1;
	
	
	/* Apaga a Tabela do Ranking e Coloca Bordas */
	for(linha = 0; linha < NUMERO_DE_LINHAS; linha++)
	{
		for(coluna = 0; coluna < NUMERO_DE_COLUNAS; coluna++)
		{
			if((linha == 0) || (linha == NUMERO_DE_LINHAS - 1))
			{
				tela[(linha * NUMERO_DE_COLUNAS) + coluna] = 205;
			}
			else if((coluna == 0) || (coluna == NUMERO_DE_COLUNAS - 1))
			{
				tela[(linha * NUMERO_DE_COLUNAS) + coluna] = 186;
			}
			else
			{
				tela[(linha * NUMERO_DE_COLUNAS) + coluna] = BRANCO;
			}
		}
	}
	
	/* Caracteres das Bordas */
	/*
	{201, 205, 187},
	{186, 186},
	{200, 205,188}
	*/

	/* Acrescenta os Vértices das Bordas */
	tela[VERTICE_SUPERIOR_ESQUERDO]	= 201;
	tela[VERTICE_SUPERIOR_DIREITO]	= 187;	
	tela[VERTICE_INFERIOR_ESQUERDO]	= 200;
	tela[VERTICE_INFERIOR_DIREITO]	= 188;
}




void Transforma_Numero_em_String(char *numero, int pontuacao)
{
	int auxiliar_1 = 0;
	int auxiliar_2 = 0;
	
	
	/* Zera Número */
	numero[0] = numero[1] = numero[2] = 48;
	
	/* Transforma Centena */
	if(pontuacao > 99)
	{
		auxiliar_1	= pontuacao / 100;
		numero[0]	= auxiliar_1 + 48;
	}
	
	/* Transforma Dezena */
	if(pontuacao > 9)
	{
		auxiliar_2	= pontuacao - (auxiliar_1 * 100);
		numero[1]	= auxiliar_2 + 48;
	}
	
	/* Transforma Unidade */
	numero[2]	= (pontuacao - (auxiliar_1 * 100) - (auxiliar_2 * 10)) + 48;
	
}



void Verifica_Arquivo_Recordes()
{
	FILE * Arquivo;
	
	
	/* Abre Arquivo para Leitura */
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	if (Arquivo == NULL)
	{		
		/* Se o Arquivo não existir, cria um novo */
		Arquivo = fopen (ARQUIVO_RECORDS , "w+");
		
		if(Arquivo != NULL)
		{	
			     //1234567890123456789012345678901234567890
			fputs("               Ranking                \n\0", Arquivo);
			fputs("\0", Arquivo);
			fputs("010 - Cleber\n\0", Arquivo);
			fputs("009 - Presidente\n\0", Arquivo);
			fputs("008 - 100%\n\0", Arquivo);
			fputs("007 - Cleber\n\0", Arquivo);
			fputs("006 - Presidente\n\0", Arquivo);
			fputs("005 - 100%\n\0", Arquivo);
			fputs("004 - Cleber\n\0", Arquivo);
			fputs("003 - Presidente\n\0", Arquivo);
			fputs("002 - 100%\n\0", Arquivo);
			fputs("001 - Cleber\n\0", Arquivo);
			fputs("\n\0", Arquivo);
			fputs("Pressione ESC para Retornar ao Menu.\n\0", Arquivo);
			
			/* Salva Informações do Buffer no Arquivo */
			fflush(Arquivo);
		}
	}
	
	/* Fecha o Arquivo */
	fclose(Arquivo);
}



void Movimenta_Buraco()
{	
	if(buraco.linha == BURACO_LINHA_INICIAL)
	{
		buraco.tamanho = 1;
		buraco.coluna = BURACO_COLUNA_INICIAL;
	}
	else if(buraco.linha == (BURACO_LINHA_INICIAL + 1))
	{
		buraco.tamanho = 1;
		buraco.coluna = BURACO_COLUNA_INICIAL + 1;
	}
	else if(buraco.linha == (BURACO_LINHA_INICIAL + 2))
	{
		buraco.tamanho = 1;
		buraco.coluna = BURACO_COLUNA_INICIAL;
	}
	else if(buraco.linha == (BURACO_LINHA_INICIAL + 3))
	{
		buraco.tamanho = 1;
		buraco.coluna = BURACO_COLUNA_INICIAL - 1;
	}
	else
	{
		// Determina a Posição do Buraco
		switch(buraco.regiao)
		{
			case 0:
				buraco.coluna++;
				// Determina o Tamanho do Buraco e a Coluna
				if(buraco.linha == 6)
				{
					buraco.tamanho = 2;
					buraco.coluna = BURACO_COLUNA_INICIAL + 4;
				}
				else if(buraco.linha == 15)
				{
					buraco.tamanho = 3;
					buraco.coluna = BURACO_COLUNA_INICIAL + 6;
				}
				else if(buraco.linha == 20)
				{
					buraco.tamanho = 4;
					buraco.coluna = BURACO_COLUNA_INICIAL + 8;
				}
				else
				{
					buraco.tamanho = 5;
					buraco.coluna = BURACO_COLUNA_INICIAL + 10;
				}				
			break;
			
			case 1:
				// Determina o Tamanho do Buraco e a Coluna
				if(buraco.linha == 6)
				{
					buraco.tamanho = 2;
					buraco.coluna = BURACO_COLUNA_INICIAL + 1;
				}
				else if(buraco.linha == 15)
				{
					buraco.tamanho = 3;
					buraco.coluna = BURACO_COLUNA_INICIAL;
				}
				else if(buraco.linha == 20)
				{
					buraco.tamanho = 4;
					buraco.coluna = BURACO_COLUNA_INICIAL -1;
				}
				else
				{
					buraco.tamanho = 5;
					buraco.coluna = BURACO_COLUNA_INICIAL -1;
				}
			break;
			
			case 2:
			default:
				buraco.coluna--;
				// Determina o Tamanho do Buraco e a Coluna
				if(buraco.linha == 6)
				{
					buraco.tamanho = 2;
					buraco.coluna = BURACO_COLUNA_INICIAL - 4;
				}
				else if(buraco.linha == 15)
				{
					buraco.tamanho = 3;
					buraco.coluna = BURACO_COLUNA_INICIAL - 6;
				}
				else if(buraco.linha == 20)
				{
					buraco.tamanho = 4;
					buraco.coluna = BURACO_COLUNA_INICIAL - 8;
				}
				else
				{
					buraco.tamanho = 5;
					buraco.coluna = BURACO_COLUNA_INICIAL -10;
				}
				
			break;
		}
	}
	
	/* Verifica se o Buraco está em uma Posição Vertical Válida */
	buraco.linha++;
	if(buraco.linha > TAMANHO_TELA_LINHAS)
	{
		buraco.tamanho = 1;
		buraco.linha = BURACO_LINHA_INICIAL;
		
		buraco.regiao++;
		if(buraco.regiao > 2)
		{
			buraco.regiao = 0;
		}
		
		buraco.pontuacao++;
		Alterar_Placar(buraco.pontuacao);
	}
}



void Inserir_Buraco_na_Tela()
{
	switch(buraco.tamanho)
	{
		case 1:
			tela.tela[tela.proxima_tela][buraco.linha][buraco.coluna] = 219;
		break;
		
		case 2:
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna] 	= 219;
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna] 	= 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 1] = 219;
		break;
		
		case 3:
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 2] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna]		= 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 1] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 2] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 2] = ' ';
		break;		
		
		case 4:
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 2] = 219;
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 3] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna]		= 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 1] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 2] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 3] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna]		= 219;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 1] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 2] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 3] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 2] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 3] = ' ';
		break;		
		
		case 5:
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 1] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 2] = 219;
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 3] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha]		[buraco.coluna + 4] = ' ';
			
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 2] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 3] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 1]	[buraco.coluna + 4] = ' ';
			
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna]		= 219;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 1] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 2] = 176;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 3] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 2]	[buraco.coluna + 4] = 219;
			
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 1] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 2] = 177;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 3] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 3]	[buraco.coluna + 4] = ' ';
			
			tela.tela[tela.proxima_tela][buraco.linha + 4]	[buraco.coluna]		= ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 4]	[buraco.coluna + 1] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 4]	[buraco.coluna + 2] = 219;
			tela.tela[tela.proxima_tela][buraco.linha + 4]	[buraco.coluna + 3] = ' ';
			tela.tela[tela.proxima_tela][buraco.linha + 4]	[buraco.coluna + 4] = ' ';
		break;
		
		default:
			buraco.tamanho = 1;
		break;
	}
}



void Cria_Buraco()
{
	buraco.regiao		= 1;
	buraco.tamanho		= 1;
	buraco.pontuacao	= 0;
	buraco.linha		= BURACO_COLUNA_INICIAL;
	buraco.coluna		= BURACO_COLUNA_INICIAL;	
}



int Pontuacao()
{
	return buraco.pontuacao;
}



/* Template */
/*
void Montar_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
		}
	}
	
}
*/











