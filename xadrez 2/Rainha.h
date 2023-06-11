#pragma once

#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Rainha :public Inimigo
			{
			private:
				bool atirou;
			public:
				Rainha(const Vector2f pos);
				~Rainha();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}