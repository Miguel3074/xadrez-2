#pragma once

#include "Jogo.h"

// padr�o de projeto state
class Tela {
protected:
	Jogo* jogo;

public:
	Tela() : jogo(nullptr) {}
	virtual ~Tela() {}
	void instanciaJogo(Jogo* Ijogo) { jogo = Ijogo;  }
	virtual void executar() = 0;
};