/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



/* Inclusão das Bibliotecas */
#include <time.h>/* Biblioteca para Data e Hora */

/* Constantes */
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)



clock_t Inicia_Cronometro()
{
	return (clock ());
}



unsigned int Tempo_Cronometro(clock_t tempo_inicio)
{
	clock_t delta_tempo = clock() - tempo_inicio;
	return((unsigned int)delta_tempo / CLOCKS_PER_MS);
}





