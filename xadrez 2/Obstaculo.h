#pragma once

#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			class Obstaculo : public Entidade
			{
			private:
				bool danoso;

			public:
				Obstaculo(const Vector2f pos, const Vector2f tam, IDs id, bool dan);
				virtual ~Obstaculo();

				virtual void executar() = 0;
			};
		}
	}
}