#pragma once
#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			class Tabuleiro : public Obstaculo
			{
			private:
				float empuxo;

			public:
				Tabuleiro(const Vector2f pos, IDs::IDs id);
				~Tabuleiro();
				void atualizar(float gravidade);
				void colisao(Entidade* outraentidade, Vector2f ds);
			};

		}
	}
}