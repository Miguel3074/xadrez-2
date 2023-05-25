#include "Personagem.h"


Xadrez_2::Personagem::Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel) :
	corpo(RectangleShape(tam)), dirEsquerda(false), dt(NULL), podeAndar(false), vel(vel, 0.0f)
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

void Xadrez_2::Personagem::Personagem::andar(const bool dirEsquerda)
{
	podeAndar = true;
	this->dirEsquerda = dirEsquerda;
}

void Xadrez_2::Personagem::Personagem::parar()
{
	podeAndar = false;
}

void Xadrez_2::Personagem::Personagem::atualizarPosicao()
{
	dt = relogio.getElapsedTime().asSeconds();
	float ds = 1000 * dt; //MRU
	if (dirEsquerda) {
		ds *= -1;
	}
	//cout << ds << endl;
	corpo.move(ds, 0.0f);
}