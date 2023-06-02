#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {

			Obstaculo::Obstaculo(const Vector2f pos, IDs::IDs id) :
				Entidade(pos, Vector2f(500.0f, 100.0f), id), aereo(false)
			{
				corpo.setFillColor(Color::Green);
				corpo.setPosition(pos);
			}

			Obstaculo::~Obstaculo()
			{
			}

			void Obstaculo::atualizar()
			{
			}

			void Obstaculo::colisao(Entidade* outraentidade, Vector2f ds)
			{
			}
		}
	}
}