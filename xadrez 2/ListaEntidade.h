#pragma once

#include "Lista.h"
#include "Entidade.h"

namespace Listas {
	class ListaEntidade
	{
	private:
		Lista<Entidades::Entidade> objListaEntidade;
	public:
		ListaEntidade();
		~ListaEntidade();
		void addEntidade(Entidades::Entidade* entidade);
		void removeEntidade(Entidades::Entidade* entidade);
		void removeEntidade(int pos);
		int getTam();
		Entidades::Entidade* operator[](int pos);
		void executar(RenderWindow* janela);
	};

}
