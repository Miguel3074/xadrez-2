#include "Menu.h"
#include "Jogo.h"

namespace Xadrez_2 {
	Menu::Menu() : 
		Ente(IDs::menu), fase1(), fase2(), pontos(), sair(), selecao(), menuOpcao(0), instanciaJogo(nullptr), perfilAtual(), perfis(), menuPerfil(true)
	{
		fase1.setString("Fase Biblioteca");
		fase2.setString("Fase Parque");
		pontos.setString("Pontos");
		sair.setString("Sair");
		selecao.setString(">>");

		fase1.setPosition(300, 200);
		fase2.setPosition(300, 250);
		pontos.setPosition(300, 300);
		sair.setPosition(300, 350);
		selecao.setPosition(270, 200);
		jogadorPerfil.setPosition(150, 75);

		if (!fonte.loadFromFile("Flavor_sans.otf"))
		{
			cout << "Falha ao carregar fonte." << endl;
			exit(1);
		}

		ifstream jogadoresPerfis("perfis.txt");
		if (!jogadoresPerfis.is_open()) {
			cout << "nao foi possivel abrir o arquivo" << endl;
			exit(1);
		}
		
		string linha;
		while (getline(jogadoresPerfis, linha))
		{
			string nome;
			string pontos;
			int i = 0;
			for (; linha[i] != '-'; i++)
			{
				nome += linha[i];
			}
			for (++i; i < linha.size(); i++)
			{
				pontos += linha[i];
			}
			Perfil* perfil = new Perfil();
			perfil->setNome(nome);
			perfil->setPontuacao(stoi(pontos));
			perfis.push_back(perfil);
		}

		jogadoresPerfis.close();

		organizarPerfis();

		fase1.setFont(fonte);
		fase2.setFont(fonte);
		pontos.setFont(fonte);
		sair.setFont(fonte);
		selecao.setFont(fonte);
		jogadorPerfil.setFont(fonte);
	}

	Menu::~Menu() {
		ofstream jogadoresPerfis("perfis.txt");
		if (!jogadoresPerfis.is_open()) {
			cout << "nao foi possivel abrir o arquivo" << endl;
			exit(1);
		}
		for (Perfil* p : perfis)
			jogadoresPerfis << p->getNome() + '-' + to_string(p->getPontuacao()) << endl;

		jogadoresPerfis.close();

		perfis.clear();
	}

	void Menu::rankings() {
		RenderWindow* janela = pGrafico->getJanela();
		Event evento;
		Text rank("", fonte);
		bool mostraRankings = true;

		while (mostraRankings)
		{
			janela->clear();
			rank.setString("Top 10");
			rank.setPosition(300, 50);
			janela->draw(rank);

			for (int i = 0; i < 10 && i < perfis.size(); i++)
			{
				rank.setPosition(300, 150 + 50 * i);
				rank.setString("Perfil: " + perfis[i]->getNome() + " - " + "Pontuacao: " + to_string(perfis[i]->getPontuacao()));
				janela->draw(rank);
			}
			janela->display();

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
						mostraRankings = false;
						break;
					}
					break;
				}
			}
		}
	}

	void Menu::organizarPerfis() {
		for (int i = 0; i < perfis.size(); i++)
		{
			for (int j = i; j < perfis.size(); j++)
				if (perfis[i]->getPontuacao() < perfis[j]->getPontuacao())
				{
					Perfil* aux = perfis[i];
					perfis[i] = perfis[j];
					perfis[j] = aux;
				}
		}
	}

	void Menu::menuPerfis()
	{
		RenderWindow* janela = pGrafico->getJanela();
		Event evento;
		Text nomePerfil("Novo Perfil", fonte);
		nomePerfil.setPosition(300, 200);

		if (menuOpcao > 1 && perfis.size() - menuOpcao > 1)
			selecao.setPosition(270, (200 + 50 * 2));
		else if (menuOpcao < 2 || perfis.size() < 5)
			selecao.setPosition(270, 200 + 50 * menuOpcao);
		else
			if (perfis.size() - menuOpcao < 1)
				selecao.setPosition(270, 200 + 50 * 4);
			else
				selecao.setPosition(270, 200 + 50 * 3);

		janela->draw(selecao);

		if (menuOpcao < 3) {
			janela->draw(nomePerfil);
			for (int i = 1; i < 5 && i <= perfis.size(); i++)
			{
				nomePerfil.setString(perfis[i-1]->getNome());
				nomePerfil.setPosition(300, 200 + 50 * i);
				janela->draw(nomePerfil);
			}
		}
		else if (perfis.size() - menuOpcao < 3) {
			for (int i = 0, j = perfis.size() - 5; i < 5; i++, j++)
			{
				nomePerfil.setString(perfis[j]->getNome());
				nomePerfil.setPosition(300, 200 + 50 * i);
				janela->draw(nomePerfil);
			}
		}
		else {
			for (int i = 0, j = menuOpcao - 3; i < 5; i++, j++)
			{
				nomePerfil.setString(perfis[j]->getNome());
				nomePerfil.setPosition(300, 200 + 50 * i);
				janela->draw(nomePerfil);
			}
		}


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
					menuOpcao >= perfis.size() ? menuOpcao = 0 : menuOpcao++;
					break;
				case Keyboard::W:
				case Keyboard::Up:
					menuOpcao <= 0 ? menuOpcao = perfis.size() : menuOpcao--;
					break;
				case Keyboard::Enter:
					if (menuOpcao == 0)
						criarPerfil();
					else
						perfilAtual = perfis[menuOpcao - 1];
					menuPerfil = false;
					menuOpcao = 1;
					if(perfilAtual)
						jogadorPerfil.setString("Ola, " + perfilAtual->getNome());
					return;
				}
				break;
			}
		}

	}

	void Menu::criarPerfil()
	{
		RenderWindow* janela = pGrafico->getJanela();
		Event evento;
		Text nomePerfil("", fonte), nomeInfo("Insira seu nome de jogador (10 caracteres permitidos, letras e numeros)", fonte);
		nomeInfo.setPosition(300, 150);
		nomePerfil.setPosition(300, 200);

		while (menuPerfil)
		{
			while (janela->pollEvent(evento))
			{
				janela->draw(nomeInfo);
				janela->draw(nomePerfil);
				janela->display();
				if (evento.type == Event::Closed)
				{
					pGrafico->fecharJanela();
					menuPerfil = false;
				}
				else if (evento.type == evento.KeyPressed)
				{
					if (nomePerfil.getString().getSize() < 10 && evento.key.code <= 35 && evento.key.code >= 0)
					{
						if (evento.key.code <= 25)
							nomePerfil.setString(nomePerfil.getString() + char(evento.key.code + 97));
						else if (evento.key.code == 26)
							nomePerfil.setString(nomePerfil.getString() + "0");
						else
							nomePerfil.setString(nomePerfil.getString() + to_string(evento.key.code - 26));
					}
					else if (evento.key.code == Keyboard::Key::Backspace)
					{
						if (nomePerfil.getString().getSize() > 0)
						{
							string original(nomePerfil.getString());
							string backspaced("");
							for (int i = 0; i < original.size() - 1; i++)
								backspaced += original[i];
							nomePerfil.setString(backspaced);
						}
					}
					else if (evento.key.code == Keyboard::Key::Escape)
					{
						pGrafico->fecharJanela();
						menuPerfil = false;
					}
					else if (evento.key.code == Keyboard::Key::Enter)
					{
						perfilAtual = new Perfil();
						perfilAtual->setNome(nomePerfil.getString());
						perfis.push_back(perfilAtual);
						menuPerfil = false;
					}

				}
				janela->clear();
			}
		}
	}

	void Menu::menuInicial()
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
		janela->draw(jogadorPerfil);

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
					if (menuOpcao == 3)
						rankings();
					else
						instanciaJogo->mudarTela(menuOpcao);
					return;
				}
				break;
			}
		}
	}

	void Menu::executar()
	{
		if(menuPerfil)
			menuPerfis();
		else
			menuInicial();
	}

	Menu::Perfil::Perfil() : nome(), pontuacao(0) {}
	Menu::Perfil::~Perfil() {}

	void Menu::Perfil::setNome(string nome) { this->nome = nome; }
	void Menu::Perfil::setPontuacao(unsigned int pontuacao) { this->pontuacao = pontuacao; }
	
	string Menu::Perfil::getNome() { return nome; }
	unsigned int Menu::Perfil::getPontuacao() { return pontuacao; }
}