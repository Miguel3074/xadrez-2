#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidade {
		Xadrez_2::Entidade::Entidade::Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs iD) :
			corpo(RectangleShape(tam)), pos(pos), tam(tam), Ente(iD)
		{
		}

		Entidade::Entidade::~Entidade()
		{
		}

		const RectangleShape Entidade::Entidade::getCorpo() const
		{
			return corpo;
		}

		void Entidade::Entidade::setPos(Vector2f p)
		{
			corpo.setPosition(p);
		}

		Vector2f Entidade::Entidade::getPos()
		{
			return corpo.getPosition();
		}

		Vector2f Entidade::Entidade::getTam()
		{
			return tam;
		}

		void Entidade::Entidade::atualizar()
		{
		}
	}
}