#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidade.h"

class Jogo {
private:
	static Gerenciadores::GerenciadorEventos* pEvento;
	Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;
	Gerenciadores::GerenciadorColisao colisor;
	Listas::ListaEntidade listaEntidades;
public:
	Jogo();
	~Jogo();
	void executar();
	void instanciaEntidade();
};