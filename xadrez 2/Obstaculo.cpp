#include "Obstaculo.h"


Entidades::Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, IDs id) :
	Entidade(pos, tam, id), aereo(false)
{
	corpo.setFillColor(Color::Green);
	corpo.setPosition(pos);
}

Entidades::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculo::executar()
{
}

void Entidades::Obstaculo::colisao(Entidades::Entidade* outraentidade, Vector2f ds)
{
}