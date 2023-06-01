#pragma once


#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			class Personagem : public Entidade
			{
			protected:
				Vector2f vel;
				bool podeAndar;
				bool dirEsquerda;
				Clock relogio;
				float dt;
			public:
				Personagem(const Vector2f pos, const Vector2f tam, const float vel, IDs::IDs iD);
				~Personagem();
				void andar(const bool dirEsquerda);
				void parar();
				void setVel(Vector2f v);
				Vector2f getVel();

				void atualizarPosicao();
			};
		}
	}
}