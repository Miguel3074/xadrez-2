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
		Fase::Menu* menu;
		Fase::Fase* faseAtual;

		void criarFase();
	public:
		Jogo();
		~Jogo();
		void mudarTela(int telaN);
		void executarFase1() { faseAtual = fase1; }
		void executarFase2() { faseAtual = fase2; }
		void executar();
	};

}