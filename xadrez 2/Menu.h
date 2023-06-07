#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	namespace Fase {
		class Menu : public Fase
		{
		private:

			//placeholders
			Font fonte;
			Text fase1, fase2, pontos, sair, selecao;
			//deve ter um nome pra um padrão de projeto que assiste o estado desse objeto, mas eu esqueci
			int menuOpcao;

		public:
			Menu();
			~Menu();

			int getMenuOpcao();
			void criarMapa();

			void executar() override;
		};
	}
}