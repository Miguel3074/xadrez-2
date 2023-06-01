
#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {


			Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel, IDs::IDs iD) :
				dirEsquerda(false), dt(NULL), podeAndar(false), vel(vel, 0.0f), Entidade(pos, tam, iD)
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

			void Personagem::setVel(Vector2f v)
			{
				vel = v;
			}

			Vector2f Personagem::getVel()
			{
				return vel;
			}

			void Personagem::atualizarPosicao()
			{
				dt = relogio.getElapsedTime().asSeconds();
				float ds = 1000 * dt; //MRU
				if (dirEsquerda) {
					ds *= -1;
				}
				corpo.move(ds, 0.0f);
			}
		}
	}
}