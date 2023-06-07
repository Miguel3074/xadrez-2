#include "Fase.h"


namespace Xadrez_2 {

	namespace Fase {
		Fase::Fase(IDs::IDs ID_fase) :
			Ente(ID_fase), listaEntidades(),
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
				pColisao == nullptr;
			}
		}

		void Fase::criaPeao(const Vector2f pos)
		{
			Entidade::Personagem::Inimigo::Inimigo* inimigo = new Entidade::Personagem::Inimigo::Peao(pos);
			if (inimigo == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Peao" << std::endl;
				exit(1);
			}
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(inimigo));
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
			/*Entidade::Personagem::Inimigo::Peao* Peao = new Entidade::Personagem::Inimigo::Peao(pos, pJogador);
			if (Peao == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Peao" << std::endl;
				exit(1);
			}
			return static_cast<Entidade::Entidade*>(Peao);*/
		}

		void Fase::criaRainha(const Vector2f pos)
		{
			/*Entidade::Personagem::Inimigo::Peao* Peao = new Entidade::Personagem::Inimigo::Peao(pos, pJogador);
			if (Peao == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Peao" << std::endl;
				exit(1);
			}
			return static_cast<Entidade::Entidade*>(Peao);*/
		}

		void Fase::criarEntidade(char letra, const Vector2i pos)
		{
			Vector2f posAux = Vector2f(pos.x * 75, pos.y * 75);
			switch (letra)
			{
			case ('p'):
			{
				criaPeao(posAux);
			}
			break;
			case('t'):
			{
				criaTorre(posAux);
			}
			break;
			case('ra'):
			{
				criaRainha(posAux);
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
	}
}