#include "GerenciadorColisao.h"

namespace Xadrez_2 {
	namespace Gerenciadores {
		GerenciadorColisao::GerenciadorColisao() :
			listaObstaculos(), listaInimigos(), listaFlecha(), jogador1(nullptr), jogador2(nullptr)
		{
		}

		GerenciadorColisao::~GerenciadorColisao()
		{

		}

		void GerenciadorColisao::definirJogador1(Entidades::Personagens::Jogador* jogador1)
		{
			this->jogador1 = jogador1;
		}

		Entidades::Personagens::Jogador* GerenciadorColisao::getJogador1()
		{
			return jogador1;
		}
		Entidades::Personagens::Jogador* GerenciadorColisao::getJogador2()
		{
			return jogador2;
		}


		void GerenciadorColisao::definirJogador2(Entidades::Personagens::Jogador* jogador2)
		{
			this->jogador2 = jogador2;
		}

		const Vector2f GerenciadorColisao::calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
		{
			Vector2f distancia, metade_retangulo, colisao;
			distancia = { fabs((ent1->getPos().x + ent1->getTam().x / 2.0f) - (ent2->getPos().x + ent2->getTam().x / 2.0f)) ,
						  fabs((ent1->getPos().y + ent1->getTam().y / 2.0f) - (ent2->getPos().y + ent2->getTam().y / 2.0f)) };
			metade_retangulo = { (ent1->getTam().x + ent2->getTam().x) / 2.0f,
								 (ent1->getTam().y + ent2->getTam().y) / 2.0f };
			colisao = sf::operator-(distancia, metade_retangulo);

			return colisao;
		}

		void GerenciadorColisao::incluirObstaculo(Entidades::Obstaculos::Obstaculo* obstaculo)
		{
			listaObstaculos.push_back(obstaculo);
		}

		void GerenciadorColisao::incluirInimigo(Entidades::Personagens::Inimigo* inimigo)
		{
			listaInimigos.push_back(inimigo);
		}

		void GerenciadorColisao::incluirFlecha(Entidades::Flecha* flecha)
		{
			listaFlecha.push_back(flecha);
		}

		void GerenciadorColisao::colidir(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
		{
			sf::Vector2f ds = calculaColisao(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f) {
				ent1->colisao(ent2, ds);
			}
		}

		void GerenciadorColisao::executar()
		{
			sf::Vector2f ds = sf::Vector2f();
			for (Entidades::Obstaculos::Obstaculo* obst : listaObstaculos)
			{
				if (!obst->getEstaVivo()) {
					continue;
				}
				if (jogador1->getEstaVivo()) {
					colidir(obst, jogador1);
				}
				if (jogador2->getEstaVivo()) {
					colidir(obst, jogador2);
				}

				for (Entidades::Obstaculos::Obstaculo* obst2 : listaObstaculos)
				{
					colidir(obst, obst2);
				}
				for (Entidades::Personagens::Inimigo* inim : listaInimigos)
				{
					if (!inim->getEstaVivo()) {
						continue;
					}
					colidir(obst, inim); 
					if (jogador1->getEstaVivo()) { 
						colidir(inim, jogador1); 
					}
					if (jogador2->getEstaVivo())  {
						colidir(inim, jogador2);  
					}
				}
				for (Entidades::Flecha* flecha : listaFlecha)
				{
					if (!flecha->getEstaVivo()) {
						continue;
					}
					colidir(obst, flecha);
					if (jogador1->getEstaVivo()) { 
						colidir(flecha, jogador1); 
					}
					if (jogador2->getEstaVivo()) { 
						colidir(flecha, jogador2); 
					}
				}
			}
		}
	}
}