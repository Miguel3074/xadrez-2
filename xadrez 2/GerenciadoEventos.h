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
			Entidade::Personagem::Jogador::Jogador* pjogador1;
			Entidade::Personagem::Jogador::Jogador* pjogador2;
			Jogo* instanciaJogo;

			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:

			~GerenciadorEvento();
			void setInstanciaJogo(Jogo* jogo) { instanciaJogo = jogo; }
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador1(Entidade::Personagem::Jogador::Jogador* pJogador1);
			void setJogador2(Entidade::Personagem::Jogador::Jogador* pJogador2);
			Entidade::Personagem::Jogador::Jogador* getJogador1();
			Entidade::Personagem::Jogador::Jogador* getJogador2();
			void verificaTeclaPressionada(Keyboard::Key tecla);
			void verificaTeclaSolta(Keyboard::Key tecla);
			void executar();
		};
	}
}