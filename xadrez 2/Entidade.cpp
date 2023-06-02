#include "Entidade.h"

Entidades::Entidade::Entidade() : Ente(), corpo(tam), pos(0.0, 0.0), tam(0.0, 0.0), ID(IDs::vazio), textura()
{
	// Constrói o objeto retangulo aqui, e altera suas partes nas classes filhas
}

Entidades::Entidade::Entidade(const Vector2f pos, const Vector2f tam, const IDs iD) : Ente(), corpo(this->tam), pos(pos), tam(tam), ID(iD), textura()
{

}

Entidades::Entidade::~Entidade() {}

const RectangleShape Entidades::Entidade::getCorpo() const
{
	return corpo;
}

Vector2f Entidades::Entidade::getPos() { return pos; }

Vector2f Entidades::Entidade::getTam() { return tam; }

IDs Entidades::Entidade::getId() { return ID; }