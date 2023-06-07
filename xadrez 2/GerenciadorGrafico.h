#pragma once

#include "stdafx.h"

namespace Xadrez_2 {

	namespace Gerenciador {

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
			void desenharSprite(Sprite sprite);
			void fecharJanela();
			const bool verificaJanelaAberta();
		};

	}
}