#pragma once

#include "Ente.h"

namespace Xadrez_2 {
	namespace Entidades {
		class Entidade : public Ente
		{
		protected:
			RectangleShape corpo;
			Vector2f pos;
			Vector2f tam;
			Vector2f vel;
			Texture textura;

			unsigned int pontuacao;
			bool estaVivo;
			bool dirEsquerda;
			float gravidade;

		public:
			Entidade(const Vector2f pos, const Vector2f tam, const IDs iD, Vector2f vel);
			virtual ~Entidade();
			const RectangleShape getCorpo() const;
			void setPos(Vector2f p);
			Vector2f getPos();
			Vector2f getTam();
			void setVel(Vector2f v);
			Vector2f getVel();
			bool getDirecao();
			void setEstaVivo(bool a);
			bool getEstaVivo();
			void setGravidade(float gravidade);
			void acrescentarPontuacao(unsigned int pontos) { pontuacao += pontos; }
			unsigned int verificarPontuacao() { return pontuacao; }
			virtual void colisao(Entidade* outraentidade, Vector2f ds) = 0;
			void mover(Vector2f a);
			virtual void executar() = 0;
		};
	}
}
