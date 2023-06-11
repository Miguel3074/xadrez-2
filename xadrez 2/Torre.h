#pragma once

#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Torre :public Inimigo
			{
			private:
				bool atirou;
			public:
				Torre(const Vector2f pos);
				~Torre();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}