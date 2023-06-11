#include "Jogador.h"
namespace Xadrez_2 {
	namespace Entidades {
		namespace Personagens {

			void Jogador::inicializa()
			{
				if (!this->textura.loadFromFile("../TEXTURAS/BRANCAS/cavaloB 78_130.png")) {
					cout << "Erro ao carregar a textura do cavalo\n";
				}
				textura.setSmooth(true);
				corpo.setTexture(&textura);
			}

			Jogador::Jogador(const Vector2f pos) :
				Personagem(pos, Vector2f(78.0f, 130.0f), Vector2f(0.1f, 0.0f), IDs::jogador),
				estaNoAr(false)
			{
				corpo.setPosition(pos);
				inicializa();
			}

			Jogador::~Jogador()
			{
			}

			void Jogador::executar()
			{
				setPos(corpo.getPosition());
				if (podeAndar) {
					atualizarPosicao();
				}
				else
				{
					vel.x = 0.f;
				}

				corpo.move(0.0f, -vel.y);
				vel.y = vel.y - gravidade;
				relogio.restart();

			}
			void Jogador::colisao(Entidade* outraentidade, Vector2f ds)
			{
				switch (outraentidade->getId())
				{
				case(IDs::tabuleiro):
				{

				}
				break;
				case(IDs::peao):
				{

				}
				break;
				}
			}
			void Jogador::atualizarPosicao()
			{
				dt = relogio.getElapsedTime().asSeconds();
				float ds = 1000 * dt; //MRU
				vel.x = ds;
				if (dirEsquerda) {
					ds *= -1;
				}
				corpo.move(ds, 0.0f);
				if (corpo.getPosition().x < (1920.f - tam.x) && corpo.getPosition().x > 0.f) {
					corpo.move(ds, 0.0f);
				}
				else if (corpo.getPosition().x <= 0.f) {
					corpo.setPosition(Vector2f(0.1f, corpo.getPosition().y));
				}
				else if (corpo.getPosition().x >= (1920.f - tam.x)) {
					corpo.setPosition(Vector2f(1919.f - tam.x, corpo.getPosition().y));
				}
			}
		}
	}
}