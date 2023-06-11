#pragma once
#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			class TeiaAranha : public Obstaculo
			{
			private:
				float grudaNaParede;
			public:
				TeiaAranha(const Vector2f pos);
				~TeiaAranha();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);

			};
		}
	}
}