#pragma once

#include "Ente.h"
#include "Tela.h"

class Menu : public Ente, public Tela
{
private:

	//placeholders
	Text fase1, fase2, pontos, sair, selecao;
	//deve ter um nome pra um padrão de projeto que assiste o estado desse objeto, mas eu esqueci
	int menuOpcao;

public:
	Menu();
	~Menu();

	int getMenuOpcao();

	void executar();
};