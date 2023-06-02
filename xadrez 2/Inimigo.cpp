#include "Inimigo.h"

void Entidades::Personagens::Inimigo::inicializa()
{
	vel = Vector2f(0.05f, 0.05f);
	if (!this->textura.loadFromFile("../TEXTURAS/PRETAS/peaoP 73_107.png")) {
		cout << "Erro ao carregar a textura do peao\n";
	}
	textura.setSmooth(true);
	corpo.setTexture(&textura);
}

Entidades::Personagens::Inimigo::Inimigo() : Personagem(), relogio(), jogador()
{}

Entidades::Personagens::Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Jogador* jogador) :
	Personagem(pos, tam, vel.x, IDs::inimigo), relogio(), jogador(jogador)
{
	podeAndar = true;
	inicializa();
	srand((unsigned) time(NULL));
	//moveRand = rand() % 4;
}

Entidades::Personagens::Inimigo::~Inimigo()
{
}

void Entidades::Personagens::Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(vel.x, 0.0f);
	}
	else {
		corpo.move(-vel.x, 0.0f);
	}
	if (posJogador.y - posInimigo.y > 0.0f) {
		corpo.move(0.0f, vel.y);
	}
	else {
		corpo.move(0.0f, -vel.y);
	}
}

void Entidades::Personagens::Inimigo::movimentoAleatorio()
{
}

void Entidades::Personagens::Inimigo::executar()
{
	Vector2f posJogador = jogador->getCorpo().getPosition();
	Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
		persegueJogador(posJogador, posInimigo);
	}
	else {
		podeAndar = true;
	}
}

void Entidades::Personagens::Inimigo::colisao(Entidade* outraentidade, Vector2f ds)
{
	switch (outraentidade->getId())
	{
	case(IDs::plataforma):
	{

	}
	break;
	case(IDs::jogador):
	{
		corpo.move(-ds.x, 0);
		parar();
	}
	break;
	}
}
