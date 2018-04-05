/*
 * Funcionario.cpp
 *
 *  Created on: 23/03/2018
 *      Author: claudio
 */

#include "../include/Funcionario.h"
#include "../include/Empresa.h"
#include <string>
#include <iostream>
/**
* @Construtor
*/
Funcionario::Funcionario() {
	// TODO Auto-generated constructor stub

}

/**
* @brief Método get para data
* @return data
*/
const string& Funcionario::getData() const {
	return m_data;
}

/**
* @brief Método set para data
* @param data valor que alterará a data atual
*/
void Funcionario::setData(const string& data) {
	m_data = data;
}

/**
* @brief Método get para nome
* @return nome
*/
const string& Funcionario::getNome() const {
	return m_nome;
}

/**
* @brief Método set para nome
* @param data
*/
void Funcionario::setNome(const string& nome) {
	m_nome = nome;
}


/**
* @brief Método get para salário
* @return salário
*/
double Funcionario::getSalario() const {
	return m_salario;
}

/**
* @brief Método set para salário
* @param salário
*/
void Funcionario::setSalario(double salario) {
	m_salario = salario;
}


/**
* @brief Sobrecarga do operador cin
* @param a string que carrega os valores dos atributos dos objetos
* @param f objeto funcionário
* @return a
*/
istream& operator>>(istream &a, Funcionario &f){
	cin.ignore();
	cout << "DIGITE O NOME DO FUNCIONÁRIO: " << endl;
	getline(a, f.m_nome);
	cout << "DIGITE O SALARIO DO FUNCIONÁRIO: " << endl;
	a >> f.m_salario;
	cout << "DIGITE A DATA DE ADIMISSÃO NO FORMATO DD/MM/AAAA: " << endl;
	a >> f.m_data;

	return a;
}

/**
* @brief Sobrecarga do operador cout
* @param e string que guarda os valores concatenando-os para impressão
* @param f objeto funcionário
* @return e
*/
ostream& operator<<(ostream &e, Funcionario const f){
	e << "NOME: "<< f.m_nome << "| SALÁRIO: " << f.m_salario << " REAIS | DATA DE ADMISSÃO: " <<  f.m_data << endl;
	return e;
}

/**
* @brief Sobrecarga do operador de comparação
* @param funcionarioComparação objeto funcionário para comparar com o objeto que o chamou
* @return booleano
*/
bool Funcionario::operator==(Funcionario const &funcionarioComparacao){
	if(m_nome == funcionarioComparacao.m_nome && m_data == funcionarioComparacao.m_data){
		return true;
	}
	return false;
}

/**
* @brief Método get para o total de funcionários
* @return total de funcionários
*/
double Funcionario::getTotalFunc() {
	return m_totalFunc;
}

/**
* @brief Faz a verificação das datas de admissão e a data atual retornando a quantidade de dias trabalhados
* @param dataAtual string que carrega a data atual para comparação
* @return quantidade de dias
*/
int Funcionario::verificarData(string dataAtual){
	/** @brief Calcular dias*/
	string diaAdmissao;
	diaAdmissao += m_data[0];
	diaAdmissao += m_data[1];
	int intDiaAdmissao = atoi(diaAdmissao.c_str());
	string diaAtual;
	diaAtual += dataAtual[0];
	diaAtual += dataAtual[1];
	int intdiaAtual = atoi(diaAtual.c_str());
	int valorComparacaoDias = intdiaAtual- intDiaAdmissao;

	/** @brief Calcular meses para dias*/
	int vetMeses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string mesAdmissao;
	mesAdmissao += m_data[3];
	mesAdmissao += m_data[4];
	int intMesAdmissao = atoi(mesAdmissao.c_str());

	string mesAtual;
	mesAtual += dataAtual[3];
	mesAtual += dataAtual[4];
	int intMesAtual = atoi(mesAtual.c_str());

	int valorComparacaoMes = 0;
	if(intMesAtual < intMesAdmissao){
		for(int i=intMesAtual+1; i<=intMesAdmissao; i++){
			valorComparacaoMes -= vetMeses[i];
		}
	}else if(intMesAtual > intMesAdmissao){
		for(int i=intMesAdmissao+1; i<=intMesAtual; i++){
			valorComparacaoMes += vetMeses[i];
		}
	}else{
		valorComparacaoMes = 0;
	}

	/** @brief Calcular anos para dias*/
	string anoAdmissao;
	anoAdmissao += m_data[7];
	anoAdmissao += m_data[8];
	anoAdmissao += m_data[9];
	anoAdmissao += m_data[10];
	int intAnoAdmissao = atoi(anoAdmissao.c_str());


	string anoAtual;
	anoAtual += dataAtual[7];
	anoAtual += dataAtual[8];
	anoAtual += dataAtual[9];
	anoAtual += dataAtual[10];
	int intAnoAtual= atoi(anoAtual.c_str());

	int valorComparacaoAno = 0;
	if(intAnoAdmissao < intAnoAtual){
		valorComparacaoAno = (intAnoAtual * 365) - (intAnoAdmissao * 365);
	}else{
		valorComparacaoAno = (intAnoAdmissao * 365) - (intAnoAtual * 365);
	}

	int diasRetorno = valorComparacaoAno + valorComparacaoMes + valorComparacaoDias;
	return diasRetorno;
}

/**
* @brief Destrutor
*/
Funcionario::~Funcionario() {
	// TODO Auto-generated destructor stub
}


