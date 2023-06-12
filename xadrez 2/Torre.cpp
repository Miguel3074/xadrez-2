#include "Torre.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			Torre::Torre(const Vector2f pos) :
				Inimigo(pos, Vector2f(80.0f, 130.0f), IDs::torre), flecha(nullptr), atirou(false)
			{
				flecha = new Flecha(pos);
				vel = Vector2f(0.f, 0.f);
				if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/torreP 80_130.png")) {
					cout << "Erro ao carregar a textura do peao\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
				podeAndar = false;
			}
			Torre::~Torre()
			{

			}
			Flecha* Torre::getFlecha()
			{
				return flecha;
			}
			void Torre::executar()
			{
				Vector2f posInimigo = corpo.getPosition();
				corpo.move(0.0f, -vel.y);
				vel.y = vel.y - gravidade;
				flecha->setPosTorre(posInimigo);
				flecha->executar();
			}
			void Torre::colisao(Entidade* outraentidade, Vector2f ds)
			{
				switch (outraentidade->getId())
				{
				case(IDs::tabuleiro):
				{

				}
				break;
				case(IDs::jogador):
				{
					if (ds.x > ds.y) {
						if (outraentidade->getDirecao())
							outraentidade->mover(Vector2f(-ds.x, 0.f));
						else
							outraentidade->mover(Vector2f(ds.x, 0.f));
					}
					else {
						estaVivo = false;
						flecha->setEstaVivo(false);
					}

				}
				break;
				}
			}
		}
	}
}
