#pragma once

#include "stdafx.h"



namespace Gerenciadores {

	class GerenciadorGrafico
	{
	private:
		RenderWindow* janela;

		//SINGLETON
		static GerenciadorGrafico* pJanela;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		RenderWindow* getJanela();
		void limpaJanela();
		void desenhaElemento(RectangleShape corpo);
		void mostraElementos();
		void fecharJanela();
		const bool verificaJanelaAberta();
	};

}
