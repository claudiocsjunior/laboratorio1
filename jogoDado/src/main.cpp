#include <iostream>
#include <string>
#include "../include/Jogador.h"
#include "../include/Jogo.h"
using namespace std;

int main(){
	Jogo jogo;
	jogo.definicoesIniciais();
	jogo.criarJogadores();
	do{
	jogo.executarRodadas();
	}while(jogo.verificarCampeao() == 0);

	jogo.printarCampeao();

	return 0;
}
