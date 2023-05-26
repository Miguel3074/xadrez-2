#include "Jogo.h"

namespace Xadrez_2 {

	Gerenciador::GerenciadorGrafico* Jogo::pGerenciadorGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
	Gerenciador::GerenciadorEvento* Jogo::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

	Jogo::Jogo()
	{
		if (pGerenciadorGrafico == nullptr) {
			cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
			exit(1);
		}
		executar();
	}

	Jogo::~Jogo()
	{
	}

	void Jogo::executar()
	{
		instanciaEntidade();
		while (pGerenciadorGrafico->verificaJanelaAberta())
		{
			pEvento->executar();
			pGerenciadorGrafico->limpaJanela();
			listaEntidade.executar(pGerenciadorGrafico->getJanela());
			pGerenciadorGrafico->mostraElementos();
		}
	}

	void Jogo::instanciaEntidade()
	{
		Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(Vector2f(200.0f, 200.0f), Vector2f(50.0f, 50.0f), 0.15f);
		Entidade::Personagem::Inimigo::Inimigo* inimigo1 = new Entidade::Personagem::Inimigo::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f), jogador);
		Entidade::Personagem::Inimigo::Inimigo* inimigo2 = new Entidade::Personagem::Inimigo::Inimigo(Vector2f(300.0f, 200.0f), Vector2f(50.0f, 50.0f), jogador);

		Entidade::Personagem::Personagem* p1 = static_cast<Entidade::Personagem::Personagem*>(jogador);
		Entidade::Personagem::Personagem* p2 = static_cast<Entidade::Personagem::Personagem*>(inimigo1);
		Entidade::Personagem::Personagem* p3 = static_cast<Entidade::Personagem::Personagem*>(inimigo2);

		listaEntidade.addEntidade(p1);
		listaEntidade.addEntidade(p2);
		listaEntidade.addEntidade(p3);

		pEvento->setJogador(jogador);
		pEvento->setGerenciadorGrafico(pGerenciadorGrafico);
	}
}
