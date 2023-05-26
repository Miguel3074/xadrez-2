#pragma once

#include "GerenciadorGrafico.h"
//#include "GerenciadorColisoes.h"

class Ente {
protected:
	//unsigned int id; //se precisarmos pesquisar algo pelo id numérica a algum ponto dá pra acionar isso aqui
	//static unsigned int ID_CONT; //pra auto-incrementar no caso acima
	static Xadrez_2::Gerenciador::GerenciadorGrafico* GGG; //Gerenciador Gráfico Geral, GGG
	// >Inserir variável para imagem da ent
	sf::Event evento;

public:
	Ente();
	~Ente();

	virtual void executar() = 0;
	void desenhar();
};