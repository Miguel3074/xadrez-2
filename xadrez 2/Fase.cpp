#include "Fase.h"


namespace Xadrez_2 {

	namespace Fase {
		Fase::Fase(IDs::IDs ID_fase) :
			Ente(ID_fase), listaEntidades(), instanciaJogo(nullptr),
			pColisao(new Gerenciador::GerenciadorColisao(&listaEntidades)),
			pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
			pEvento(pEvento->getGerenciadorEvento()),
			gravidade(0.007f)
		{
			if (pColisao == nullptr) {
				cout << "Erro ao criar gerenciador de colisao" << endl;
				exit(1);
			}
		}

		Fase::~Fase()
		{
			if (pColisao) {
				delete(pColisao);
				pColisao = nullptr;
			}
		}

		void Fase::criaPeao(const Vector2f pos)
		{
			cout << pos.x <<"  "<< pos.y<<endl;
			Entidade::Personagem::Inimigo::Inimigo* peao = new Entidade::Personagem::Inimigo::Peao(pos);
			if (peao == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Peao" << std::endl;
				exit(1);
			}
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(peao));
		}

		void Fase::criaJogador(const Vector2f pos)
		{
			Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos);
			if (jogador == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
				exit(1);
			}
			Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
			pEvento->setJogador(jogador);
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(jogador));
		}

		void Fase::criaTabuleiro(const Vector2f pos)
		{
			Entidade::Obstaculo::Tabuleiro* tabuleiro = new Entidade::Obstaculo::Tabuleiro(pos);

			if (tabuleiro == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um tabuleiro" << std::endl;
				exit(1);
			}
			Entidade::Obstaculo::Tabuleiro* o1 = static_cast<Entidade::Obstaculo::Tabuleiro*>(tabuleiro);
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(tabuleiro));
		}

		void Fase::criaTorre(const Vector2f pos)
		{
			cout << pos.x <<"  "<< pos.y<<endl;
			Entidade::Personagem::Inimigo::Torre* torre = new Entidade::Personagem::Inimigo::Torre(pos);
			if (torre == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar uma Torre" << std::endl;
				exit(1);
			}
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(torre));
		}

		void Fase::criaRainha(const Vector2f pos)
		{
			cout << pos.x <<"  "<< pos.y<<endl;
			Entidade::Personagem::Inimigo::Rainha* rainha = new Entidade::Personagem::Inimigo::Rainha(pos);
			if (rainha == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar uma Torre" << std::endl;
				exit(1);
			}
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(rainha));
		}

		void Fase::criarEntidade(char letra, const Vector2i pos)
		{
			Vector2f posAux = Vector2f(pos.x * 75.f, pos.y * 75.f);
			srand(time(NULL));
			switch (letra)
			{
			case ('p'):
			{
				criaPeao(Vector2f(rand() % 1920, rand() % 1080));
			}
			break;
			case('t'):
			{
				criaTorre(Vector2f(rand() % 1920, rand() % 1080));
			}
			break;
			case('q'):
			{
				criaRainha(Vector2f(rand() % 1920, rand() % 1080));
			}
			break;
			case('j'):
			{
				criaJogador(posAux);
			}
			break;
			case('#'):
			{
				criaTabuleiro(posAux);
			}
			break;
			}
		}

		void Xadrez_2::Fase::Fase::setInstanciaJogo(Jogo* jogo) { this->instanciaJogo = jogo; }
	}
}