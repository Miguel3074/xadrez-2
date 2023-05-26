#include "Ente.h"

Ente::Ente() : evento()
{}

Ente::~Ente()
{}

void Ente::desenhar()
{
	GGG->desenhaElemento(this);
}

static Xadrez_2::Gerenciador::GerenciadorGrafico* Ente::GGG(Xadrez_2::Gerenciador::GerenciadorGrafico.getGerenciadorGrafico())