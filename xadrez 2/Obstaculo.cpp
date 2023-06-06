#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {

			Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, IDs::IDs id, bool dan) :
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