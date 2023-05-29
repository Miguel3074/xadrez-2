#pragma once

#include "Ente.h"

namespace Entidades {
	class Entidade : public Ente {
	protected:
		RectangleShape corpo;
		Vector2f pos;
		Vector2f tam;

	public:
		Entidade();
		~Entidade();

		const RectangleShape getCorpo() const;

		virtual void executar() = 0;

	};
}