#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Xadrez_2 {
	class Jogo;
	namespace Gerenciadores {

		class GerenciadorEvento
		{
		private:
			GerenciadorGrafico* pGerenciadorGrafico;
			Entidades::Personagens::Jogador* pjogador1;
			Entidades::Personagens::Jogador* pjogador2;
			Jogo* instanciaJogo;

			static GerenciadorEvento* pEvento;
			GerenciadorEvento();
		public:

			~GerenciadorEvento();
			void setInstanciaJogo(Jogo* jogo) { instanciaJogo = jogo; }
			static GerenciadorEvento* getGerenciadorEvento();
			void setJogador1(Entidades::Personagens::Jogador* pJogador1);
			void setJogador2(Entidades::Personagens::Jogador* pJogador2);
			Entidades::Personagens::Jogador* getJogador1();
			Entidades::Personagens::Jogador* getJogador2();
			void verificaTeclaPressionada(Keyboard::Key tecla);
			void verificaTeclaSolta(Keyboard::Key tecla);
			void executar();
		};
	}
}