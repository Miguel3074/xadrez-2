#include "GerenciadorColisao.h"

Xadrez_2::Gerenciador::GerenciadorColisao::GerenciadorColisao(ListaEntidade* listaEntidades) :
	listaEntidades(listaEntidades)
{
}

Xadrez_2::Gerenciador::GerenciadorColisao::~GerenciadorColisao()
{

}

const Vector2f Xadrez_2::Gerenciador::GerenciadorColisao::calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((ent1->getPos().x + ent1->getTam().x / 2.0f) - (ent2->getPos().x + ent2->getTam().x / 2.0f)) ,
				  fabs((ent1->getPos().y + ent1->getTam().y / 2.0f) - (ent2->getPos().y + ent2->getTam().y / 2.0f)) };
	metade_retangulo = { (ent1->getTam().x + ent2->getTam().x) / 2.0f,
						 (ent1->getTam().y + ent2->getTam().y) / 2.0f };
	colisao = distancia - metade_retangulo;
	return colisao;
}

void Xadrez_2::Gerenciador::GerenciadorColisao::executar()
{
	for (int i = 0; i < listaEntidades->getTam() - 1; i++) {
		Entidade::Entidade* ent1 = listaEntidades->operator[](i);
		for (int j = i + 1; j < listaEntidades->getTam(); j++) {
			Entidade::Entidade* ent2 = listaEntidades->operator[](j);
			sf::Vector2f ds = calculaColisao(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f) {
				ent2->colisao(ent1, ds);
			}
		}
	}
}
