#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Gerenciadores {

	class GerenciadorEventos
	{
	private:
		Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;
		Entidades::Personagens::Jogador* pjogador;

		static GerenciadorEventos* pEvento;
		GerenciadorEventos();
	public:

		~GerenciadorEventos();
		static GerenciadorEventos* getGerenciadorEventos();
		void setJogador(Entidades::Personagens::Jogador* pJogador);
		void verificaTeclaPressionada(Keyboard::Key tecla);
		void verificaTeclaSolta(Keyboard::Key tecla);
		void executar();
	};
}
