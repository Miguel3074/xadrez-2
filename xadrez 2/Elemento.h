#pragma once



namespace Xadrez_2 {
	namespace Lista {

		template<class TE>
		class Elemento
		{
		private:
			Elemento<TE>* prox;
			TE* elemento;
		public:
			Elemento();
			~Elemento();
			void setProx(Elemento<TE>* prox);
			void setElem(TE* elemento);
			Elemento<TE>* getProx();
			TE* getElemento();
		};

		template<class TE>
		inline Elemento<TE>::Elemento() :
			prox(nullptr), elemento(nullptr)
		{
		}

		template<class TE>
		inline Elemento<TE>::~Elemento()
		{
		}

		template<class TE>
		inline void Elemento<TE>::setProx(Elemento<TE>* prox)
		{
			this->prox = prox;
		}

		template<class TE>
		inline void Elemento<TE>::setElem(TE* elemento)
		{
			this->elemento = elemento;
		}

		template<class TE>
		inline Elemento<TE>* Elemento<TE>::getProx()
		{
			return prox;
		}

		template<class TE>
		inline TE* Elemento<TE>::getElemento()
		{
			return elemento;
		}
	}
}

