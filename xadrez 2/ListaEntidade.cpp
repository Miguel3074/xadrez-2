#include "ListaEntidade.h"


Listas::ListaEntidade::ListaEntidade() :
	objListaEntidade()
{
}

Listas::ListaEntidade::~ListaEntidade()
{
}

void Listas::ListaEntidade::addEntidade(Entidades::Entidade* entidade)
{
	objListaEntidade.addElemento(entidade);
}

void Listas::ListaEntidade::removeEntidade(Entidades::Entidade* entidade)
{
	objListaEntidade.removerElemento(entidade);
}

void Listas::ListaEntidade::removeEntidade(int pos)
{
	objListaEntidade.removerElemento(pos);
}

int Listas::ListaEntidade::getTam()
{
	return objListaEntidade.getTam();
}

Entidades::Entidade* Listas::ListaEntidade::operator[](int pos)
{
	return objListaEntidade.operator[](pos);
}

void Listas::ListaEntidade::executar(RenderWindow* janela)
{
	int tam = objListaEntidade.getTam();
	Entidades::Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++) {
		aux = objListaEntidade[i];
		aux->executar();
		janela->draw(aux->getCorpo());
	}
}