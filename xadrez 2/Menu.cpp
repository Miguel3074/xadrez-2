#include "Menu.h"

Menu::Menu() : fase1(), fase2(), pontos(), sair(), selecao(), menuOpcao(0)
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
}

Menu::~Menu() {}

int Menu::getMenuOpcao() { return menuOpcao; }

void Menu::executar()
{
	Window* janela = pGerGra->getJanela();

	while (janela->pollEvent(this->evento)) {
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

		switch (evento.type)
		{
		case Event::Closed:
			system("quit");
			break;
		case Event::KeyPressed:
			Event::KeyEvent botao = evento.key;
			switch (botao.code)
			{
			case Keyboard::Escape:
				system("quit");
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
				return;
			}
			break;
		}
	}

}