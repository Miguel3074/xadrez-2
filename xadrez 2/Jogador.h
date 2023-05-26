#pragma once

#include "stdafx.h"
#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				class Jogador :public Personagem
				{
				private:
					void inicializa();

				public:
					Jogador(const Vector2f pos, const Vector2f tam, const float vel);
					~Jogador();
					void atualizar();
				};
			}
		}
	}
}