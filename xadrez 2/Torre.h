#pragma once

#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				class Torre :public Inimigo
				{
				private:
					bool atirou;
				public:
					Torre(const Vector2f pos);
					~Torre();
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};

			}
		}
	}
}