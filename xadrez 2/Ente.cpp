#include "Ente.h"

Ente::Ente() : evento()
{}

Ente::~Ente()
{}

void Ente::desenhar()
{
	pGerGra->desenhaElemento(this);
}

static Gerenciadores::GerenciadorGrafico* Ente::pGerGra(Gerenciadores::GerenciadorGrafico.getGerenciadorGrafico())