#pragma once

#include "Ente.h"

namespace Xadrez_2 {
	namespace Entidade {
		class Entidade : public Ente
		{
		protected:
			RectangleShape corpo;
			Vector2f pos;
			Vector2f tam;
			Texture textura;

		public:
			Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs iD);
			~Entidade();
			const RectangleShape getCorpo() const;
			void setPos(Vector2f p);
			Vector2f getPos();
			Vector2f getTam();
			virtual void atualizar();
			virtual void colisao(Entidade* outraentidade, Vector2f ds) = 0;
		};
	}
}
