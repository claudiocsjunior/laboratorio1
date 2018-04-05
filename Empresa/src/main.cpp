#include <iostream>
#include "../include/Funcionario.h"
#include "../include/Empresa.h"
#include "../include/EmpresaConjunto.h"
#include "../include/Funcionalidades.h"
using namespace std;

double  Funcionario::m_totalFunc = 0;
double  Empresa::m_totalEmpresas = 0;
int main()
{
	cout << "SEJA BEM VINDO" << endl;
	Funcionalidades iniciarFuncionalidades;
	/** @brief Chama o método de execução das funcionalidades do sistema*/
	iniciarFuncionalidades.executarFuncionalidades();
	return 0;
}
