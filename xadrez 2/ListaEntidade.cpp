#include "ListaEntidade.h"

namespace Xadrez_2 {



	ListaEntidade::ListaEntidade() :
		objListaEntidade()
	{
	}

	ListaEntidade::~ListaEntidade()
	{
	}

	void ListaEntidade::addEntidade(Entidades::Entidade* entidade, float gravidade)
	{
		objListaEntidade.addElemento(entidade);
		entidade->setGravidade(gravidade);
	}

	void ListaEntidade::removeEntidade(Entidades::Entidade* entidade)
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

	void ListaEntidade::limparLista()
	{
		objListaEntidade.limparLista();
	}

	Entidades::Entidade* ListaEntidade::operator[](int pos)
	{
		return objListaEntidade.operator[](pos);
	}

	bool ListaEntidade::jogadoresVivos() {
		for (int i = 0; i < objListaEntidade.getTam(); i++) {
			if (objListaEntidade[i]->getId() == IDs::jogador)
				return true;
		}
		return false;
	}

	bool ListaEntidade::inimigosVivos() {
		for (int i = 0; i < objListaEntidade.getTam(); i++) {
			if (objListaEntidade[i]->getId() == IDs::peao ||
				objListaEntidade[i]->getId() == IDs::rainha || 
				objListaEntidade[i]->getId() == IDs::torre)
				return true;
		}
		return false;
	}

	void ListaEntidade::executar(RenderWindow* janela)
	{
		Entidades::Entidade* aux = nullptr;
		for (int i = 0; i < objListaEntidade.getTam(); i++) {
			aux = objListaEntidade.operator[](i);
			aux->executar();
			if (!aux->getEstaVivo()) {
				objListaEntidade.removerElemento(aux);
			}
			else
				janela->draw(aux->getCorpo());
		}
	}

}