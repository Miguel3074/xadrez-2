#include "Jogador.h"

void Entidades::Personagens::Jogador::Jogador::inicializa()
{
	vel = Vector2f(0.1f, 0.1f);

}

Entidades::Personagens::Jogador::Jogador() : Personagem()
{
	inicializa();
}

Entidades::Personagens::Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
	Personagem(pos, tam)
{
	corpo.setPosition(pos);
	corpo.setFillColor(Color::Blue);
	inicializa();
}

Entidades::Personagens::Jogador::Jogador::~Jogador()
{
}


void Entidades::Personagens::Jogador::Jogador::executar()
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		corpo.move(-vel.x, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		corpo.move(0.0f, -vel.y);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		corpo.move(vel.x, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		corpo.move(0.0f, vel.y);
	}
}
