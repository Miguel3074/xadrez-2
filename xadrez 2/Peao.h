#pragma once

#include "Inimigo.h"


namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				class Peao : public Inimigo
				{
				private:
					bool chegouNoFinal;
				public:
					Peao(const Vector2f pos);
					~Peao();
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};
			}
		}
	}
}