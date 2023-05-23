#pragma once

#include "stdafx.h"

namespace Jogador {
	class Jogador
	{
	private:
		RectangleShape corpo;
		Vector2f velocidade;
		void inicializa();

	public:

		Jogador(const Vector2f pos, const Vector2f tam);
		Jogador(const RectangleShape corpo);
		Jogador();
		~Jogador();

		void mover();

	};
}

