#include "Jogo.h"

void Xadrez_2::Jogo::criarFase()
{
	menu->executar();
	menu->setInstanciaJogo(this);
	fase1->setInstanciaJogo(this);
	fase2->setInstanciaJogo(this);
}

namespace Xadrez_2 {

	Jogo::Jogo() :
		pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
		fase1(new Fase::FaseBiblio()), fase2(new Fase::FaseParque()), menu(new Menu()), faseAtual(menu),
		pEvento(Gerenciador::GerenciadorEvento::getGerenciadorEvento())
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
