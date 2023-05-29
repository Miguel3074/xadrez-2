#pragma once

#include "GerenciadorGrafico.h"
//#include "GerenciadorColisoes.h"

class Ente {
protected:
	//unsigned int id; //se precisarmos pesquisar algo pelo id num�rica a algum ponto d� pra acionar isso aqui
	//static unsigned int ID_CONT; //pra auto-incrementar no caso acima
	static Gerenciadores::GerenciadorGrafico* pGerGra; //Gerenciador Gr�fico Geral, GGG
	// >Inserir vari�vel para imagem da ent
	sf::Event evento;

public:
	Ente();
	~Ente();

	virtual void executar() = 0;
	void desenhar();
};