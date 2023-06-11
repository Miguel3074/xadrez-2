#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	class Jogo;
	class Menu : public Ente
	{
	private:

		//placeholders
		Font fonte;
		Text fase1, fase2, pontos, sair, selecao;
		//deve ter um nome pra um padrão de projeto que assiste o estado desse objeto, mas eu esqueci
		int menuOpcao;
		Jogo* instanciaJogo;

	public:
		Menu();
		~Menu();

		int getMenuOpcao();
		void setInstanciaJogo(Jogo* jogo) { this->instanciaJogo = jogo; }

		void executar();
	};
}