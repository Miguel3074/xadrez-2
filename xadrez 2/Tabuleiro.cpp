#include "Tabuleiro.h"
namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			Tabuleiro::Tabuleiro(const Vector2f pos) :
				Obstaculo(pos, Vector2f(450.0f, 150.0f), IDs::tabuleiro, false), empuxo(0)
			{
				if (!this->textura.loadFromFile("../TEXTURAS/tabuleiro.png")) {
					cout << "Erro ao carregar a textura do tabuleiro\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
			}
			Tabuleiro::~Tabuleiro()
			{
			}
			void Tabuleiro::executar()
			{
				empuxo = gravidade * -1;
				corpo.move(0.0f, gravidade);
				corpo.move(0.0f, empuxo);
			}
			void Tabuleiro::colisao(Entidade* outraentidade, Vector2f ds)
			{
				if (outraentidade->getId() != IDs::tabuleiro && outraentidade->getId() != IDs::teiaAranha) {
					if (ds.y > ds.x) {
						if (outraentidade->getCorpo().getPosition().y < corpo.getPosition().y)
							outraentidade->mover(Vector2f(0.0f, ds.y));
						else
							outraentidade->mover(Vector2f(0.0f, -ds.y));
						outraentidade->setVel(Vector2f(outraentidade->getVel().x, 0.0f));
					}
					else {
						if (outraentidade->getDirecao())
							outraentidade->mover(Vector2f(-ds.x, 0.f));
						else
							outraentidade->mover(Vector2f(ds.x, 0.f));
					}
				}
			}
		}
	}
}