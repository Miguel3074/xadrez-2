#include "Peao.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			Peao::Peao(const Vector2f pos) :
				Inimigo(pos, Vector2f(73.0f, 107.0f), IDs::peao), chegouNoFinal(false)
			{
				vel = Vector2f(0.05f, 0.05f);
				if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/peaoP 73_107.png")) {
					cout << "Erro ao carregar a textura do peao\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
				pontuacao = 5;
			}

			Peao::~Peao()
			{
			}

			void Peao::executar()
			{
				Inimigo::executar();
				podeAndar = true;
				if (corpo.getPosition().x < (1920.f - tam.x) && corpo.getPosition().x > 0.f) {
					corpo.move(-0.05f, 0.0f);
				}
				else {
					chegouNoFinal = true;
				}

			}

			void Peao::colisao(Entidade* outraentidade, Vector2f ds)
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
							outraentidade->setEstaVivo(false);
					}
					else {
						estaVivo = false;
						outraentidade->acrescentarPontuacao(pontuacao);
					}

				}
				break;
				}
			}
			bool Peao::getChegouNoFinal()
			{
				return chegouNoFinal;
			}
		}
	}
}