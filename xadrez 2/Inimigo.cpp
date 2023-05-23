#include "Inimigo.h"

void Xadrez_2::Personagem::Inimigo::Inimigo::inicializa()
{
}

Xadrez_2::Personagem::Inimigo::Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Jogador::Jogador* jogador):
	Personagem(pos,tam),relogio(),jogador(jogador)
{
	corpo.setFillColor(Color::Red);
	inicializa();
	srand(time(NULL));
	moveRand = rand() % 4;
}

Xadrez_2::Personagem::Inimigo::Inimigo::~Inimigo()
{
}

void Xadrez_2::Personagem::Inimigo::Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
{
}

void Xadrez_2::Personagem::Inimigo::Inimigo::movimentoAleatorio()
{
}

void Xadrez_2::Personagem::Inimigo::Inimigo::mover()
{
}
