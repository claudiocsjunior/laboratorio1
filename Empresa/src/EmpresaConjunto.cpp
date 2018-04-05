/*
 * EmpresaConjunto.cpp
 *
 *  Created on: 24/03/2018
 *      Author: claudio
 */
#include <iostream>
#include "../include/EmpresaConjunto.h"
#include "../include/Empresa.h"
using namespace std;

/**
* @brief Construtor para o conjunto de empresas
*/
EmpresaConjunto::EmpresaConjunto() {
	// TODO Auto-generated constructor stub

}

/**
* @brief Método get para empresas
* @param i valor da posição da empresa a ser selecionada
* @return empresa
*/
Empresa& EmpresaConjunto::getEmpresas(int i){
	return m_empresas[i];
}

/**
* @brief Método para adicionar empresas
* @param empresa onjeto a ser adicionado
* @return posicão da empresa para ser 'logada' posteriormente
*/
int EmpresaConjunto::adicionarEmpresa(Empresa &empresa){
	cin >> empresa;
	int retornoEmpresa = 0;
	if(totalEmpresas < 40){
		m_empresas[totalEmpresas++] = empresa;
		cout << "EMPRESA DE NOME " << m_empresas[totalEmpresas-1].getNome() << " E CNPJ " << m_empresas[totalEmpresas-1].getCnpj() << " CADASTRADA COM SUCESSO!" << endl;
		cout << endl;
		retornoEmpresa = totalEmpresas-1;
	}else{
		cout << "ERRO AO ADICIONAR UMA NOVA EMPRESA, EXCEDEU O LIMITE!" << endl;
		cout << endl;
	}

	Empresa::m_totalEmpresas = totalEmpresas;
	return retornoEmpresa;

}

/**
* @brief Destrutor
*/
EmpresaConjunto::~EmpresaConjunto() {
	// TODO Auto-generated destructor stub
}

