#pragma once

#include "stdafx.h"

namespace Xadrez_2 {

	namespace Personagem {
		class Personagem
		{
		protected:
			RectangleShape corpo;
			Vector2f vel;
			bool podeAndar;
			bool dirEsquerda;
			Clock relogio;
			float dt;
		public:
			Personagem(const Vector2f pos, const Vector2f tam, const float vel);
			~Personagem();
			const RectangleShape getCorpo();
			void andar(const bool dirEsquerda);
			void parar();
			virtual void atualizar() = 0;

			void atualizarPosicao();
		};
	}
}
