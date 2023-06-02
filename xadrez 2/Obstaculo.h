#pragma once

#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			class Obstaculo : public Entidade
			{
			private:

				bool aereo;

			public:
				Obstaculo(const Vector2f pos, IDs::IDs id);
				~Obstaculo();

				void atualizar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}