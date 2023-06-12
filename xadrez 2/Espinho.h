#pragma once
#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			class Espinho : public Obstaculo
			{
			private:
				bool espetou;
			public:
				Espinho(const Vector2f pos);
				~Espinho();
				void executar();
				void colisao(Entidade* outraentidade, Vector2f ds);
				void verifEspetou();

			};
		}
	}
}