
#include "Personagem.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {


			Personagem::Personagem(const Vector2f pos, const Vector2f tam, Vector2f vel, IDs::IDs iD) :
				dirEsquerda(false), dt(NULL), podeAndar(false), Entidade(pos, tam, iD, vel)
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
			}
		}
	}
}