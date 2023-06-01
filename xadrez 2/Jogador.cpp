#include "Jogador.h"
namespace Xadrez_2 {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				void Jogador::inicializa()
				{
					vel = Vector2f(0.1f, 0.1f);
					if (!this->textura.loadFromFile("../TEXTURAS/BRANCAS/cavaloB 78_130.png")) {
						cout << "Erro ao carregar a textura do cavalo\n";
					}
					textura.setSmooth(true);
					corpo.setTexture(&textura);
				}

				Jogador::Jogador(const Vector2f pos, const Vector2f tam, const float vel) :
					Personagem(pos, tam, vel, IDs::IDs::jogador)
				{
					corpo.setPosition(pos);
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
						corpo.move(0, -ds.y);
					}
					break;
					case(IDs::IDs::inimigo):
					{
						corpo.move(-ds.x, 0);
					}
					break;
					}
				}
			}
		}
	}
}