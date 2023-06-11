#include "Espinho.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {
			Espinho::Espinho(const Vector2f pos) :
				Obstaculo(pos, Vector2f(39.0f, 50.0f), IDs::espinho, true), espetou(false)
			{
				if (!this->textura.loadFromFile("../TEXTURAS/espinho.png")) {
					cout << "Erro ao carregar a textura do espinho\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
			}
			Espinho::~Espinho()
			{
			}
			void Espinho::executar()
			{
				vel.y = vel.y + gravidade;
				corpo.move(0.0f, vel.y);
			}
			void Espinho::colisao(Entidade* outraentidade, Vector2f ds)
			{
				if (outraentidade->getId() == IDs::jogador) {
					outraentidade->setEstaVivo(false);
				}
				else if (outraentidade->getId() == IDs::tabuleiro) {
					corpo.move(0.0f, -ds.y);
					vel.y = 0.f;
				}
			}
		}
	}
}