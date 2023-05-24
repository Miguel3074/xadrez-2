#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		Gerenciador::GerenciadorGrafico* pJanela;
		vector<Xadrez_2::Personagem::Personagem*> personagens;
	public:
		Jogo();
		~Jogo();
		void executar();
	};

}