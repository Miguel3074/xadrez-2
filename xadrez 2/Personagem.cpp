#include "Personagem.h"

Entidades::Personagens::Personagem::Personagem() : Entidade()
{}

Entidades::Personagens::Personagem::Personagem(const Vector2f pos, const Vector2f tam) : Entidade()
{
	corpo.setPosition(pos);
	corpo.setFillColor(Color::Blue);
	corpo.setSize(tam);
}

Entidades::Personagens::Personagem::~Personagem()
{}