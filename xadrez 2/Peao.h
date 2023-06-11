#pragma once

#include "Inimigo.h"


namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Peao : public Inimigo
			{
			private:
				bool chegouNoFinal;
			public:
				Peao(const Vector2f pos);
				~Peao();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}