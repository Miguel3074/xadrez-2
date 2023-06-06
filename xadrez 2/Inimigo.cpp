#include "Inimigo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				void Inimigo::inicializa()
				{
					vel = Vector2f(0.05f, 0.05f);
					if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/peaoP 73_107.png")) {
						cout << "Erro ao carregar a textura do peao\n";
					}
					textura.setSmooth(true);
					corpo.setTexture(&textura);
				}

				Inimigo::Inimigo(const Vector2f pos, Jogador::Jogador* jogador) :
					Personagem(pos, Vector2f(78.0f, 130.0f), Vector2f(0.15f, 0.0f), IDs::IDs::inimigo), relogio(), jogador(jogador)
				{
					podeAndar = true;
					inicializa();
					srand(time(NULL));
					//moveRand = rand() % 4;
				}

				Inimigo::~Inimigo()
				{
				}

				void Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
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
				}

				void Inimigo::atualizar(float gravidade)
				{
					Vector2f posJogador = jogador->getCorpo().getPosition();
					Vector2f posInimigo = corpo.getPosition();

					if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
						persegueJogador(posJogador, posInimigo);
					}
					else {
						podeAndar = true;
					}
					corpo.move(0.0f, -vel.y);
					vel.y = vel.y - gravidade;
				}
				void Inimigo::colisao(Entidade* outraentidade, Vector2f ds)
				{
					switch (outraentidade->getId())
					{
					case(IDs::IDs::tabuleiro):
					{

					}
					break;
					case(IDs::IDs::jogador):
					{
						if(dirEsquerda)
							corpo.move(-ds.x, 0);
						else
							corpo.move(ds.x, 0);
						parar();
					}
					break;
					}
				}
			}
		}
	}
}