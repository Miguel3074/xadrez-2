#include "Jogador.h"
namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				void Jogador::inicializa()
				{
					vel = Vector2f(0.1f, 0.1f);

				}

				Jogador::Jogador(const Vector2f pos, const Vector2f tam, const float vel) :
					Personagem(pos, tam, vel, IDs::IDs::jogador)
				{
					corpo.setPosition(pos);
					corpo.setFillColor(Color::Blue);
					inicializa();
				}

				Jogador::~Jogador()
				{
				}


				void Jogador::atualizar()
				{

					if (podeAndar) {
						atualizarPosicao();
					}
					relogio.restart();

				}
				void Jogador::colisao(Entidade* outraentidade, Vector2f ds)
				{
					switch (outraentidade->getId())
					{
					case(IDs::IDs::plataforma):
					{

					}
					break;
					case(IDs::IDs::inimigo):
					{

					}
					break;
					}
				}
			}
		}
	}
}