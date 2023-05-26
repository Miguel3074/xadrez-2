#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				void Inimigo::inicializa()
				{
					vel = Vector2f(0.05f, 0.05f);
				}

				Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Jogador::Jogador* jogador) :
					Personagem(pos, tam, vel.x), relogio(), jogador(jogador)
				{
					corpo.setFillColor(Color::Red);
					inicializa();
					srand(time(NULL));
					moveRand = rand() % 4;
				}

				Inimigo::~Inimigo()
				{
				}

				void Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
				{
					if (posJogador.x - posInimigo.x > 0.0f) {
						corpo.move(vel.x, 0.0f);
					}
					else {
						corpo.move(-vel.x, 0.0f);
					}
					if (posJogador.y - posInimigo.y > 0.0f) {
						corpo.move(0.0f, vel.y);
					}
					else {
						corpo.move(0.0f, -vel.y);
					}
				}

				void Inimigo::movimentoAleatorio()
				{
				}

				void Inimigo::atualizar()
				{
					Vector2f posJogador = jogador->getCorpo().getPosition();
					Vector2f posInimigo = corpo.getPosition();

					if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
						persegueJogador(posJogador, posInimigo);
					}
				}
			}
		}
	}
}