/*
 * Jogo.h
 *
 *  Created on: 30/03/2018
 *      Author: claudio
 */

#ifndef JOGO_H_
#define JOGO_H_
#include "Jogador.h"
#include <iostream>
#include <string>
using namespace std;

#define QUANTIDADE_MAX_JOGADORES 10

class Jogo {
private:
	int m_quantidadeJogadoresAtivosPartida; /**<Inteiro que verificar a quantidade de jogadores ativos na partida*/
	int m_quantidadeJogadores = 0; /**<Inteiro com a quantidade de jogadores que serão escolhidos*/
	Jogador m_jogadores[QUANTIDADE_MAX_JOGADORES]; /**<Vetor com os jogaores que irão participar do jogo*/
	int m_rodada = 0;/**<Inteiro com a rodada atual do jogo*/
	Jogador * m_vencedor = NULL; /**<Ponteiro que guarda o jogador caso este consiga a vitória*/

public:
	/** @brief Construtor e Destrutor para a empresa*/
	Jogo();
	virtual ~Jogo();

	/** @brief Métodos de acesso*/
	const Jogador* getJogadores() const; /**<Método get para os jogadores*/
	int getQuantidadeJogadores() const; /**<Método get para a quantidade de jogadores*/
	void setQuantidadeJogadores(int quantidadeJogadores); /**<Método set para a quantidade de jogadores*/
	int getQuantidadeJogadoresAtivosPartida() const; /**<Método get para a quantidade de jogadores ativos na partida*/
	void setQuantidadeJogadoresAtivosPartida(
			int quantidadeJogadoresAtivosPartida); /**<Método set para a quantidade de jogadores ativos na partida*/
	int getRodada() const; /**<Método get para a rodada da partida*/
	void setRodada(int rodada); /**<Método set para a rodada da partida*/
	Jogador* getVencedor() const; /**<Método get o vencedor da partida*/
	void setVencedor(Jogador* vencedor); /**<Método set para o vencedor da partida*/

	/** @brief atributa estático para a pontuação base para o jogo e seu método de acesso*/
	static int m_pontuacaoTeto;
	static int getPontuacaoTeto();


	/** @brief Métodos*/
	void definicoesIniciais(); /**<Definições iniciais para o inicio do jogo*/
	void criarJogadores(); /**<Método para a criação de jogadores*/
	void executarRodadas(); /**<Método para a execução de cada rodada*/

	int verificarPontuacaoJogador(Jogador &jogador); /**<Método para verificar a pontuação do jogador - o status da partida*/
	void acharGanhador(); /**<Método para achar o campeão caso os jogadores parem*/
	void resumoRodada(); /**<Método para mostrar o resumo da rodada*/
	int verificarCampeao(); /**<Método para verificar se há um campeão no fim da rodada*/
	void printarCampeao(); /**<Método para mostrar o campeão*/

};

#endif /* JOGO_H_ */
