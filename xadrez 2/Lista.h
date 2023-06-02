#pragma once

#include "stdafx.h"

namespace Listas {
	template<class L>
	class Lista
	{
	private:
		template<class E>
		class Elemento
		{
		private:
			Elemento* prox;
			E* elemento;
		public:
			Elemento();
			~Elemento();
			void setProx(Elemento<E>* prox);
			void setElem(E* elemento);
			Elemento<E>* getProx();
			E* getElemento();
		};
		Elemento<L>* pInicio;
		Elemento<L>* pFinal;
		unsigned int tam;
	public:
		Lista();
		~Lista();
		void addElemento(L* elemento);
		void removerElemento(L* elemento);
		void removerElemento(int pos);
		int getTam();
		void limparLista();
		L* operator[](int pos);
	};
}

template<class L>
Listas::Lista<L>::Lista() :
	pInicio(nullptr), pFinal(nullptr), tam(0)
{
}

template<class L>
Listas::Lista<L>::~Lista()
{
	limparLista();
}

template<class L>
void Listas::Lista<L>::addElemento(L* elemento)
{
	Elemento<L>* newElemento = new Elemento<L>;
	newElemento->setElem(elemento);
	if (pInicio == nullptr) {
		pInicio = newElemento;
		pFinal = newElemento;
	}
	else {
		pFinal->setProx(newElemento);
		pFinal = newElemento;
	}
	tam++;
}

template<class L>
void Listas::Lista<L>::removerElemento(L* elemento)
{

	Elemento<L>* aux = pInicio;
	Elemento<L>* aux2 = nullptr;

	while (aux != nullptr && aux->getElemento() != elemento) {
		aux2 = aux;
		aux = aux->getProx();
	}
	if (aux->getElemento() == elemento) {
		if (aux == pInicio) {
			pInicio = aux->getProx();
		}
		else if (aux == pFinal) {
			pFinal = aux2;
		}
		else {
			aux2->setProx(aux->getProx());
		}
		tam--;
		delete(aux);
		aux = nullptr;
		aux2 = nullptr;
	}
}

template<class L>
void Listas::Lista<L>::removerElemento(int pos)
{
	L* elemento = operator[](pos);
	return removerElemento(elemento);
}

template<class L>
int Listas::Lista<L>::getTam()
{
	return (int)tam;
}

template<class L>
void Listas::Lista<L>::limparLista()
{
	if (pInicio) {
		Elemento<L>* aux = pInicio;
		Elemento<L>* aux2 = nullptr;
		while (aux != nullptr) {
			aux2 = aux->getProx();
			delete(aux->getElemento());
			aux = nullptr;
			aux = aux2;
		}
	}
	pInicio = nullptr;
	pFinal = nullptr;
}

template<class L>
L* Listas::Lista<L>::operator[](int pos)
{
	Elemento<L>* aux = pInicio;
	for (int i = 0; i < pos; i++) {
		aux = aux->getProx();
	}
	return aux->getElemento();
}

template<class L>
template<class E>
Listas::Lista<L>::Elemento<E>::Elemento() : prox(nullptr), elemento(nullptr) {}

template<class L>
template<class E>
Listas::Lista<L>::Elemento<E>::~Elemento() {}

template<class L>
template<class E>
void Listas::Lista<L>::Elemento<E>::setProx(Elemento<E>* prox)
{
	this->prox = prox;
}

template<class L>
template<class E>
void Listas::Lista<L>::Elemento<E>::setElem(E* elemento)
{
	this->elemento = elemento;
}

template<class L>
template<class E>
Listas::Lista<L>::Elemento<E>* Listas::Lista<L>::Elemento<E>::getProx()
{
	return prox;
}

template<class L>
template<class E>
E* Listas::Lista<L>::Elemento<E>::getElemento()
{
	return elemento;
};