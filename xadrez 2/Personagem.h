#pragma once

#include "stdafx.h"

namespace Xadrez_2{

	namespace Personagem {
		class Personagem
		{
		protected:
			RectangleShape corpo;
			Vector2f vel;
		public:
			Personagem(const Vector2f pos, const Vector2f tam);
			~Personagem();
			const RectangleShape getCorpo();

			virtual void mover() = 0;
		};
	}
}
