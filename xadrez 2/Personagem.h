#pragma once

#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			Vector2f vel;
		public:
			Personagem();
			Personagem(const Vector2f pos, const Vector2f tam);
			~Personagem();

			virtual void executar() = 0;
		};
	}
}
