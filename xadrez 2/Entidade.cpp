#include "Entidade.h"

namespace Xadrez_2 {
	Xadrez_2::Entidade::Entidade::Entidade(const Vector2f pos, const Vector2f tam) :
		corpo(RectangleShape(tam)), pos(pos), tam(tam)
	{
	}

	Entidade::Entidade::~Entidade()
	{
	}

	const RectangleShape Entidade::Entidade::getCorpo() const
	{
		return corpo;
	}






}