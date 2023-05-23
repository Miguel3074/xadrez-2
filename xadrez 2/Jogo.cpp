#include "Jogo.h"

Xadrez_2::Jogo::Jogo():
	janela(VideoMode(1080.0f, 720.0f), "Xadrez 2"), jogador(Vector2f(500.0f,500.0f),Vector2f(50.0f,50.0f) )
{
	executar();
}

Xadrez_2::Jogo::~Jogo()
{
}

void Xadrez_2::Jogo::executar()
{
	while (janela.isOpen())
	{
		Event evento;
		if (janela.pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				janela.close();   
			}
			else if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Escape) {
					janela.close();
				}
			}
		}
		janela.clear();
		jogador.mover();
		janela.draw(jogador.getCorpo());
		janela.display();
	}
}
