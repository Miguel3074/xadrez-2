#include "Personagem.h"

Entidades::Personagens::Personagem::Personagem() : Entidade(), dirEsquerda(false), dt(NULL), podeAndar(false), vel(0.0f, 0.0f)
{}

Entidades::Personagens::Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel, IDs iD) :
	Entidade(pos, tam, iD), dirEsquerda(false), dt(NULL), podeAndar(false), vel(vel, 0.0f)
{
	corpo.setPosition(pos);
}

Entidades::Personagens::Personagem::~Personagem()
{}

void Entidades::Personagens::Personagem::andar(const bool dirEsquerda)
{
	podeAndar = true;
	this->dirEsquerda = dirEsquerda;
}

void Entidades::Personagens::Personagem::parar()
{
	podeAndar = false;
}

void Entidades::Personagens::Personagem::setVel(Vector2f v)
{
	vel = v;
}

Vector2f Entidades::Personagens::Personagem::getVel()
{
	return vel;
}

void Entidades::Personagens::Personagem::atualizarPosicao()
{
	dt = relogio.getElapsedTime().asSeconds();
	float ds = 1000 * dt; //MRU
	if (dirEsquerda) {
		ds *= -1;
	}
	corpo.move(ds, 0.0f);
}