#pragma once

#include "stdafx.h"



namespace Gerenciadores {

	class GerenciadorGrafico
	{
	private:
		RenderWindow* janela;
		VideoMode resolucao;

		//SINGLETON
		static GerenciadorGrafico* pGerenciadorGrafico;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		RenderWindow* getJanela();
		VideoMode getResolucao();
		void limpaJanela();
		void desenhaElemento(RectangleShape corpo);
		void mostraElementos();
		void fecharJanela();
		const bool verificaJanelaAberta();
	};

}
