#pragma once

//#include "ListaEntidade.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Flecha.h"

namespace Xadrez_2 {
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			list<Entidades::Obstaculos::Obstaculo*> listaObstaculos;
			list<Entidades::Personagens::Inimigo*> listaInimigos;
			list <Entidades::Flecha*> listaFlecha;
			Entidades::Personagens::Jogador* jogador1;
			Entidades::Personagens::Jogador* jogador2;

			const Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
			void colidir(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
		public:
			GerenciadorColisao();
			~GerenciadorColisao();

			void definirJogador1(Entidades::Personagens::Jogador* jogador1);
			Entidades::Personagens::Jogador* getJogador1();
			void definirJogador2(Entidades::Personagens::Jogador* jogador2);
			Entidades::Personagens::Jogador* getJogador2();

			void incluirObstaculo(Entidades::Obstaculos::Obstaculo* obstaculo);
			void incluirInimigo(Entidades::Personagens::Inimigo* inimigo);
			void incluirFlecha(Entidades::Flecha* flecha);

			void executar();
		};
	}
}