#pragma once

#include "Ente.h"
#include "IDs.h"

namespace Entidades {
	class Entidade : public Ente {
	protected:
		RectangleShape corpo;
		Vector2f pos;
		Vector2f tam;
		Texture textura;

		const IDs ID;

	public:
		Entidade();
		Entidade(const Vector2f pos, const Vector2f tam, const IDs iD);
		~Entidade();

		const RectangleShape getCorpo() const;
		Vector2f getPos();
		Vector2f getTam();
		IDs getId();

		virtual void executar() = 0;
		virtual void colisao(Entidade* outraentidade, Vector2f ds) = 0;

	};
}