#pragma once

#include "Entidade.h"
#include "Lista.h"

namespace Xadrez_2 {
	namespace Lista {
		class ListaEntidade
		{
		private:
			Lista<Entidade::Entidade> objListaEntidade;
		public:
			ListaEntidade();
			~ListaEntidade();
			void addEntidade(Entidade::Entidade* entidade);
			void removeEntidade(Entidade::Entidade* entidade);
			void removeEntidade(int pos);
			int getTam();
			Entidade::Entidade* operator[](int pos);
			void executar(RenderWindow* janela);
		};
	}
}

