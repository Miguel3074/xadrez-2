#pragma once
#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			class TeiaAranha : public Obstaculo
			{
			private:
				float grudaNaParede;
			public:
				TeiaAranha(const Vector2f pos);
				~TeiaAranha();
				void atualizar(float gravidade);
				void colisao(Entidade* outraentidade, Vector2f ds);

			};

		}
	}
}