#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	namespace Fase {
		class FaseParque : public Fase
		{
		private:
			ifstream mapa2txt;
		public:
			FaseParque();
			~FaseParque();
			void criarMapa();
		};

	}
}
