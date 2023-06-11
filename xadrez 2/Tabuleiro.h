#pragma once
#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			class Tabuleiro : public Obstaculo
			{
			private:
				float empuxo;

			public:
				Tabuleiro(const Vector2f pos);
				~Tabuleiro();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
			};
		}
	}
}