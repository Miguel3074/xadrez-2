#include "Jogador.h"

void Jogador::Jogador::inicializa()
{
	velocidade = Vector2f(0.1f, 0.1f);

}

Jogador::Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
	corpo(RectangleShape(tam))
{
	corpo.setPosition(pos);
	corpo.setFillColor(Color::Blue);
	inicializa();
}

Jogador::Jogador::Jogador(const RectangleShape corpo):
	corpo(corpo)
{
	inicializa();
}

Jogador::Jogador::Jogador():
	corpo()
{
	inicializa();
}

Jogador::Jogador::~Jogador()
{
}


void Jogador::Jogador::mover()
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		corpo.move(-velocidade.x, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		corpo.move(0.0f,- velocidade.y);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		corpo.move(velocidade.x, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		corpo.move(0.0f,velocidade.y);
	}
}
