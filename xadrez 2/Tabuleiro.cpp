#include "Tabuleiro.h"
namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {
			Tabuleiro::Tabuleiro(const Vector2f pos, IDs::IDs id) :
				Obstaculo(pos, Vector2f(450.0f, 150.0f), id, false), empuxo(0)
			{
				if (!this->textura.loadFromFile("../TEXTURAS/tabuleiro.png")) {
					cout << "Erro ao carregar a textura do cavalo\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
			}
			Tabuleiro::~Tabuleiro()
			{
			}
			void Tabuleiro::atualizar(float gravidade)
			{
				empuxo = gravidade * -1;
				corpo.move(0.0f, gravidade);
				corpo.move(0.0f, empuxo);
			}
			void Tabuleiro::colisao(Entidade* outraentidade, Vector2f ds)
			{
				if (outraentidade->getId() != IDs::IDs::tabuleiro) {
					if (outraentidade->getCorpo().getPosition().y < corpo.getPosition().y)
						outraentidade->mover(Vector2f(0.0f, ds.y));
					else
						outraentidade->mover(Vector2f(0.0f, -ds.y));
					outraentidade->colisao(this, ds);
					if (outraentidade->getId() == IDs::IDs::jogador || outraentidade->getId() == IDs::IDs::inimigo) {
						outraentidade->setVel(Vector2f(outraentidade->getVel().x, 0.0f));
					}
				}
			}
		}
	}
}