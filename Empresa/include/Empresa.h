/*
 * Empresa.h
 *
 *  Created on: 23/03/2018
 *      Author: claudio
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include "Funcionario.h"
#include <string>
#include <iostream>
using namespace std;

class Empresa {
private:
	string m_nome; /**<string que guarda o nome da empresa*/
	Funcionario m_funcionarios[40]; /**<Vetor que guarda os funcionários*/
	string m_cnpj; /**<string que guarda o cnpj da empresa*/
	int totalFuncionario = 0; /**<inteiro que guarda o total de funcionários*/

public:
	/** @brief Construtor e Destrutor para a empresa*/
	Empresa();
	virtual ~Empresa();

	/** @brief Métodos de acesso (getters e setters)*/
	const string& getCnpj() const; /**<Método get para CNPJ*/
	void setCnpj(const string& cnpj); /**<Método set para CNPJ*/
	const string& getNome() const; /**<Método get para Nome*/
	void setNome(const string& nome); /**<Método set para Nome*/

	/** @brief Variável estática e método de acesso*/
	static double m_totalEmpresas; /**<Declaração de variável estática para guarda o total de empresas*/
	static double getTotalEmpresas(); /**<Método get para o total de empresas*/

	/** @brief Outros métodos*/
	friend istream& operator>>(istream &i, Empresa &e); /**<Sobrecarga do operador cin para empresas*/
	void cadastrarFuncionario(); /**<Método de cadastro de um novo funcionário*/
	friend ostream& operator<<(ostream &o, Empresa const e); /**<Sobrecargo do operador cout para empresas*/
	void listarFuncionarios(); /**< Método para listar funcionários */
	int getTotalFuncionario() const; /**< Método que retorna o total de funcionários*/
	void aumentarPorcentagemEmSalario(int porcentagem);/**< Método para aumentar a porcentagem do salário dos funcioários em X%*/
	void listarFuncionariosExp();/**< Método para listar funcionários no periodo de experiência*/
};

#endif /* EMPRESA_H_ */
