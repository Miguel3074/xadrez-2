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
					bool pulou;
					void inicializa();

				public:
					Jogador(const Vector2f pos, const Vector2f tam);
					~Jogador();
					void setPulou(bool pulo);
					bool getPulou();
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};
			}
		}
	}
}