#include "GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pJanela = nullptr;

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() :
	janela(new RenderWindow(VideoMode(1080.0f, 720.0f), "Xadrez-2"))
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
	if (pJanela == nullptr) {
		return new Gerenciadores::GerenciadorGrafico();
	}
	return pJanela;
}

RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela()
{
	return janela;
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
