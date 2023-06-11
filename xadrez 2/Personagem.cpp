
#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {


			Personagem::Personagem(const Vector2f pos, const Vector2f tam, Vector2f vel, IDs iD) :
				dt(0), podeAndar(false), Entidade(pos, tam, iD, vel)
			{
				corpo.setPosition(pos);
			}

			Personagem::~Personagem()
			{
			}

			void Personagem::andar(const bool dirEsquerda)
			{

				podeAndar = true;
				this->dirEsquerda = dirEsquerda;

			}

			void Personagem::parar()
			{
				podeAndar = false;
			}

			void Personagem::atualizarPosicao()
			{
				dt = relogio.getElapsedTime().asSeconds();
				float ds = 1000 * dt; //MRU
				if (dirEsquerda) {
					ds *= -1;
				}
				corpo.move(ds, 0.0f);
				if (corpo.getPosition().x < (1920.f - tam.x) && corpo.getPosition().x > 0.f) {
					corpo.move(ds, 0.0f);
				}
				else if (corpo.getPosition().x <= 0.f) {
					corpo.setPosition(Vector2f(0.1f, corpo.getPosition().y));
				}
				else if (corpo.getPosition().x >= (1920.f - tam.x)) {
					corpo.setPosition(Vector2f(1919.f - tam.x, corpo.getPosition().y));
				}
			}
		}
	}
}