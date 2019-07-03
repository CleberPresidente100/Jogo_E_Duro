/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



#ifndef __TELA__

	/* Constantes */
	#define __TELA__
	
	/* TELA */
		// Tela sendo Exibida Atualmente, Próxima Tela a ser Exibida, Tela Auxiliar para Comparação
		// As Telas Atual e Próxima são dinâmicas e ocuparão as posições 0 e 1 do Vetor.
		// Já a Tela Auxiliar será sempre Última posição do Vetor.
		#define NUMERO_DE_TELAS 3
		#define TELA_AUXILIAR (NUMERO_DE_TELAS - 1)
		
		#define BRANCO 32
		#define ESPESSURA_BORDA_TELA 1
		#define TAMANHO_TELA_LINHAS 30
		#define TAMANHO_TELA_COLUNAS 80
	
	/* PLACAR */
		#define ESPESSURA_BORDA_PLACAR 1
		#define TAMANHO_PLACAR_LINHAS 7
		#define TAMANHO_PLACAR_COLUNAS 16
		#define POSICAO_PLACAR_LINHA ESPESSURA_BORDA_TELA
		#define POSICAO_PLACAR_COLUNA ESPESSURA_BORDA_TELA
	
	/* CARRO */
		#define POSICAO_CARRO_LINHA (TAMANHO_TELA_LINHAS - ESPESSURA_BORDA_TELA - TAMANHO_CARRO_LINHAS)
		#define POSICAO_CARRO_COLUNA (((TAMANHO_TELA_COLUNAS / 2) - (TAMANHO_CARRO_COLUNAS / 2)) + 1)
	
	/* PISTA */
		#define POSICAO_PISTA_LINHA ESPESSURA_BORDA_TELA
		#define POSICAO_PISTA_COLUNA ESPESSURA_BORDA_TELA
	
	
	/* TABELA DE RANKING */
		#define ARQUIVO_RECORDS "records.txt"
		
		#define RANKING_LINHAS 17
		#define RANKING_COLUNAS 40
		#define RANKING_POSICAO_LINHA 3
		#define RANKING_POSICAO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - (RANKING_COLUNAS / 2) + 2)


	/* TABELA DE NOVO RECORDE */
		#define NOVO_RECORDE_LINHAS 6
		#define NOVO_RECORDE_COLUNAS 29
		#define NOVO_RECORDE_POSICAO_LINHA 11
		#define NOVO_RECORDE_POSICAO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - (NOVO_RECORDE_COLUNAS / 2) + 2)
	
	/* BURACO */
		#define BURACO_LINHA_INICIAL 3
		#define BURACO_COLUNA_INICIAL ((TAMANHO_PISTA_COLUNAS / 2) + 2)
	
	/* Estruturas */
	
	/* Funções */
		/* Gerais */
		void Exibe_Menu_Principal();
		void Exibe_Menu_Recordes();
		void Exibe_Menu_Sobre();
		void Inserir_Recordes();
		void Inserir_Texto_Sobre();
		void Inserir_Nome_do_Jogo();
		void Inserir_Mensagem_Derrota();
		void Realiza_Inicializacao_das_Estruturas();
		void Exibe_Tela_Novo_Recorde(int pontuacao);
		void Criar_Tela_Branco_com_Bordas(char *tela, int NUMERO_DE_LINHAS, int NUMERO_DE_COLUNAS);
		void Transforma_Numero_em_String(char *numero, int pontuacao);
		void Verifica_Arquivo_Recordes();
	
		/* Placar */
		void Cria_Placar();
		void Exibe_Placar();
		void Inserir_Placar_na_Tela();
		void Alterar_Placar(int pontuacao);
		int Pontuacao();
	
		/* Tela */
		void Inicializa_Telas();
		void Limpa_Tela(unsigned char indice_tela);
		void Exibe_Tela();
		int  Atualizar_Tela();
		void Comparar_Tela_Atual_com_Proxima_Tela();
	
		/* Carro */
		void Cria_Carro();
		int  Inserir_Carro_na_Tela();
		void Move_Carro(int movimentar_carro);
		
		/* Pista */
		void Inserir_Pista_na_Tela();
		void Atualiza_Falha_Pista(int linha);
		
		/* Buraco */
		void Cria_Buraco();
		void Movimenta_Buraco();
		void Inserir_Buraco_na_Tela();
	
#endif






