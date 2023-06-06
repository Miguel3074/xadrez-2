#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	namespace Fase {
		class FaseBiblio : public Fase
		{
		private:
			ifstream mapa1txt;
		public:
			FaseBiblio();
			~FaseBiblio();
			void criarMapa();

		};

	}
}

