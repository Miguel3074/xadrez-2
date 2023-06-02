#pragma once

#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				class Jogador :public Personagem
				{
				private:
					void inicializa();

				public:
					Jogador(const Vector2f pos, const Vector2f tam);
					~Jogador();
					void atualizar();
					void colisao(Entidade* outraentidade, Vector2f ds);
				};
			}
		}
	}
}