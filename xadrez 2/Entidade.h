#pragma once

#include "stdafx.h"
#include "IDs.hpp"

namespace Xadrez_2 {
	namespace Entidade {

		class Entidade
		{
		protected:
			RectangleShape corpo;
			Vector2f pos;
			Vector2f tam;
			Texture textura;

			const IDs::IDs ID;
		public:
			Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs iD);
			~Entidade();
			const RectangleShape getCorpo() const;
			void setPos(Vector2f p);
			Vector2f getPos();
			Vector2f getTam();
			IDs::IDs getId();
			virtual void atualizar() = 0;
			virtual void colisao(Entidade* outraentidade, Vector2f ds) = 0;
		};
	}
}
