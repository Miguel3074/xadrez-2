#pragma once

#include "Lista.h"
#include "Entidade.h"

namespace Xadrez_2 {
	class ListaEntidade
	{
	private:
		Lista<Entidades::Entidade> objListaEntidade;
	public:
		ListaEntidade();
		~ListaEntidade();
		void addEntidade(Entidades::Entidade* entidade, float gravidade);
		void removeEntidade(Entidades::Entidade* entidade);
		void removeEntidade(int pos);
		void limparLista();
		int getTam();
		Entidades::Entidade* operator[](int pos);

		bool jogadoresVivos();
		bool inimigosVivos();

		void executar(RenderWindow* janela);
	};

}

