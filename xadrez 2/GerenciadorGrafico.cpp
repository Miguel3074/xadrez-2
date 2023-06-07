#include "GerenciadorGrafico.h"

namespace Xadrez_2 {
	namespace Gerenciador {

		GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = GerenciadorGrafico::getGerenciadorGrafico();

		GerenciadorGrafico::GerenciadorGrafico() :
			resolucao(1920.f, 1080.0f), janela(new RenderWindow(VideoMode(1920.f, 1080.0f), "Xadrez-2"))
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

		VideoMode GerenciadorGrafico::getResolucao()
		{
			return resolucao;
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

		void GerenciadorGrafico::desenharSprite(Sprite sprite)
		{
			janela->draw(sprite);
		}


		const bool GerenciadorGrafico::verificaJanelaAberta()
		{
			return janela->isOpen();
		}
	}
}