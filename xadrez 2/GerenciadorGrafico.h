#pragma once

#include "stdafx.h"

namespace Xadrez_2 {

	namespace Gerenciador {

		class GerenciadorGrafico
		{
		private:
			RenderWindow* janela;

			//SINGLETON
			static GerenciadorGrafico* pGerenciadorGrafico;
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
}