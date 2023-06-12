#pragma once

#include "FaseBiblio.h"
#include "FaseParque.h"
#include "Menu.h"
#include <string>

namespace Xadrez_2 {
	class Jogo
	{
	private:
		Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;
		Gerenciadores::GerenciadorEvento* pEvento;
		Fases::FaseBiblio* fase1;
		Fases::FaseParque* fase2;
		Menu* menu;
		Ente* faseAtual;
		//list<string> listaJogadores;

		void criarFase();
	public:
		Jogo();
		~Jogo();

		void verificarMaiorPontuacao(unsigned int pontos) { menu->setMelhorPontuacao(pontos); }

		void mudarTela(int telaN);
		void executar();
	};

}