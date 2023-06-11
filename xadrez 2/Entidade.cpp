#include "Entidade.h"

namespace Xadrez_2 {
	namespace Entidades {
		Entidade::Entidade(const Vector2f pos, const Vector2f tam, const IDs iD, Vector2f vel) :
			corpo(RectangleShape(tam)), pos(pos), tam(tam), Ente(iD), dirEsquerda(false), gravidade(0.f), estaVivo(true)
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

		void Entidade::setVel(Vector2f v)
		{
			vel = v;
		}

		Vector2f Entidade::getVel()
		{
			return vel;
		}

		void Entidade::mover(Vector2f a)
		{
			corpo.move(a);
		}

		bool Entidade::getDirecao()
		{
			return dirEsquerda;
		}

		void Entidade::setEstaVivo(bool a)
		{
			estaVivo = a;
		}

		bool Entidade::getEstaVivo()
		{
			return estaVivo;
		}

		void Entidade::setGravidade(float gravidade)
		{
			this->gravidade = gravidade;
		}

	}
}