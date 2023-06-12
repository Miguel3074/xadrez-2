#pragma once
#include "GerenciadorGrafico.h"
#include "IDs.hpp"
#include "stdafx.h"

namespace Xadrez_2 {

	class Ente {

	protected:
		const IDs ID;
		static Gerenciadores::GerenciadorGrafico* pGrafico;

	public:

		Ente(IDs ID);
		virtual ~Ente();

		//virtual void atualizar() = 0;
		const IDs getId() const;
		virtual void executar() = 0;
	};

}