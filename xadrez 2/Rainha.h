#pragma once

#include "Inimigo.h"
#include "Jogador.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Rainha :public Inimigo
			{
			private:
				bool persegueJogador1;
				Jogador* jog1;
				Jogador* jog2;
			public:
				Rainha(const Vector2f pos);
				~Rainha();
				void setJogadores(Jogador* jog1, Jogador* jog2);
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
				void persegueJogador();
			};
		}
	}
}