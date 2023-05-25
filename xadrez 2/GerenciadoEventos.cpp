#include "GerenciadoEventos.h"

namespace Xadrez_2 {
	namespace Gerenciador {

		GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

		GerenciadorEvento::GerenciadorEvento()
		{
			pJanela = pJanela->getGerenciadorGrafico();
		}

		GerenciadorEvento::~GerenciadorEvento()
		{
			if (pJanela) {
				delete(pJanela);
				pJanela = nullptr;
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


		void GerenciadorEvento::setJogador(Personagem::Jogador::Jogador* pJogador)
		{
			this->pjogador = pJogador;
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
				pJanela->fecharJanela();
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
			while (pJanela->getJanela()->pollEvent(evento))
			{
				if (evento.type == Event::KeyPressed) {
					verificaTeclaPressionada(evento.key.code);
				}
				else if (evento.type == Event::KeyReleased) {
					verificaTeclaSolta(evento.key.code);
				}
				else if (evento.type == Event::Closed)
				{
					pJanela->fecharJanela();
				}

			}
		}
	}
}