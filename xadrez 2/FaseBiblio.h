#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	namespace Fases {
		class FaseBiblio : public Fase
		{
		private:
			ifstream mapa1txt;
		public:
			FaseBiblio();
			~FaseBiblio();
			void criarMapa();
			void executar();
		};

	}
}

