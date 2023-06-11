#pragma once


#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidades {

		class Flecha : public Entidade
		{
		private:
			float aerodinamica;
			bool atingiu;
			bool ladoDisparo;
		public:
			Flecha(const Vector2f pos);
			~Flecha();
			void executar();
			void colisao(Entidade* outraentidade, Vector2f ds);
			void verifPos();
			void setPosTorre(Vector2f posT);
		};

	}
}