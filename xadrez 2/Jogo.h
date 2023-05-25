#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		static Gerenciador::GerenciadorEvento* pEvento;
		static Gerenciador::GerenciadorGrafico* pJanela;
		vector<Personagem::Personagem*> personagens;
	public:
		Jogo();
		~Jogo();
		void executar();
	};

}