#pragma once

#include "FaseBiblio.h"
#include "FaseParque.h"
#include "Menu.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
		Gerenciador::GerenciadorEvento* pEvento;
		Fase::FaseBiblio* fase1;
		Fase::FaseParque* fase2;
		Menu* menu;
		Tela* faseAtual;

		void criarFase();
	public:
		Jogo();
		~Jogo();
		void mudarTela(int telaN);
		void executar();
	};

}