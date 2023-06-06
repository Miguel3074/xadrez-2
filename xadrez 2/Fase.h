#pragma once

#include "Ente.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Tabuleiro.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidade.h"


namespace Xadrez_2 {

	namespace Fase {
		class Fase : public Ente
		{
		protected:
			ListaEntidade listaEntidades;
			Gerenciador::GerenciadorColisao* pColisao;
			Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
			Gerenciador::GerenciadorEvento* pEvento;

			float gravidade;
		public:
			Fase(IDs::IDs ID_fase);
			~Fase();
			void criaPeao(const Vector2f pos);
			void criaJogador(const Vector2f pos);
			void criaTabuleiro(const Vector2f pos);
			void criaTorre(const Vector2f pos);
			void criaRainha(const Vector2f pos);
			virtual void criarMapa() = 0;
			void criarEntidade(char letra, const Vector2i pos);
			void executar();
			void desenhar();


		};
	}
}

