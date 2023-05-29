#include "GerenciadoEventos.h"
namespace Xadrez_2 {
	namespace Gerenciador {

		GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

		GerenciadorEvento::GerenciadorEvento()
		{
		}

		GerenciadorEvento::~GerenciadorEvento()
		{
			if (pGerenciadorGrafico) {
				delete(pGerenciadorGrafico);
				pGerenciadorGrafico = nullptr;
			}
		}

		GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
		{
			if (pEvento == nullptr) {
				;
				return new GerenciadorEvento();
			}
			return pEvento;
		}


		void GerenciadorEvento::setJogador(Entidade::Personagem::Jogador::Jogador* pJogador)
		{
			this->pjogador = pJogador;
		}

		void GerenciadorEvento::setGerenciadorGrafico(GerenciadorGrafico* pGrafico)
		{
			this->pGerenciadorGrafico = pGrafico;
		}

		void GerenciadorEvento::verificaTeclaPressionada(Keyboard::Key tecla)
		{
			if (tecla == Keyboard::A) {
				pjogador->andar(true);
			}
			else if (tecla == Keyboard::D) {
				pjogador->andar(false);
			}
			else if (tecla == Keyboard::Escape) {
				pGerenciadorGrafico->fecharJanela();
			}
		}

		void GerenciadorEvento::verificaTeclaSolta(Keyboard::Key tecla)
		{
			if (tecla == Keyboard::A || tecla == Keyboard::D) {
				pjogador->parar();
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