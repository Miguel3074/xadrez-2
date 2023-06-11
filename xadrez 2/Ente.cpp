#include "Ente.h"

namespace Xadrez_2 {

	Gerenciadores::GerenciadorGrafico* Ente::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

	Ente::Ente(IDs ID) :
		ID(ID)
	{
	}

	Ente::~Ente()
	{
	}

	const IDs Ente::getId() const
	{
		return ID;
	}

}