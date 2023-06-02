#include "Ente.h"
namespace Xadrez_2 {

	Gerenciador::GerenciadorGrafico* Ente::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

	Ente::Ente(IDs::IDs ID) :
		ID(ID)
	{
	}

	Ente::~Ente()
	{
	}

	const  IDs::IDs Ente::getId() const
	{
		return ID;
	}

}