/*
 * Empresa.cpp
 *
 *  Created on: 23/03/2018
 *      Author: claudio
 */

#include "../include/Empresa.h"
#include "../include/Funcionario.h"
#include <string>
#include <iostream>
using namespace std;

/**
* @brief Construtor para a empresa
*/
Empresa::Empresa() {
	// TODO Auto-generated constructor stub

}

/**
* @brief Método get para cnpj
* @return cnpj
*/
const string& Empresa::getCnpj() const {
	return m_cnpj;
}

/**
* @brief Método set para cnpj
* @param recebe uma string cnpj para alteração do valor atual
*/
void Empresa::setCnpj(const string& cnpj) {
	m_cnpj = cnpj;
}

/**
* @brief Método get para nome
* @return nome
*/
const string& Empresa::getNome() const {
	return m_nome;
}

/**
* @brief Método set para nome
* @param recebe uma string nome para alteração do valor atual
*/
void Empresa::setNome(const string& nome) {
	m_nome = nome;
}

/**
* @brief Método get total de empresas
* @return total de empresas
*/
double Empresa::getTotalEmpresas(){
	return m_totalEmpresas;
}

/**
* @brief Sobrecarga do operador cin
* @param i string que carrega os valores dos atributos dos objetos
* @param e objeto empresa
* @return i
*/
istream& operator>>(istream &i, Empresa &e){
	cout << "DIGITE O NOME DA EMPRESA: " << endl;
	i >> e.m_nome;
	cout << "DIGITE O CNPJ DA EMPRESA: " << endl;
	i >> e.m_cnpj;
	return i;
}


/**
* @brief Método para cadastrar um novo funcionário na empresa
*/
void Empresa::cadastrarFuncionario(){
	Funcionario funcionario;
	cin >> funcionario;
	/** @brief (0) - não existe funcioário com os dados mesmos dados, (1) - existe funcionários com os mesmos dados*/
	int funcionarioExistente = 0;
	/** @brief Verifica de há algum funcionário com os mesmos dados existentes no vetor funcionários da empresa*/
	for(int i = 0; i < totalFuncionario; i++){
		if(m_funcionarios[i] == funcionario){
			cout << "FUNCIONÁRIO JÁ EXISTENTE!" << endl;
			cout << endl;
			funcionarioExistente = 1;
		}
	}
	/** @brief Caso não haja funcionário com os mesmos dados - criar novo funcionário*/
	if(funcionarioExistente == 0){
		/** @brief Verifica se o total de funcionário por empresa excedeu o limite disponibilizado pelo sistema*/
		if(totalFuncionario < 40){
			m_funcionarios[totalFuncionario++] = funcionario;
			cout << "FUNCIONARIO DE NOME " << m_funcionarios[totalFuncionario-1].getNome()
					<< " COM SALARIO " << m_funcionarios[totalFuncionario-1].getSalario()
					<< " ADMITIDO DESDE O DIA " << m_funcionarios[totalFuncionario-1].getData() << " CADASTRADO COM SUCESSO!" << endl;
			Funcionario::m_totalFunc++;
			cout << endl;
		}else{
			cout << "ERRO AO ADICIONAR UM NOVO FUNCIONÁRIO, EXCEDEU O LIMITE!" << endl;
			cout << endl;
		}
		cout << "TOTAL FUNCIONARIOS: "<< totalFuncionario << endl;

	}
}

/**
* @brief Sobrecarga do operador cout
* @param o string que guarda os valores concatenando-os para impressão
* @param e objeto empresa
* @return o
*/
ostream& operator<<(ostream &o, Empresa const e){
	o << "NOME: "<<e.m_nome << " CNPJ: " << e.m_cnpj << endl;
	return o;
}

/**
* @brief Método get para total de funcionários
* @return total de funcionários
*/
int Empresa::getTotalFuncionario() const {
	return totalFuncionario;
}

/**
* @brief Método para listar o total de funcionários
*/
void Empresa::listarFuncionarios(){
	Funcionario funcionario;
	cout << "<<FUNCIONÁRIOS>>" << endl;
	cout << "TOTAL: " << totalFuncionario <<endl;
	/** @brief Percorre o vetor imprimindo os funcionários correspondentes*/
	for(int i=0; i < 40; i++){
		funcionario = m_funcionarios[i];
		if(funcionario.getNome() != "\0"){
			cout << "ID: "<< i << "  --- ";
			cout << funcionario;
		}else if(funcionario.getNome() == "\0" && i == 0){
			cout << "AINDA NÃO TEMOS NENHUM FUNCIONARIO CADASTRADO PARA ESTA EMPRESA" << endl;
			cout << endl;
		}
	}
}

/**
* @brief Método para aumentar o salário dos funcionários em X%
* @param porcentagem que será atribuida aos salários
*/
void Empresa::aumentarPorcentagemEmSalario(int porcentagem){
	/** @brief Verifica se há funcionários cadastrados na empresa*/
	if(totalFuncionario > 0){
		/** @brief Percorre o vetor de funcionários aumentando o salário de cada um*/
		for(int i = 0; i < totalFuncionario; i++){
			double aumento = 0;
			double salarioModificado = 0;
			aumento = (m_funcionarios[i].getSalario() * porcentagem)/100;
			salarioModificado = m_funcionarios[i].getSalario() + aumento;
			m_funcionarios[i].setSalario(salarioModificado);
		}

		cout << "AUMENTO DE SALÁRIO DE TODOS OS FUNCIONÁRIOS EM " << porcentagem <<"%!" << endl;
		cout << endl;
	}
	else{
		cout << "AINDA NÃO TEMOS NENHUM FUNCIONARIO CADASTRADO PARA ESTA EMPRESA" << endl;
		cout << endl;
	}
}

/**
* @brief Método para listar os funcionários em periodo de experiência
*/
void Empresa::listarFuncionariosExp(){
	/** @brief Verifica se há funcionários cadastrados na empresa*/
	if(totalFuncionario > 0){
		string dataAtual;
		cout << "DIGITE A DATA ATUAL NO FORMATO DD/MM/AAAA" << endl;
		cout << endl;
		cin >> dataAtual;
		/** @brief Varre todo o vetor e busca de funcionários de funcionários em periodo de experiência de acordo com a data informada*/
		for(int i = 0; i < totalFuncionario; i++){
			/** @brief Chama o metodo para verificar a data*/
			int retorno = m_funcionarios[i].verificarData(dataAtual);
			if(retorno < 0){
				cout << "ERRO: A DATA ATUAL INFORMADA ESTÁ ANTERIOR A DATA DE ADMISSÃO DO FUNCIONÁRIO "<< m_funcionarios[i].getNome() << endl;
				cout << endl;
			}
			else
			{
				if(retorno <= 90){
					cout << " EM PERIODO DE EXPERIÊNCIA: " << m_funcionarios[i].getNome() << endl;
					cout << endl;
				}
			}

		}

	}else{
		cout << "AINDA NÃO TEMOS NENHUM FUNCIONARIO CADASTRADO PARA ESTA EMPRESA" << endl;
		cout << endl;
	}

}

/**
* @brief Destrutor
*/
Empresa::~Empresa() {
	// TODO Auto-generated destructor stub
}

