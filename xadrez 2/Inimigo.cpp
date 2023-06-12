#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {

			Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, IDs id) ://, Jogador::Jogador* jogador
				Personagem(pos, tam, Vector2f(0.15f, 0.0f), id), eliminado(false)
			{
				podeAndar = true;
			}

			Inimigo::~Inimigo()
			{
			}

			void Inimigo::executar()
			{
				Vector2f posInimigo = corpo.getPosition();
				corpo.move(0.0f, -vel.y);
				vel.y = vel.y - gravidade;
			}

		}
	}
}