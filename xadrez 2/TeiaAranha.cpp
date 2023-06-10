#include "TeiaAranha.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			TeiaAranha::TeiaAranha(const Vector2f pos) :
				Obstaculo(pos, Vector2f(200.0f, 200.0f), IDs::IDs::teiaAranha, false), grudaNaParede(0)
			{
				if (!this->textura.loadFromFile("../TEXTURAS/teia_aranha.png")) {
					cout << "Erro ao carregar a textura da teia\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
			}
			TeiaAranha::~TeiaAranha()
			{
			}
			void TeiaAranha::atualizar(float gravidade)
			{
				grudaNaParede = gravidade * -1;
				corpo.move(0.0f, gravidade);
				corpo.move(0.0f, grudaNaParede);
			}
			void TeiaAranha::colisao(Entidade* outraentidade, Vector2f ds)
			{
				if (outraentidade->getId() != IDs::IDs::teiaAranha) {
					outraentidade->setVel(Vector2f(outraentidade->getVel().x / 2.f, outraentidade->getVel().y / 2.f));
					cout << "bbb" << endl;
					if (outraentidade->getId() == IDs::IDs::jogador) {
						if (outraentidade->getDirecao()) {
							outraentidade->mover(Vector2f(1.f, 0.f));
						}
						else {
							outraentidade->mover(Vector2f(-1.f, 0.f));
						}
					}
				}
			}
		}
	}
}