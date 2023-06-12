#pragma once

#include "Ente.h"
#include "Jogador.h"
#include "Peao.h"
#include "Torre.h"
#include "Rainha.h"
#include "Tabuleiro.h"
#include "TeiaAranha.h"
#include "Espinho.h"
#include "GerenciadorGrafico.h"
#include "GerenciadoEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidade.h"


namespace Xadrez_2 {
	class Jogo;
	namespace Fases {
		class Fase : public Ente
		{
		protected:
			ListaEntidade listaEntidades;
			Gerenciadores::GerenciadorColisao* pColisao;
			Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;
			Gerenciadores::GerenciadorEvento* pEvento;
			list<Entidades::Personagens::Peao*> listaPeao;

			Texture texturaFundo;
			Sprite fundo;

			Jogo* instanciaJogo;

			float gravidade;
		public:
			Fase(IDs ID_fase);
			virtual ~Fase();
			void setInstanciaJogo(Jogo* jogo);
			void criaPeao(const Vector2f pos);
			void criaJogador(const Vector2f pos);
			void criaTabuleiro(const Vector2f pos);
			void criaTeia(const Vector2f pos);
			void criaEspinho(const Vector2f pos);
			void criaTorre(const Vector2f pos);
			void criaRainha(const Vector2f pos);
			virtual void criarMapa() = 0;
			void criarEntidade(char letra, const Vector2i pos);
			Vector2f randPos();
			int randQnty();
			virtual void executar();
		};
	}
}

