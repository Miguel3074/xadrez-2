#include "Jogo.h"

Xadrez_2::Jogo::Jogo() :
	personagens(), pJanela(pJanela->getGerenciadorGrafico())
{
	if (pJanela == nullptr) {
		cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
		exit(1);
	}


	Personagem::Jogador::Jogador* jogador = new Personagem::Jogador::Jogador(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f));
	Personagem::Inimigo::Inimigo* inimigo = new Personagem::Inimigo::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f), jogador);

	Personagem::Personagem* p1 = static_cast<Personagem::Personagem*>(jogador);
	Personagem::Personagem* p2 = static_cast<Personagem::Personagem*>(inimigo);

	personagens.push_back(p1);
	personagens.push_back(p2);

	executar();
}

Xadrez_2::Jogo::~Jogo()
{
}

void Xadrez_2::Jogo::executar()
{
	while (pJanela->verificaJanelaAberta())
	{
		Event evento;
		if (pJanela->getJanela()->pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				pJanela->fecharJanela();
			}
			else if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Escape) {
					pJanela->fecharJanela();
				}
			}
		}
		pJanela->limpaJanela();
		for (int i = 0; i < personagens.size(); i++) {
			personagens.at(i)->move();
			pJanela->desenhaElemento(personagens.at(i)->getCorpo());
		}
		pJanela->mostraElementos();
	}
	personagens.clear();
}
