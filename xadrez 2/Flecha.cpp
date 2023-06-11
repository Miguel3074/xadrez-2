#include "Flecha.h"


namespace Xadrez_2 {
	namespace Entidades {
		Flecha::Flecha(const Vector2f pos) :
			Entidade(pos, Vector2f(50.f, 20.f), IDs::flecha, Vector2f(0.1f, 0.f)), atingiu(false), aerodinamica(-0.00699f), ladoDisparo(false)
		{
			if (!this->textura.loadFromFile("../TEXTURAS/flecha.png")) {
				cout << "Erro ao carregar a textura da flecha\n";
			}
			textura.setSmooth(true);
			corpo.setTexture(&textura);
		}
		Flecha::~Flecha()
		{
		}
		void Flecha::executar()
		{
			verifPos();
			if (vel.x == 0.f && vel.y == 0.f) {
				corpo.setPosition(pos);
				vel.x = 0.15f;
				if (rand() % 2 == 1) {
					vel.x = vel.x * -1.f;
					corpo.setScale(Vector2f(1, 1));
				}
				else
					corpo.setScale(Vector2f(-1, 1));
			}
			corpo.move(vel.x, -vel.y);
			vel.y = vel.y - gravidade - aerodinamica;
		}
		void Flecha::colisao(Entidade* outraentidade, Vector2f ds)
		{
			switch (outraentidade->getId())
			{
			case(IDs::tabuleiro):
			{
				vel.x = 0.f;
				vel.y = 0.f;
			}
			break;
			case(IDs::jogador):
			{
				outraentidade->setEstaVivo(false);
				vel.x = 0.f;
				vel.y = 0.f;
			}
			break;
			}
		}
		void Flecha::verifPos()
		{
			if (corpo.getPosition().x < 0.f || corpo.getPosition().x > 1920.f) {
				vel.x = 0.f;
				vel.y = 0.f;
			}
		}
		void Flecha::setPosTorre(Vector2f posT)
		{
			pos = posT;
		}
	}
}