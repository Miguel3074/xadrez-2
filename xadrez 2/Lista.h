#pragma once

#include "stdafx.h"

namespace Xadrez_2 {
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
			Elemento() :
				prox(nullptr), elemento(nullptr)
			{

			}
			~Elemento() {}
			void setProx(Elemento<E>* prox)
			{
				this->prox = prox;
			}
			void setElem(E* elemento)
			{
				this->elemento = elemento;
			}
			Elemento<E>* getProx()
			{
				return prox;
			}
			E* getElemento()
			{
				if (elemento)
					return elemento;
				else
				{
					return nullptr;
				}
			};
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




	template<class L>
	Lista<L>::Lista() :
		pInicio(nullptr), pFinal(nullptr), tam(0)
	{
	}

	template<class L>
	Lista<L>::~Lista()
	{
		limparLista();
	}

	template<class L>
	void Lista<L>::addElemento(L* elemento)
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
	void Lista<L>::removerElemento(L* elemento)
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
			//aux2 = nullptr;
		}
	}

	template<class L>
	void Lista<L>::removerElemento(int pos)
	{
		L* elemento = operator[](pos);
		return removerElemento(elemento);
	}

	template<class L>
	int Lista<L>::getTam()
	{
		return (int)tam;
	}

	template<class L>
	void Lista<L>::limparLista()
	{
		if (pInicio) {
			Elemento<L>* aux = pInicio;
			Elemento<L>* aux2 = nullptr;
			while (aux != nullptr) {
				aux2 = aux->getProx();
				if (aux->getElemento()) {
					delete(aux->getElemento());
				}
				delete(aux);
				aux = aux2;
			}
		}
		tam = 0;
		pInicio = nullptr;
		pFinal = nullptr;
	}

	template<class L>
	L* Lista<L>::operator[](int pos)
	{
		Elemento<L>* aux = pInicio;
		for (int i = 0; i < pos; i++) {
			aux = aux->getProx();
		}
		return aux->getElemento();
	}
}