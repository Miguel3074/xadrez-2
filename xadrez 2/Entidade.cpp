#include "Entidade.h"

Entidades::Entidade::Entidade() : Ente(), corpo(), pos(0.0, 0.0), tam(0.0, 0.0)
{
	// Constrói o objeto retangulo aqui, e altera suas partes nas classes filhas
}

Entidades::Entidade::~Entidade() {}

const RectangleShape Entidades::Entidade::getCorpo() const
{
	return corpo;
}