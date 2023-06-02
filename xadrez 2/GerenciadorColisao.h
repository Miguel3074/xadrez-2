#pragma once

#include "ListaEntidade.h"


namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		Listas::ListaEntidade* listaEntidades;
	public:
		GerenciadorColisao(Listas::ListaEntidade* listaEntidades);
		~GerenciadorColisao();
		const Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
		void executar();
	};
}
