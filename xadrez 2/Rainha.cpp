#include "Rainha.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {
				Rainha::Rainha(const Vector2f pos) :
					Inimigo(pos, Vector2f(75.0f, 173.0f), IDs::IDs::rainha), atirou(false)
				{
					vel = Vector2f(0.f, 0.f);
					if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/rainhaP 75_173.png")) {
						cout << "Erro ao carregar a textura do peao\n";
					}
					textura.setSmooth(true);
					corpo.setTexture(&textura);
					podeAndar = false;
				}
				Rainha::~Rainha()
				{
				}
				void Rainha::atualizar(float gravidade)
				{
					Vector2f posInimigo = corpo.getPosition();
					corpo.move(0.0f, -vel.y);
					vel.y = vel.y - gravidade;
				}
				void Rainha::colisao(Entidade* outraentidade, Vector2f ds)
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
							estaVivo = false;
						}

					}
					break;
					}
				}
			}
		}
	}
}
