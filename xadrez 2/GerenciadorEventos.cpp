#include "GerenciadorEventos.h"

Gerenciadores::GerenciadorEventos* Gerenciadores::GerenciadorEventos::pEvento = nullptr;

Gerenciadores::GerenciadorEventos::GerenciadorEventos() :
	pjogador(nullptr), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
{
}

Gerenciadores::GerenciadorEventos::~GerenciadorEventos()
{
	if (pGerenciadorGrafico) {
		delete(pGerenciadorGrafico);
		pGerenciadorGrafico = nullptr;
	}
}

Gerenciadores::GerenciadorEventos* Gerenciadores::GerenciadorEventos::getGerenciadorEventos()
{
	if (pEvento == nullptr) {
		;
		return new GerenciadorEventos();
	}
	return pEvento;
}


void Gerenciadores::GerenciadorEventos::setJogador(Entidades::Personagens::Jogador* pJogador)
{
	this->pjogador = pJogador;
}

void Gerenciadores::GerenciadorEventos::verificaTeclaPressionada(Keyboard::Key tecla)
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

void Gerenciadores::GerenciadorEventos::verificaTeclaSolta(Keyboard::Key tecla)
{
	if (tecla == Keyboard::A || tecla == Keyboard::D) {
		pjogador->parar();
	}
}

void Gerenciadores::GerenciadorEventos::executar()
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