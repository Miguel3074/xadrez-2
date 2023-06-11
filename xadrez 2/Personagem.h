#pragma once


#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			class Personagem : public Entidade
			{
			protected:
				bool podeAndar;
				Clock relogio;
				float dt;
			public:
				Personagem(const Vector2f pos, const Vector2f tam, Vector2f vel, IDs iD);
				~Personagem();
				void andar(const bool dirEsquerda);
				void parar();

				virtual void executar() = 0;
			};
		}
	}
}