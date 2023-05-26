#include "Entidade.h"

Entidades::Entidade::Entidade() : Ente(), x(0), y(0), corpo()
{
	// Constrói o objeto retangulo aqui, e altera suas partes nas classes filhas
}

Entidades::Entidade::~Entidade() {}

const RectangleShape Entidades::Entidade::getCorpo()
{
	return corpo;
}