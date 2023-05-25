#include "Jogo.h"

namespace Xadrez_2 {

	Gerenciador::GerenciadorGrafico* Jogo::pJanela = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
	Gerenciador::GerenciadorEvento* Jogo::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

	Jogo::Jogo() :
		personagens()
	{
		if (pJanela == nullptr) {
			cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
			exit(1);
		}

		Personagem::Jogador::Jogador* jogador = new Personagem::Jogador::Jogador(Vector2f(200.0f, 200.0f), Vector2f(50.0f, 50.0f), 0.15f);
		Personagem::Inimigo::Inimigo* inimigo = new Personagem::Inimigo::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f), jogador);

		Personagem::Personagem* p1 = static_cast<Personagem::Personagem*>(jogador);
		Personagem::Personagem* p2 = static_cast<Personagem::Personagem*>(inimigo);

		personagens.push_back(p1);
		personagens.push_back(p2);

		pEvento->setJogador(jogador);

		executar();
	}

	Jogo::~Jogo()
	{
	}

	void Jogo::executar()
	{
		while (pJanela->verificaJanelaAberta())
		{
			pJanela->limpaJanela();
			pEvento->executar();
			for (int i = 0; i < personagens.size(); i++) {
				personagens.at(i)->atualizar();
				pJanela->desenhaElemento(personagens.at(i)->getCorpo());
			}
			pJanela->mostraElementos();
		}
		personagens.clear();
	}
}
