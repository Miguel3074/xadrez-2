#include "ListaEntidade.h"

namespace Xadrez_2 {



	ListaEntidade::ListaEntidade() :
		objListaEntidade()
	{
	}

	ListaEntidade::~ListaEntidade()
	{
	}

	void ListaEntidade::addEntidade(Entidade::Entidade* entidade)
	{
		objListaEntidade.addElemento(entidade);
	}

	void ListaEntidade::removeEntidade(Entidade::Entidade* entidade)
	{
		objListaEntidade.removerElemento(entidade);
	}

	void ListaEntidade::removeEntidade(int pos)
	{
		objListaEntidade.removerElemento(pos);
	}

	int ListaEntidade::getTam()
	{
		return objListaEntidade.getTam();
	}

	Entidade::Entidade* ListaEntidade::operator[](int pos)
	{
		return objListaEntidade.operator[](pos);
	}

	void ListaEntidade::executar(RenderWindow* janela)
	{
		int tam = objListaEntidade.getTam();
		Entidade::Entidade* aux = nullptr;
		for (int i = 0; i < tam; i++) {
			aux = objListaEntidade.operator[](i);
			aux->atualizar();
			janela->draw(aux->getCorpo());
		}
	}

}