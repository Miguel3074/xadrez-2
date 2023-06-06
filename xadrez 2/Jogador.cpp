#include "Jogador.h"
namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				void Jogador::inicializa()
				{
					if (!this->textura.loadFromFile("../TEXTURAS/BRANCAS/cavaloB 78_130.png")) {
						cout << "Erro ao carregar a textura do cavalo\n";
					}
					textura.setSmooth(true);
					corpo.setTexture(&textura);
				}

				Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
					Personagem(pos, tam, Vector2f(0.1f, 0.0f), IDs::IDs::jogador),
					estaNoAr(false), pulou(true)
				{
					corpo.setPosition(pos);
					inicializa();
				}

				Jogador::~Jogador()
				{
				}

				void Jogador::setPulou(bool pulo)
				{
					pulou = true;
				}

				bool Jogador::getPulou()
				{
					return false;
				}

				void Jogador::atualizar(float gravidade)
				{

					if (podeAndar) {
						atualizarPosicao();
					}

					corpo.move(0.0f, -vel.y);
					vel.y = vel.y - gravidade;
					relogio.restart();

				}
				void Jogador::colisao(Entidade* outraentidade, Vector2f ds)
				{
					switch (outraentidade->getId())
					{
					case(IDs::IDs::tabuleiro):
					{
					}
					break;
					case(IDs::IDs::inimigo):
					{
						corpo.move(-ds.x, 0);
					}
					break;
					}
				}
			}
		}
	}
}