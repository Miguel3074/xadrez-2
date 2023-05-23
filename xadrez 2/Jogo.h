#pragma once

#include "Jogador.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		RenderWindow janela;
		Jogador::Jogador jogador;
	public:
		Jogo();
		~Jogo();
		void executar();
	};

}