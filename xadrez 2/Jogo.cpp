#include "Jogo.h"

Gerenciadores::GerenciadorEventos* Jogo::pEvento = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();

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
	Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(Vector2f(500.0f, 200.0f), Vector2f(78.0f, 130.0f), 0.15f);
	Entidades::Personagens::Inimigo* inimigo1 = new Entidades::Personagens::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(73.0f, 107.0f), jogador);
	Entidades::Personagens::Inimigo* inimigo2 = new Entidades::Personagens::Inimigo(Vector2f(600.0f, 200.0f), Vector2f(73.0f, 107.0f), jogador);
	Entidades::Obstaculo* obstaculo1 = new Entidades::Obstaculo(Vector2f(0.0f, static_cast<float>(pGerenciadorGrafico->getResolucao().height) - 100.0f),
		Vector2f(static_cast<float>(pGerenciadorGrafico->getResolucao().width), 100.0f), IDs::plataforma);

	Entidades::Personagens::Personagem* p1 = static_cast<Entidades::Personagens::Personagem*>(jogador);
	Entidades::Personagens::Personagem* p2 = static_cast<Entidades::Personagens::Personagem*>(inimigo1);
	Entidades::Personagens::Personagem* p3 = static_cast<Entidades::Personagens::Personagem*>(inimigo2);
	Entidades::Obstaculo* o1 = static_cast<Entidades::Obstaculo*>(obstaculo1);


	listaEntidades.addEntidade(p1);
	listaEntidades.addEntidade(p2);
	listaEntidades.addEntidade(p3);
	listaEntidades.addEntidade(o1);

	pEvento->setJogador(jogador);
}