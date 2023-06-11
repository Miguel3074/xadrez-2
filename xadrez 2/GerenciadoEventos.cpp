#include "GerenciadoEventos.h"
#include "Jogo.h"

namespace Xadrez_2 {
	namespace Gerenciadores {

		GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

		GerenciadorEvento::GerenciadorEvento() :
			instanciaJogo(nullptr), pjogador1(nullptr), pjogador2(nullptr), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
		{
		}

		GerenciadorEvento::~GerenciadorEvento()
		{
			if (pGerenciadorGrafico) {

			}
		}

		GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
		{
			if (pEvento == nullptr) {
				;
				pEvento = new GerenciadorEvento();
			}
			return pEvento;
		}


		void GerenciadorEvento::setJogador1(Entidades::Personagens::Jogador* pJogador1)
		{
			this->pjogador1 = pJogador1;
		}

		Entidades::Personagens::Jogador* GerenciadorEvento::getJogador1()
		{
			return pjogador1;
		}

		void GerenciadorEvento::setJogador2(Entidades::Personagens::Jogador* pJogador2)
		{
			this->pjogador2 = pJogador2;
		}

		Entidades::Personagens::Jogador* GerenciadorEvento::getJogador2()
		{
			return pjogador2;
		}

		void GerenciadorEvento::verificaTeclaPressionada(Keyboard::Key tecla)
		{
			if (tecla == Keyboard::A) {
				pjogador1->andar(true);

			}
			if (tecla == Keyboard::D) {
				pjogador1->andar(false);
			}
			if (tecla == Keyboard::W) {
				if (pjogador1->getVel().y <= 0.015f && pjogador1->getVel().y >= -0.015f) {
					pjogador1->setVel(Vector2f(pjogador1->getVel().x, 2.7f));
				}
			}
			if (tecla == Keyboard::Left) {
				pjogador2->andar(true);

			}
			if (tecla == Keyboard::Right) {
				pjogador2->andar(false);
			}
			if (tecla == Keyboard::Up) {
				if (pjogador2->getVel().y <= 0.015f && pjogador2->getVel().y >= -0.015f) {
					pjogador2->setVel(Vector2f(pjogador2->getVel().x, 2.7f));
				}
			}
			if (tecla == Keyboard::Escape) {
				instanciaJogo->mudarTela(0);
				pjogador1 = nullptr;
				pjogador2 = nullptr;
			}
		}

		void GerenciadorEvento::verificaTeclaSolta(Keyboard::Key tecla)
		{
			if (tecla == Keyboard::A || tecla == Keyboard::D) {
				pjogador1->parar();
			}
			if (tecla == Keyboard::Left || tecla == Keyboard::Right) {
				pjogador2->parar();
			}
		}

		void GerenciadorEvento::executar()
		{
			Event evento;
			while (pGerenciadorGrafico->getJanela()->pollEvent(evento))
			{
				if (evento.type == Event::KeyPressed) {
					verificaTeclaPressionada(evento.key.code);
				}
				else if (evento.type == Event::KeyReleased) {
					verificaTeclaSolta(evento.key.code);
				}
				else if (evento.type == Event::Closed)
				{
					pGerenciadorGrafico->fecharJanela();
				}

			}
		}
	}
}