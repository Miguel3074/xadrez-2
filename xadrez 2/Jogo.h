#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"

class Jogo {
private:
	static Gerenciadores::GerenciadorGrafico* pGerGra;
	vector<Entidades::Personagens::Personagem*> personagens;
public:
	Jogo();
	~Jogo();
	void executar();
};