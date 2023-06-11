#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	namespace Fases {
		class FaseParque : public Fase
		{
		private:
			ifstream mapa2txt;
		public:
			FaseParque();
			~FaseParque();
			void criarMapa();
			void executar();
		};

	}
}
