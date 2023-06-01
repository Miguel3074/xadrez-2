#include "Obstaculo.h"

namespace Xadrez_2 {
	namespace Entidade {
		namespace Obstaculo {

			Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, IDs::IDs id) :
				Entidade(pos, tam, id), aereo(false)
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