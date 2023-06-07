#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {

				Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, IDs::IDs id) ://, Jogador::Jogador* jogador
					Personagem(pos, tam, Vector2f(0.15f, 0.0f), id)//, jogador(jogador)
				{
					podeAndar = true;
				}

				Inimigo::~Inimigo()
				{
				}

				/*void Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
				{
					if (podeAndar) {
						if (posJogador.x - posInimigo.x > 0.0f) {
							corpo.move(vel.x, 0.0f);
							dirEsquerda = false;
						}
						else {
							corpo.move(-vel.x, 0.0f);
							dirEsquerda = true;
						}
					}
				}*/
			}
		}
	}
}