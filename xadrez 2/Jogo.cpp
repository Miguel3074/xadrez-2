#include "Jogo.h"

namespace Xadrez_2 {

	Gerenciador::GerenciadorEvento* Jogo::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

	Jogo::Jogo() :
		pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
		colisor(&listaEntidades)
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
			listaEntidades.executar(pGerenciadorGrafico->getJanela());

			colisor.executar();

			pGerenciadorGrafico->mostraElementos();
		}
	}

	void Jogo::instanciaEntidade()
	{
		Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(Vector2f(500.0f, 200.0f), Vector2f(78.0f, 130.0f), 0.15f);
		Entidade::Personagem::Inimigo::Inimigo* inimigo1 = new Entidade::Personagem::Inimigo::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(73.0f, 107.0f), jogador);
		Entidade::Personagem::Inimigo::Inimigo* inimigo2 = new Entidade::Personagem::Inimigo::Inimigo(Vector2f(600.0f, 200.0f), Vector2f(73.0f, 107.0f), jogador);
		Entidade::Obstaculo::Obstaculo* obstaculo1 = new Entidade::Obstaculo::Obstaculo(Vector2f(0.0f, pGerenciadorGrafico->getResolucao().height - 100.0f), Vector2f(pGerenciadorGrafico->getResolucao().width, 100.0f), IDs::IDs::plataforma);

		Entidade::Personagem::Personagem* p1 = static_cast<Entidade::Personagem::Personagem*>(jogador);
		Entidade::Personagem::Personagem* p2 = static_cast<Entidade::Personagem::Personagem*>(inimigo1);
		Entidade::Personagem::Personagem* p3 = static_cast<Entidade::Personagem::Personagem*>(inimigo2);
		Entidade::Obstaculo::Obstaculo* o1 = static_cast<Entidade::Obstaculo::Obstaculo*>(obstaculo1);


		listaEntidades.addEntidade(p1);
		listaEntidades.addEntidade(p2);
		listaEntidades.addEntidade(p3);
		listaEntidades.addEntidade(o1);

		pEvento->setJogador(jogador);
	}
}
