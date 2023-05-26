#pragma once

#include "stdafx.h"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {

			class Jogador : public Personagem
			{
			private:
				//int pontos;
				void inicializa();

			public:
				Jogador();
				Jogador(const Vector2f pos, const Vector2f tam);
				~Jogador();

				void executar();
			};
	}
}