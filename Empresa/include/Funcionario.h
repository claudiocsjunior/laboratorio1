/*
 * Funcionario.h
 *
 *  Created on: 23/03/2018
 *      Author: claudio
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Funcionario {

private:
	string m_nome; /**< string que guardo o nome dos funcionários*/
	double m_salario; /**< double que guarda o salário dos funcionários*/
	string m_data; /**< string que guarda a data de admissão do funcionário*/

public:
	/** @brief Construtor e Destrutor para os funcionários*/
	Funcionario();
	virtual ~Funcionario();

	/** @brief Métodos de acesso*/
	const string& getData() const; /**< Método get para a data*/
	void setData(const string& data); /**< Método set para a data*/
	const string& getNome() const; /**< Método get para o nome*/
	void setNome(const string& nome); /**< Método set para o nome*/
	double getSalario() const; /**< Método get para o salário*/
	void setSalario(double salario); /**< Método set para o salário*/

	/** @brief Variável estática para o total de funcionário e o métodod e acesso (get)*/
	static double m_totalFunc;
	static double getTotalFunc();

	/** @brief Métodos*/
	friend istream& operator>>(istream &a, Funcionario &f); /**< Sobrecarga do operador cin para funcionários*/
	friend ostream& operator<<(ostream &e, Funcionario const f); /**< Sobrecarga do operador cout para funcionários*/
	bool operator==(Funcionario const &funcionarioComparacao); /**< Sobrecarga do operador de comparação para funcionários*/
	int verificarData(string dataComparacao); /**< Método para comparar datas e retorna o periodo de em dias entre elas*/

};

#endif /* FUNCIONARIO_H_ */
