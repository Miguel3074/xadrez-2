#pragma once

#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			class Obstaculo : public Entidade
			{
			private:
				bool danoso;

			public:
				Obstaculo(const Vector2f pos, const Vector2f tam, IDs::IDs id, bool dan);
				~Obstaculo();

			};
		}
	}
}