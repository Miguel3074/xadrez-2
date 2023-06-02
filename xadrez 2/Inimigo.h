#pragma once

#include "Personagem.h"
#include "Jogador.h"

#define VEL_INIMIGO_X 0.5f
#define VEL_INIMIGO_Y 0.5f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem
		{
		private:
			Jogador* jogador;
			Clock relogio;
			//short moveRand;
			void inicializa();

		public:
			Inimigo();
			Inimigo(const Vector2f pos, const Vector2f tam, Jogador* jogador);
			~Inimigo();

			void persegueJogador(Vector2f posJogador, Vector2f posInimigo);
			void movimentoAleatorio();
			void executar();
			void colisao(Entidade* outraentidade, Vector2f ds);
		};
	}
}