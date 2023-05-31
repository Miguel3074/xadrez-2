#include "Entidade.h"

namespace Xadrez_2 {
	Xadrez_2::Entidade::Entidade::Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs iD) :
		corpo(RectangleShape(tam)), pos(pos), tam(tam), ID(iD)
	{
	}

	Entidade::Entidade::~Entidade()
	{
	}

	const RectangleShape Entidade::Entidade::getCorpo() const
	{
		return corpo;
	}

	Vector2f Entidade::Entidade::getPos()
	{
		return pos;
	}

	Vector2f Entidade::Entidade::getTam()
	{
		return tam;
	}

	IDs::IDs Entidade::Entidade::getId()
	{
		return ID;
	}

}