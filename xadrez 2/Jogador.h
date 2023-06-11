#pragma once

#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {

			class Jogador :public Personagem
			{
			private:
				bool estaNoAr;
				void inicializa();

			public:
				Jogador(const Vector2f pos);
				~Jogador();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}