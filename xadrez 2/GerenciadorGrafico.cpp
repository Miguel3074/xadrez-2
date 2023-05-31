#include "GerenciadorGrafico.h"

namespace Xadrez_2 {
	namespace Gerenciador {

		GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = GerenciadorGrafico::getGerenciadorGrafico();

		GerenciadorGrafico::GerenciadorGrafico() :
			janela(new RenderWindow(VideoMode(1080.0f, 720.0f), "Xadrez-2"))
		{
			if (janela == nullptr) {
				cout << "ERROR: Nao foi possivel criar uma janela grafica" << endl;
				exit(1);
			}
		}

		GerenciadorGrafico::~GerenciadorGrafico()
		{
			if (janela) {
				delete(janela);
				janela = nullptr;
			}
		}

		GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
		{
			if (pGerenciadorGrafico == nullptr) {
				pGerenciadorGrafico = new GerenciadorGrafico();
			}
			return pGerenciadorGrafico;
		}

		RenderWindow* GerenciadorGrafico::getJanela()
		{
			return janela;
		}

		void GerenciadorGrafico::limpaJanela()
		{
			janela->clear();
		}

		void GerenciadorGrafico::desenhaElemento(RectangleShape corpo)
		{
			janela->draw(corpo);
		}

		void GerenciadorGrafico::mostraElementos()
		{
			janela->display();
		}

		void GerenciadorGrafico::fecharJanela()
		{
			janela->close();
		}

		const bool GerenciadorGrafico::verificaJanelaAberta()
		{
			return janela->isOpen();
		}
	}
}