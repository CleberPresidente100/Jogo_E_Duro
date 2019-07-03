/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



/* Inclusão das Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* Biblioteca com Funções para Strings */
#include <conio.h>	/* Biblioteca da função getch */
#include <locale.h>	/* Biblioteca para Acentuação */
#include <time.h>	/* Biblioteca para Data e Hora */


#include "tela.h"
#include "carro.h"
#include "pista.h"
#include "gotoxy.h"
#include "milisegundos.h"
#include "caracteres.h"


/* Constantes */
#define ESC 27
#define SAIR '4'

/* Estruturas */
struct str_Novo_Recorde
{
	int colocacao_no_ranking;
	fpos_t posicao_registo;
};


/* Declaração de Funções */
void Inicia_Jogo();
//fpos_t Verifica_Pontuacao(int pontuacao);
void Verifica_Pontuacao(int pontuacao, str_Novo_Recorde *novo_recorde);
int VerificaTeclasDeMovimentacao(char tecla);
int Determina_Velocidade_do_Jogo(unsigned int pontuacao);
void Salva_Novo_Recorde(str_Novo_Recorde *novo_recorde, int pontuacao);




/* Função Main */
int main(void)
{
	int opcao = 0;
	int exibir_menu = 1;
		
	
	/* Permite o uso de Caracteres da Tabela ASCII Extendida */
	setlocale(LC_ALL, "ALL");
	
	/* Cria os Arquivos Necessários */
	Verifica_Arquivo_Recordes();
	
	
	do
	{
		/* Verifica se a Tela deve ser Recarregada */
		if(exibir_menu)
		{			
			Realiza_Inicializacao_das_Estruturas();
			Exibe_Tela(); // Exibe as Bordas da Tela
			Exibe_Menu_Principal();
			exibir_menu = 0;
		}
		
		/* Espera o Usuário Escolher uma Opção */
		fflush(stdin);
		opcao = getch();
		
		switch(opcao)
		{
			case '1':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Inicia_Jogo();
				exibir_menu++;
			break;
			
			case '2':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Exibe_Menu_Recordes();
				while(getch() != ESC); // Espera a Tecla ESC ser Precionada
				exibir_menu++;
			break;
			
			case '3':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Exibe_Menu_Sobre();
				while(getch() != ESC); // Espera a Tecla ESC ser Precionada
				exibir_menu++;
			break;
			
			case SAIR:
			default:
			break;
		}
		
	}while(opcao != SAIR);
	
}




int VerificaTeclasDeMovimentacao(char tecla)
{
	if	(
			(tecla == 'a') ||
			(tecla == 'A') ||
			(tecla == 75) 
		)
	{
		return MOVER_CARRO_PARA_ESQUERDA;
	}
	
	if	(
			(tecla == 'd') ||
			(tecla == 'D') ||
			(tecla == 77) 
		)
	{
		return MOVER_CARRO_PARA_DIREITA;
	}
	
	return 0;
}



void Inicia_Jogo()
{
	/* Carro */
	int sentido = 0;
	int posicao_carro = 0;
	int movimentar_carro = 0;
	
	/* Falha na Borda da Pista que dá a impressão de Movimento */
	int posicao_falha_pista = -1;
	int movimentar_falha_pista = 0;
	
	/* Contagem de Tempo */
	clock_t tempo_inicio;
	unsigned int segundos = 0;
	unsigned int milisegundos = 0;
	unsigned int velocidade_do_jogo = 0;
	
	/* Pontuação */
	int pontuacao = 0;
	float tempo_decorrido = 0; // número de segundo que será substituído pela pontuação de buracos
	str_Novo_Recorde novo_recorde;
	
	/* Determina o Fim de Jogo */
	int fim_de_jogo = 0;
	
	
	
	
	
	/* Configurações Iniciais */
	velocidade_do_jogo = Determina_Velocidade_do_Jogo(segundos);
	tempo_inicio = Inicia_Cronometro();
	
	
	/* Looping do Jogo */
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(milisegundos >= 1)
		{
			/* Movimenta o Carro */
			if(kbhit())
			{
				movimentar_carro = VerificaTeclasDeMovimentacao(getch());
								
				if(movimentar_carro)
				{
					Move_Carro(movimentar_carro);					
					movimentar_carro = 0;
				}
			}
			
			/* Movimenta Falha na Borda da Pista */
			movimentar_falha_pista++;
			if(movimentar_falha_pista >= velocidade_do_jogo)
			{
				movimentar_falha_pista = 0;
				
				posicao_falha_pista++;
				if(posicao_falha_pista > TAMANHO_PISTA_LINHAS)
				{
					posicao_falha_pista = 0;
				}				
				
				/* Movimenta Buraco */
				Movimenta_Buraco();
				
				Atualiza_Falha_Pista(posicao_falha_pista);
				velocidade_do_jogo = Determina_Velocidade_do_Jogo(segundos);
			}
			
			
			// Alterar Pontuação
			tempo_decorrido += milisegundos;
			if(tempo_decorrido >= 1000)
			{
				segundos++;
				tempo_decorrido = 0;
				
				/*
				// Validação da Pontuação
				pontuacao++;
				if((pontuacao < 0) || (pontuacao > 999))
				{
					pontuacao = 0;
				}
				
				Alterar_Placar(pontuacao);
				*/
			}
			
			
			
			
			
			/* Atualiza a Tela */
			fim_de_jogo = Atualizar_Tela();
			
			/* Fim de Jogo */
			if(fim_de_jogo)
			{
				while(getch() != ESC);				
				break;
			}
			
			tempo_inicio = Inicia_Cronometro();
			
		}
	}
	
	pontuacao = Pontuacao();
	Verifica_Pontuacao(pontuacao, &novo_recorde);
	
	if(novo_recorde.posicao_registo)
	{
		Exibe_Tela_Novo_Recorde(pontuacao);
		Exibe_Tela();
		Salva_Novo_Recorde(&novo_recorde, pontuacao);
	}
}



int Determina_Velocidade_do_Jogo(unsigned int segundos)
{
	int velocidade_do_jogo = 0;
	
	if(segundos < 10)
	{
		velocidade_do_jogo = 50;
	}
	else if(segundos < 20)
	{
		velocidade_do_jogo = 40;
	}
	else if(segundos < 30)
	{
		velocidade_do_jogo = 30;
	}
	else if(segundos < 40)
	{
		velocidade_do_jogo = 20;
	}
	else if(segundos < 50)
	{
		velocidade_do_jogo = 10;
	}
	else if(segundos < 60)
	{
		velocidade_do_jogo = 1;
	}
	
	return velocidade_do_jogo;
}



void Verifica_Pontuacao(int pontuacao, str_Novo_Recorde *novo_recorde)
{
	int linha = 0;
	int coluna = 0;
	int pontuacao_ranking = 0;
	
	FILE * Arquivo;	
	fpos_t posicao_registo = 0;
	char linha_arquivo [100];
	
	// Inicializa Variável
	novo_recorde->colocacao_no_ranking = 0;
	
	/* Abre Arquivo para Leitura */
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	if (Arquivo != NULL)
	{
		while(!feof (Arquivo))
		{
			/* Salva a posição do Registo Atual */
			fgetpos(Arquivo, &novo_recorde->posicao_registo);
			
			/* Lê a próxima linha do arquivo */
			fgets(linha_arquivo, (RANKING_COLUNAS - 2), Arquivo);
			
			/* Determina se a Linha Lida é um Registro de Recorde */
			if	(
					(linha_arquivo[0] >= '0') && (linha_arquivo[0] <= '9') &&
					(linha_arquivo[1] >= '0') && (linha_arquivo[1] <= '9') &&
					(linha_arquivo[2] >= '0') && (linha_arquivo[2] <= '9')
				)
			{
				
				/* Incrementa Variável que indica Posição no Ranking*/
				novo_recorde->colocacao_no_ranking++;
				
				
				
				/* Transforma os Caracteres que Representam a Pontuação em um Número */
				pontuacao_ranking  = (linha_arquivo[0] - 48) * 100;
				pontuacao_ranking += (linha_arquivo[1] - 48) * 10;
				pontuacao_ranking += (linha_arquivo[2] - 48);
				
				/*	Se a Pontuaçao for Maior ou Igual que a de um
					dos Registros, retorna a Linha a ser Substituída */
				if(pontuacao >= pontuacao_ranking)
				{
					/* Fecha Arquivo */
					fclose (Arquivo);
					return;
				}
			}
		}
	}
	
	/* Fecha Arquivo */
	fclose (Arquivo);
	novo_recorde->posicao_registo = 0;
	return;
	
}



void Salva_Novo_Recorde(str_Novo_Recorde *novo_recorde, int pontuacao)
{
	int indice = 0;
	
	FILE * Arquivo;
	char auxiliar[100];
	char linhas_arquivo [10][100];
	
	char nome_do_recordista[20];
	char pontuacao_string[3];
	
	
	
	/* Posiciona Cursor e Espera o Usuário Digitar o Nome */
	gotoxy((NOVO_RECORDE_POSICAO_LINHA + 4), (NOVO_RECORDE_POSICAO_COLUNA + 5));
	fflush(stdin);
	scanf("%s", &nome_do_recordista);
		
	
	/* Transforma a Pontuação em Caracteres */
	Transforma_Numero_em_String(pontuacao_string, pontuacao);
		
	
	/* Abre Arquivo para Leitura */
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	if (Arquivo != NULL)
	{
		// Inicializa Variável 
		indice = 0;
		
		/* Lê Arquivo */
		while(!feof(Arquivo))
		{
			/* Lê a próxima linha do arquivo */
			fgets(auxiliar, (RANKING_COLUNAS - 2), Arquivo);
			
			/* Determina se a Linha Lida é um Registro de Recorde */
			if	(
					(auxiliar[0] >= '0') && (auxiliar[0] <= '9') &&
					(auxiliar[1] >= '0') && (auxiliar[1] <= '9') &&
					(auxiliar[2] >= '0') && (auxiliar[2] <= '9')
				)
			{
				strcpy(linhas_arquivo[indice], auxiliar);
				indice++;
			}
		}
		
		/* Salva Informações do Buffer no Arquivo */
		//fflush(Arquivo);
				
		/* Fecha Arquivo */
		fclose(Arquivo);
		
		
		
		
		// Cria novo Registro para ser Inserido na Tabela de Recordes
		strcpy(auxiliar, pontuacao_string);
		strcat(auxiliar, " - ");
		strcat(auxiliar, nome_do_recordista);
		strcat(auxiliar, "\n\0");
		
		
		// Atualiza Tabela de Recordes
		for(indice = 9; indice >= 0; indice--)
		{
			if(indice == novo_recorde->colocacao_no_ranking)
			{
				strcpy(linhas_arquivo[indice], auxiliar);
				// Ao Encontrar a posição correta, não há mais o que se alterar. Então sai do for.
				break;
			}
			else
			{
				// Faz o registro cair 1 posição na tabela para poder inserir o novo recorde
				strcpy(linhas_arquivo[indice], linhas_arquivo[indice - 1]);
			}
		}
		
		Arquivo = fopen (ARQUIVO_RECORDS , "w");
		if(Arquivo != NULL)
		{
			// Salva Cabeçalho no Arquivo
			fputs("               Ranking                \n\0", Arquivo);
			fputs("\0", Arquivo);
						
			// Salva Registros de Recorde Atualizados no Arquivo
			for(indice = 0; indice < 10; indice++)
			{
				fputs(linhas_arquivo[indice], Arquivo);	
			}
			
			// Salva Rodapé no Arquivo
			fputs("\n\0", Arquivo);
			fputs("Pressione ESC para Retornar ao Menu.\n\0", Arquivo);
		}
		
		/* Salva Informações do Buffer no Arquivo */
		fflush(Arquivo);
		
		/* Fecha Arquivo */
		fclose(Arquivo);
	}
	
	
}













