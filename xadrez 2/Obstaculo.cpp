#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidades {
		namespace Obstaculos {

			Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, IDs id, bool dan) :
				Entidade(pos, tam, id, Vector2f(0.0f, 0.0f)), danoso(dan)
			{
				corpo.setPosition(pos);
			}

			Obstaculo::~Obstaculo()
			{
			}
		}
	}
}