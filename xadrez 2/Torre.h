#pragma once

#include "Inimigo.h"
#include "Flecha.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Torre :public Inimigo
			{
			private:
				Flecha* flecha;
				bool atirou;
			public:
				Torre(const Vector2f pos);
				~Torre();
				Flecha* getFlecha();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}