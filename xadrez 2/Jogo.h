#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidade.h"

namespace Xadrez_2 {
	class Jogo
	{
	private:
		static Gerenciador::GerenciadorEvento* pEvento;
		Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
		Gerenciador::GerenciadorColisao colisor;
		ListaEntidade listaPersonagens;
		ListaEntidade listaObstaculos;
	public:
		Jogo();
		~Jogo();
		void executar();
		void instanciaEntidade();
	};

}