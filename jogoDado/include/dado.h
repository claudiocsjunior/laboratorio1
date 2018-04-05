#ifndef _DADO_H_
#define _DADO_H_

#include "Jogador.h"
#include "Jogo.h"
#include <random>

using namespace std;
class dado {
	private:
		int valor;
		random_device rd;
		default_random_engine gen;
		uniform_int_distribution<> dis;
	public:
		dado ();
		int jogar();
		int getValor();
};

#endif
