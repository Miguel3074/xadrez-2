#pragma once

#include "Ente.h"

namespace Entidades {
	class Entidade : public Ente {
	protected:
		//variáveis de posição
		//eu lembro que no meu no passado eu tinha usado vector2f também, mas por algum motivo o professor coloca como int
		//vou deixar no jeito que ele deixou no diagrama, mas é tranquilo de editar no que a gente tem, então tá valendo
		int x, y;
		RectangleShape corpo;
		//notei que tu ta usando o namespace sf, mas deixei como comentário pq tá incluído em personagem no código que tu fez

	public:
		Entidade();
		~Entidade();

		const RectangleShape getCorpo();

		virtual void executar() = 0;

	};
}