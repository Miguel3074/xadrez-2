#include "Rainha.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {
			Rainha::Rainha(const Vector2f pos) :
				Inimigo(pos, Vector2f(75.0f, 173.0f), IDs::rainha), persegueJogador1(true), jog1(nullptr), jog2(nullptr)
			{
				vel = Vector2f(0.f, 0.f);
				if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/rainhaP 75_173.png")) {
					cout << "Erro ao carregar a textura do peao\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
				podeAndar = true;
				vel.x = 0.20f;
			}
			Rainha::~Rainha()
			{
			}

			void Rainha::setJogadores(Jogador* joga1, Jogador* joga2)
			{
				jog1 = joga1;
				if (joga2) {
					jog2 = joga2;
					if (rand() % 2 == 0) {
						persegueJogador1 = false;
					}
				}
			}

			void Rainha::executar()
			{
				persegueJogador();
				Inimigo::executar();
				/*Vector2f posInimigo = corpo.getPosition();
				corpo.move(0.0f, -vel.y);
				vel.y = vel.y - gravidade;*/
			}
			void Rainha::colisao(Entidade* outraentidade, Vector2f ds)
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
					}

				}
				break;
				}
			}
			void Rainha::persegueJogador()
			{
				if (corpo.getPosition().x > 0.f) {
					if (corpo.getPosition().x < 1920.f - tam.x) {
						if (persegueJogador1)
						{
							if (jog1) {
								Vector2f posJog1 = jog1->getPos();
								if (posJog1.x - corpo.getPosition().x > 0.f)
									corpo.move(vel.x, 0.f);
								else
									corpo.move(-vel.x, 0.f);
							}
							else
								persegueJogador1 = false;
						}
						else {
							if (jog2) {
								Vector2f posJog2 = jog2->getPos();
								if (posJog2.x - corpo.getPosition().x > 0.f)
									corpo.move(vel.x, 0.f);
								else
									corpo.move(-vel.x, 0.f);
							}
							else
								persegueJogador1 = true;
						}
					}
					else {
						corpo.setPosition(1920.f - tam.x, corpo.getPosition().y);
					}
				}
				else
				{
					corpo.setPosition(0.f, corpo.getPosition().y);
				}
			}
		}
	}
}
