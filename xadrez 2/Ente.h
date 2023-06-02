#pragma once
#include "GerenciadorGrafico.h"
#include "IDs.hpp"
#include "stdafx.h"

namespace Xadrez_2 {

	class Ente {

	protected:
		const IDs::IDs ID;
		static Gerenciador::GerenciadorGrafico* pGrafico;

	public:

		Ente(IDs::IDs ID);
		~Ente();

		//virtual void atualizar() = 0;
		const IDs::IDs getId() const;
	};

}