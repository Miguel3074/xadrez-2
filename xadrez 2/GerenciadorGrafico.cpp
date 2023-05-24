#include "GerenciadorGrafico.h"

Xadrez_2::Gerenciador::GerenciadorGrafico* Xadrez_2::Gerenciador::GerenciadorGrafico::pJanela = nullptr;

Xadrez_2::Gerenciador::GerenciadorGrafico::GerenciadorGrafico() :
	janela(new RenderWindow(VideoMode(1080.0f, 720.0f), "Xadrez-2"))
{
	if (janela == nullptr) {
		cout << "ERROR: Nao foi possivel criar uma janela grafica" << endl;
		exit(1);
	}
}

Xadrez_2::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela) {
		delete(janela);
		janela = nullptr;
	}
}

Xadrez_2::Gerenciador::GerenciadorGrafico* Xadrez_2::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pJanela == nullptr) {
		return new Xadrez_2::Gerenciador::GerenciadorGrafico();
	}
	return pJanela;
}

RenderWindow* Xadrez_2::Gerenciador::GerenciadorGrafico::getJanela()
{
	return janela;
}

void Xadrez_2::Gerenciador::GerenciadorGrafico::limpaJanela()
{
	janela->clear();
}

void Xadrez_2::Gerenciador::GerenciadorGrafico::desenhaElemento(RectangleShape corpo)
{
	janela->draw(corpo);
}

void Xadrez_2::Gerenciador::GerenciadorGrafico::mostraElementos()
{
	janela->display();
}

void Xadrez_2::Gerenciador::GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

const bool Xadrez_2::Gerenciador::GerenciadorGrafico::verificaJanelaAberta()
{
	return janela->isOpen();
}
