#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Tabuleiro.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"
#include "GerenciadorColisao.h"


namespace Xadrez_2 {
	class Jogo;
	namespace Fase {
		class Fase : public Ente
		{
		protected:
			ListaEntidade listaEntidades;
			Gerenciador::GerenciadorColisao* pColisao;
			Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;
			Gerenciador::GerenciadorEvento* pEvento;

			Jogo* instanciaJogo;

			float gravidade;
		public:
			Fase(IDs::IDs ID_fase);
			~Fase();

			void setInstanciaJogo(Jogo* jogo);

			void criaPeao(const Vector2f pos);
			void criaJogador(const Vector2f pos);
			void criaTabuleiro(const Vector2f pos);
			void criaTorre(const Vector2f pos);
			void criaRainha(const Vector2f pos);
			virtual void criarMapa() = 0;
			void criarEntidade(char letra, const Vector2i pos);
			virtual void executar();
			void desenhar();


		};
	}
}

