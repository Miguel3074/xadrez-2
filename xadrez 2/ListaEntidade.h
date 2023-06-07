#pragma once

#include "Lista.h"
#include "Entidade.h"

namespace Xadrez_2 {
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
		void limparLista();
		int getTam();
		Entidade::Entidade* operator[](int pos);
		void executar(RenderWindow* janela, float gravidade);
	};

}

