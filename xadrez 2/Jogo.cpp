#include "Jogo.h"

Jogo::Jogo() : personagens()
{
	if (pGerGra == nullptr) {
		cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
		exit(1);
	}


	Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f));
	Entidades::Personagens::Inimigo* inimigo = new Entidades::Personagens::Inimigo(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f));

	Entidades::Personagens::Personagem* p1 = static_cast<Entidades::Personagens::Personagem*>(jogador);
	Entidades::Personagens::Personagem* p2 = static_cast<Entidades::Personagens::Personagem*>(inimigo);

	personagens.push_back(p1);
	personagens.push_back(p2);

	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (pGerGra->verificaJanelaAberta())
	{
		Event evento;
		if (pGerGra->getJanela()->pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				pGerGra->fecharJanela();
			}
			else if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Escape) {
					pGerGra->fecharJanela();
				}
			}
		}
		pGerGra->limpaJanela();
		for (int i = 0; i < (int) personagens.size(); i++) {
			personagens.at(i)->executar();
			pGerGra->desenhaElemento(personagens.at(i)->getCorpo());
		}
		pGerGra->mostraElementos();
	}
	personagens.clear();
}

static Gerenciadores::GerenciadorGrafico* Ente::pGerGra(Gerenciadores::GerenciadorGrafico.getGerenciadorGrafico())