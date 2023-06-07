#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Xadrez_2 {
	class Jogo;
	namespace Gerenciador {

		class GerenciadorEvento
		{
		private:
			GerenciadorGrafico* pGerenciadorGrafico;
			Entidade::Personagem::Jogador::Jogador* pjogador;
			Jogo* instanciaJogo;

			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:

			~GerenciadorEvento();
			void setInstanciaJogo(Jogo* jogo) { instanciaJogo = jogo; }
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador(Entidade::Personagem::Jogador::Jogador* pJogador);
			Entidade::Personagem::Jogador::Jogador* getJogador();
			void verificaTeclaPressionada(Keyboard::Key tecla);
			void verificaTeclaSolta(Keyboard::Key tecla);
			void executar();
		};
	}
}