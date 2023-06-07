#pragma once

#include "FaseBiblio.h"
#include "FaseParque.h"


namespace Xadrez_2 {
	class Jogo
	{
	private:
		Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
		static Gerenciador::GerenciadorEvento* pEvento;
		Fase::FaseBiblio* fase1;
		Fase::FaseParque* fase2;

		void criarFase();
	public:
		Jogo();
		~Jogo();
		void executar();
	};

}