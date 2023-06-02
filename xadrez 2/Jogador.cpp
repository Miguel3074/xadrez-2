#include "Jogador.h"

void Entidades::Personagens::Jogador::inicializa()
{
	vel = Vector2f(0.1f, 0.1f);
	if (!this->textura.loadFromFile("../TEXTURAS/BRANCAS/cavaloB 78_130.png")) {
		cout << "Erro ao carregar a textura do cavalo\n";
	}
	textura.setSmooth(true);
	corpo.setTexture(&textura);
}

Entidades::Personagens::Jogador::Jogador() : Personagem()
{
	inicializa();
}

Entidades::Personagens::Jogador::Jogador(const Vector2f pos, const Vector2f tam, const float vel) :
	Personagem(pos, tam, vel, IDs::jogador)
{
	corpo.setPosition(pos);
	inicializa();
}

Entidades::Personagens::Jogador::~Jogador()
{
}


void Entidades::Personagens::Jogador::executar()
{
	if (podeAndar) {
		atualizarPosicao();
	}
	relogio.restart();
}

void Entidades::Personagens::Jogador::colisao(Entidade* outraentidade, Vector2f ds)
{
	switch (outraentidade->getId())
	{
	case(IDs::plataforma):
	{
		corpo.move(0, -ds.y);
	}
	break;
	case(IDs::inimigo):
	{
		corpo.move(-ds.x, 0);
	}
	break;
	}
}
