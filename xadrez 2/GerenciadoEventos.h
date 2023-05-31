#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Xadrez_2 {

	namespace Gerenciador {

		class GerenciadorEvento
		{
		private:
			GerenciadorGrafico* pGerenciadorGrafico;
			Entidade::Personagem::Jogador::Jogador* pjogador;

			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:

			~GerenciadorEvento();
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador(Entidade::Personagem::Jogador::Jogador* pJogador);
			void verificaTeclaPressionada(Keyboard::Key tecla);
			void verificaTeclaSolta(Keyboard::Key tecla);
			void executar();
		};
	}
}