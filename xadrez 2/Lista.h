#pragma once

#include "Elemento.h"

namespace Xadrez_2 {
	namespace Lista {

		template<class TL>
		class Lista
		{
		private:
			Elemento<TL>* pInicio;
			Elemento<TL>* pFinal;
			unsigned int tam;
		public:
			Lista();
			~Lista();
			void addElemento(TL* elemento);
			void removerElemento(TL* elemento);
			void removerElemento(int pos);
			int getTam();
			void limparLista();
			TL* operator[](int pos);
		};

		template<class TL>
		inline Lista<TL>::Lista() :
			pInicio(nullptr), pFinal(nullptr), tam(0)
		{
		}

		template<class TL>
		inline Lista<TL>::~Lista()
		{
			limparLista();
		}

		template<class TL>
		inline void Lista<TL>::addElemento(TL* elemento)
		{
			Elemento<TL>* newElemento = new Elemento<TL>();
			if (newElemento == nullptr) {
				std::cout << "ERROR::Lista aux eh nullptr" << std::endl;
				exit(1);
			}
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

		template<class TL>
		inline void Lista<TL>::removerElemento(TL* elemento)
		{
			Elemento<TL>* aux = pInicio;
			Elemento<TL>* aux2 = nullptr;

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

		template<class TL>
		inline void Lista<TL>::removerElemento(int pos)
		{
			TL* elemento = operator[](pos);
			return removerElemento(elemento);
		}

		template<class TL>
		inline int Lista<TL>::getTam()
		{
			return (int)tam;
		}

		template<class TL>
		inline void Lista<TL>::limparLista()
		{
			if (pInicio) {
				Elemento<TL>* aux = pInicio;
				Elemento<TL>* aux2 = nullptr;
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

		template<class TL>
		inline TL* Lista<TL>::operator[](int pos)
		{
			Elemento<TL>* aux = pInicio;
			for (int i = 0; i < pos; i++) {
				aux = aux->getProx();
			}
			return aux->getElemento();
		}
	}
}


