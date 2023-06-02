#pragma once

#include "Entidade.h"

namespace Entidades {
	class Obstaculo : public Entidade
	{
	private:

		bool aereo;

	public:
		Obstaculo(const Vector2f pos, const Vector2f tam, IDs id);
		~Obstaculo();

		void executar();
		void colisao(Entidade* outraentidade, Vector2f ds);
	};
}