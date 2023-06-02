#include "GerenciadorColisao.h"

Gerenciadores::GerenciadorColisao::GerenciadorColisao(Listas::ListaEntidade* listaEntidades) :
	listaEntidades(listaEntidades)
{
}

Gerenciadores::GerenciadorColisao::~GerenciadorColisao()
{
	/*if (listaEntidades)
		delete(listaEntidades);*/
}

const Vector2f Gerenciadores::GerenciadorColisao::calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
{
	Vector2f distancia, metade_retangulo, colisao;
	distancia = { fabs((ent1->getPos().x + ent2->getTam().x / 2.0f) - (ent2->getPos().x + ent2->getTam().x / 2.0f)) ,
				  fabs((ent1->getPos().y + ent2->getTam().y / 2.0f) - (ent2->getPos().y + ent2->getTam().y / 2.0f)) };
	metade_retangulo = { (ent1->getTam().x + ent2->getTam().x) / 2.0f,
						 (ent1->getTam().y + ent2->getTam().y) / 2.0f };
	colisao = distancia - metade_retangulo;
	return colisao;
}

void Gerenciadores::GerenciadorColisao::executar()
{
	for (int i = 0; i < listaEntidades->getTam() - 1; i++) {
		Entidades::Entidade* ent1 = listaEntidades->operator[](i);
		for (int j = 0; j < listaEntidades->getTam(); j++) {
			Entidades::Entidade* ent2 = listaEntidades->operator[](j);
			sf::Vector2f ds = calculaColisao(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f) {
				ent1->colisao(ent2, ds);
			}
		}
	}
}