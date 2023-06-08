#pragma once

#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				class Rainha :public Inimigo
				{
				private:
					bool atirou;
				public:
					Rainha(const Vector2f pos);
					~Rainha();
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};

			}
		}
	}
}