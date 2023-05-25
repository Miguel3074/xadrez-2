#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Xadrez_2 {
	namespace Gerenciador {

		class GerenciadorEvento
		{
		private:
			GerenciadorGrafico* pJanela;
			Personagem::Jogador::Jogador* pjogador;

			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:

			~GerenciadorEvento();
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador(Personagem::Jogador::Jogador* pJogador);
			void verificaTeclaPressionada(Keyboard::Key tecla);
			void verificaTeclaSolta(Keyboard::Key tecla);
			void executar();
		};
	}
}