#pragma once

#include "stdafx.h"

namespace Xadrez_2 {
	namespace Entidade {

		class Entidade
		{
		protected:
			RectangleShape corpo;
			Vector2f pos;
			Vector2f tam;
		public:
			Entidade(const Vector2f pos, const Vector2f tam);
			~Entidade();
			const RectangleShape getCorpo() const;
			virtual void atualizar() = 0;
		};
	}
}
