#include "Peao.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {

			namespace Inimigo {
				Peao::Peao(const Vector2f pos) :
					Inimigo(pos, Vector2f(73.0f, 107.0f), IDs::IDs::peao), chegouNoFinal(false)
				{
					vel = Vector2f(0.05f, 0.05f);
					if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/peaoP 73_107.png")) {
						cout << "Erro ao carregar a textura do peao\n";
					}
					textura.setSmooth(true);
					corpo.setTexture(&textura);
				}

				Peao::~Peao()
				{
				}

				void Peao::atualizar(float gravidade)
				{
					Vector2f posInimigo = corpo.getPosition();
					podeAndar = true;
					if (corpo.getPosition().x < (1920.f - tam.x) && corpo.getPosition().x > 0.f) {
						corpo.move(-0.07f, 0.0f);
					}
					corpo.move(0.0f, -vel.y);
					vel.y = vel.y - gravidade;

				}

				void Peao::colisao(Entidade* outraentidade, Vector2f ds)
				{
					switch (outraentidade->getId())
					{
					case(IDs::IDs::tabuleiro):
					{

					}
					break;
					case(IDs::IDs::jogador):
					{
						if (ds.x > ds.y) {
							if (outraentidade->getDirecao())
								outraentidade->mover(Vector2f(-ds.x, 0.f));
							else
								outraentidade->mover(Vector2f(ds.x, 0.f));
						}
						else {
							outraentidade->mover(Vector2f(0.f, ds.y));
							outraentidade->setVel(Vector2f(outraentidade->getVel().x, 0.f));
						}

					}
					break;
					}
				}

			}
		}
	}
}