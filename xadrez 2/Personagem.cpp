
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
		}
	}
}