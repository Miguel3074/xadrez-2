#pragma once

#include "Ente.h"

namespace Entidades {
	class Entidade : public Ente {
	protected:
		//vari�veis de posi��o
		//eu lembro que no meu no passado eu tinha usado vector2f tamb�m, mas por algum motivo o professor coloca como int
		//vou deixar no jeito que ele deixou no diagrama, mas � tranquilo de editar no que a gente tem, ent�o t� valendo
		int x, y;
		RectangleShape corpo;
		//notei que tu ta usando o namespace sf, mas deixei como coment�rio pq t� inclu�do em personagem no c�digo que tu fez

	public:
		Entidade();
		~Entidade();

		const RectangleShape getCorpo();

		virtual void executar() = 0;

	};
}