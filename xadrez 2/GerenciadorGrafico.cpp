#include "GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGerenciadorGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() :
	resolucao(1940, 1080), janela(new RenderWindow(VideoMode(1940, 1080), "Xadrez-2"))
{
	if (janela == nullptr) {
		cout << "ERROR: Nao foi possivel criar uma janela grafica" << endl;
		exit(1);
	}
}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela) {
		delete(janela);
		janela = nullptr;
	}
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr) {
		pGerenciadorGrafico = new Gerenciadores::GerenciadorGrafico();
	}
	return pGerenciadorGrafico;
}

RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela()
{
	return janela;
}

VideoMode Gerenciadores::GerenciadorGrafico::getResolucao()
{
	return resolucao;
}

void Gerenciadores::GerenciadorGrafico::limpaJanela()
{
	janela->clear();
}

void Gerenciadores::GerenciadorGrafico::desenhaElemento(RectangleShape corpo)
{
	janela->draw(corpo);
}

void Gerenciadores::GerenciadorGrafico::mostraElementos()
{
	janela->display();
}

void Gerenciadores::GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

const bool Gerenciadores::GerenciadorGrafico::verificaJanelaAberta()
{
	return janela->isOpen();
}
