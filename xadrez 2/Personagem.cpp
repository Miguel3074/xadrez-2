#include "Personagem.h"

Xadrez_2::Personagem::Personagem::Personagem(const Vector2f pos, const Vector2f tam) :
	corpo(RectangleShape(tam))
{
	corpo.setPosition(pos);
	corpo.setFillColor(Color::Blue);
}

Xadrez_2::Personagem::Personagem::~Personagem()
{
}

const RectangleShape Xadrez_2::Personagem::Personagem::getCorpo()
{
	return corpo;
}

