#include "Menu.h"
#include "Jogo.h"


Xadrez_2::Menu::Menu() : Ente(IDs::IDs::menu), fase1(), fase2(), pontos(), sair(), selecao(), menuOpcao(1), instanciaJogo(nullptr)
{
	fase1.setString("Fase 1");
	fase2.setString("Fase 2");
	pontos.setString("Pontos");
	sair.setString("Sair");
	selecao.setString(">>");

	fase1.setPosition(300, 200);
	fase2.setPosition(300, 250);
	pontos.setPosition(300, 300);
	sair.setPosition(300, 350);
	selecao.setPosition(270, 200);

	if (!fonte.loadFromFile("Flavor_sans.otf"))
	{
		std::cout << "Falha ao carregar fonte." << endl;
	}

	fase1.setFont(fonte);
	fase2.setFont(fonte);
	pontos.setFont(fonte);
	sair.setFont(fonte);
	selecao.setFont(fonte);
}

Xadrez_2::Menu::~Menu() {}

int Xadrez_2::Menu::getMenuOpcao() { return menuOpcao; }

void Xadrez_2::Menu::executar()
{
	RenderWindow* janela = pGrafico->getJanela();
	Event evento;

	switch (menuOpcao)
	{
	case 1:
		selecao.setPosition(270, 200);
		break;
	case 2:
		selecao.setPosition(270, 250);
		break;
	case 3:
		selecao.setPosition(270, 300);
		break;
	case 4:
		selecao.setPosition(270, 350);
		break;
	}

	janela->draw(selecao);
	janela->draw(fase1);
	janela->draw(fase2);
	janela->draw(pontos);
	janela->draw(sair);

	while (janela->pollEvent(evento)) {
		switch (evento.type)
		{
		case Event::Closed:
			pGrafico->fecharJanela();
			break;
		case Event::KeyPressed:
			Event::KeyEvent botao = evento.key;
			switch (botao.code)
			{
			case Keyboard::Escape:
				pGrafico->fecharJanela();
				break;
			case Keyboard::S:
			case Keyboard::Down:
				menuOpcao >= 4 ? menuOpcao = 1 : menuOpcao++;
				break;
			case Keyboard::W:
			case Keyboard::Up:
				menuOpcao <= 1 ? menuOpcao = 4 : menuOpcao--;
				break;
			case Keyboard::Enter:
				instanciaJogo->mudarTela(menuOpcao);
				return;
			}
			break;
		}
	}
}