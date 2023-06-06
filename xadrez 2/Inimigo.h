#pragma once

#include "Personagem.h"
#include "Jogador.h"

#define VEL_INIMIGO_X 0.5f
#define VEL_INIMIGO_Y 0.5f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {

				class Inimigo :public Personagem
				{
				private:
					Jogador::Jogador* jogador;
					Clock relogio;
					//short moveRand;
					void inicializa();

				public:
					Inimigo(const Vector2f pos, Jogador::Jogador* jogador);
					~Inimigo();
					void persegueJogador(Vector2f posJogador, Vector2f posInimigo);
					void atualizar(float gravidade);
					void colisao(Entidade* outraentidade, Vector2f ds);
				};
			}
		}
	}
}