/*
 * EmpresaConjunto.h
 *
 *  Created on: 24/03/2018
 *      Author: claudio
 */

#ifndef EMPRESACONJUNTO_H_
#define EMPRESACONJUNTO_H_

#include "Empresa.h"

class EmpresaConjunto {
private:
	Empresa m_empresas[40]; /**<Vetor que guardas todas as empresas do sistema*/
	int totalEmpresas = 0; /**<Inteiro que guarda o total e empresas*/
public:
	/** @brief Construtor e Destrutor para o conjunto de empresas*/
	EmpresaConjunto();
	virtual ~EmpresaConjunto();
	/** @brief Método para adicionar empresas*/
	int adicionarEmpresa(Empresa &empresa);
	/** @brief Método de acesso para as empresas*/
	Empresa& getEmpresas(int i);
};

#endif /* EMPRESACONJUNTO_H_ */
