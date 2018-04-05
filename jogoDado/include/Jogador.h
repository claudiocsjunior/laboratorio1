/*
 * Jogador.h
 *
 *  Created on: 30/03/2018
 *      Author: claudio
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_
#include <iostream>
#include <string>
using namespace std;

class Jogador {
private:
	string m_nome; /**<string que guarda o nome do jogador*/
	int pontuacao = 0; /**<inteiro que guarda a pontuação de cada jogador*/
	int eliminado = 0; /**<inteiro que guarda a situação do jogador no jogo*/
	//1 - eliminado | 0 - continua no jogo
	int statusRodada = 0; /**<inteiro que guarda o status do jogador na rodada*/
	//0 - parou | 1 - jogou
public:
	/** @brief Construtor e Destrutor para o jogador*/
	Jogador();
	virtual ~Jogador();

	/** @brief Métodos de acesso*/
	const string& getNome() const;/**<Método get Nome*/
	int getPontuacao() const; /**<Método get Pontuação*/
	void setPontuacao(int pontuacao); /**<Método set Pontuação*/
	int getEliminado() const; /**<Método get Eliminado*/
	void setEliminado(int eliminado); /**<Método set Eliminado*/
	int getStatusRodada() const; /**<Método get status do jogador na rodada*/

	/** @brief Métodos*/
	friend istream& operator>>(istream &i, Jogador &j); /**<Sobrecarga do operador cin*/
	int jogarDado(); /**<Método jogar o dado - efetuar jogada*/
	void pararNaRodada();/**<Método parar na rodada - não efetuar jogada*/

};

#endif /* JOGADOR_H_ */
