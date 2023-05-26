#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"
#include "ListaEntidade.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		static Gerenciador::GerenciadorEvento* pEvento;
		static Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
		Lista::ListaEntidade listaEntidade;
	public:
		Jogo();
		~Jogo();
		void executar();
		void instanciaEntidade();
	};

}