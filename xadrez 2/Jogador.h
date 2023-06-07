#pragma once

#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				class Jogador :public Personagem
				{
				private:
					bool estaNoAr;
					void inicializa();

				public:
					Jogador(const Vector2f pos);
					~Jogador();
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};
			}
		}
	}
}