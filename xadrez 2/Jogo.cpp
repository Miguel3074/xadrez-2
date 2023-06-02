#include "Jogo.h"

namespace Xadrez_2 {

	Gerenciador::GerenciadorEvento* pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

	void Jogo::criarFase()
	{
		fase1->criarMapa();
	}

	Jogo::Jogo() :
		pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
		fase1(new Fase::FaseBiblio()), fase2(new Fase::FaseParque())
	{
		if (pGerenciadorGrafico == nullptr) {
			cout << "ERRO AO CRIAR GERENCIADOR GRAFICO";
			exit(1);
		}
		criarFase();
		executar();
	}

	Jogo::~Jogo()
	{
	}

	void Jogo::executar()
	{
		criarFase();
		while (pGerenciadorGrafico->verificaJanelaAberta())
		{
			pGerenciadorGrafico->limpaJanela();
			fase1->executar();
			pGerenciadorGrafico->mostraElementos();
		}
	}

}
