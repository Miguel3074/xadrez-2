#pragma once

#include "Personagem.h"
#include "Jogador.h"

#define VEL_INIMIGO_X 0.5f
#define VEL_INIMIGO_Y 0.5f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {

			class Inimigo :public Personagem
			{
			private:
				//Jogador::Jogador* jogador;
				//short moveRand;

			public:
				Inimigo(const Vector2f pos, const Vector2f tam, IDs id);//, Jogador::Jogador* jogador
				virtual ~Inimigo();

				virtual void executar();
			};
		}
	}
}