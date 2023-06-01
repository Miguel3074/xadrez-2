#pragma once

#include "ListaEntidade.h"
#include "Entidade.h"

namespace Xadrez_2 {
	namespace Gerenciador
	{
		class GerenciadorColisao
		{
		private:
			ListaEntidade* listaEntidades;
		public:
			GerenciadorColisao(ListaEntidade* listaEntidades);
			~GerenciadorColisao();
			const Vector2f calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
			void executar();
		};
	}
}