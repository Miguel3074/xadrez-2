#include "Jogo.h"

namespace Xadrez_2 {
	void Jogo::criarFase()
	{
		menu->executar();
		menu->setInstanciaJogo(this);
		fase1->setInstanciaJogo(this);
		fase2->setInstanciaJogo(this);
	}

	Jogo::Jogo() :
		pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
		fase1(new Fases::FaseBiblio()), fase2(new Fases::FaseParque()), menu(new Menu()), faseAtual(menu),
		pEvento(Gerenciadores::GerenciadorEvento::getGerenciadorEvento())//, listaJogadores()
	{
		if (pGerenciadorGrafico == nullptr) {
			cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
			exit(1);
		}
		pEvento->setInstanciaJogo(this);
		criarFase();
		executar();
	}

	Jogo::~Jogo()
	{
		if (fase1)
			delete(fase1);
		if (fase2)
			delete(fase2);
		if (menu)
			delete(menu);
	}

	void Jogo::mudarTela(int telaN)
	{
		switch (telaN) {
		case 0:
			faseAtual = menu;
			break;
		case 1:
			fase1->criarMapa();
			faseAtual = fase1;
			break;
		case 2:
			fase2->criarMapa();
			faseAtual = fase2;
			break;
		case 4:
			pGerenciadorGrafico->fecharJanela();
			break;
		}
	}

	void Jogo::executar()
	{
		while (pGerenciadorGrafico->verificaJanelaAberta())
		{
			pGerenciadorGrafico->limpaJanela();
			faseAtual->executar();
			pGerenciadorGrafico->mostraElementos();
		}
	}
}