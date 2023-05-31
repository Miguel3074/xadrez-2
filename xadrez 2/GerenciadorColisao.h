#pragma once

#include "ListaEntidade.h"


namespace Xadrez_2 {
	namespace Gerenciador
	{
		class GerenciadorColisao
		{
		private:
			ListaEntidade* listaPersonagem;
			ListaEntidade* listaObstaculo;
		public:
			GerenciadorColisao(ListaEntidade* listaPersonagem, ListaEntidade* listaObstaculo);
			~GerenciadorColisao();
			const Vector2f calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
			void executar();
		};
	}
}