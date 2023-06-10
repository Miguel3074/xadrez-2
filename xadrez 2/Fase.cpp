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
			if (pEvento->getJogador1() == nullptr) {
				pEvento->setJogador1(jogador);
				listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(jogador));
			}
			else if (pEvento->getJogador2() == nullptr) {
				pEvento->setJogador2(jogador);
				listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(jogador));
			}
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

		void Fase::criaTeia(const Vector2f pos)
		{
			Entidade::Obstaculo::TeiaAranha* teia = new Entidade::Obstaculo::TeiaAranha(pos);
			if (teia == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um tabuleiro" << std::endl;
				exit(1);
			}
			Entidade::Obstaculo::TeiaAranha* o1 = static_cast<Entidade::Obstaculo::TeiaAranha*>(teia);
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(teia));
		}

		void Fase::criaTorre(const Vector2f pos)
		{

			Entidade::Personagem::Inimigo::Torre* torre = new Entidade::Personagem::Inimigo::Torre(pos);
			if (torre == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar uma Torre" << std::endl;
				exit(1);
			}
			listaEntidades.addEntidade(static_cast<Entidade::Entidade*>(torre));
		}

		void Fase::criaRainha(const Vector2f pos)
		{

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


			switch (letra)
			{
			case ('p'):
			{
				for (int i = 0; i < randQnty(); i++)
					criaPeao(randPos());
			}
			break;
			case('t'):
			{
				for (int i = 0; i < randQnty(); i++)
					criaTorre(randPos());
			}
			break;
			case('q'):
			{
				for (int i = 0; i < randQnty(); i++)
					criaRainha(randPos());
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
			case('T'):
			{
				for (int i = 0; i < randQnty(); i++)
					criaTeia(randPos());
			}
			break;
			}
		}
		Vector2f Fase::randPos()
		{

			//POSICAO ELEATORIAS
			Vector2i pos2;
			pos2.x = rand() % 1900;
			pos2.y = rand() % 1000;
			Vector2f posf = (Vector2f)pos2;
			return posf;
		}

		int Fase::randQnty()
		{
			int i;
			i = (rand() % 2) + 3;
			return i;
		}

		void Xadrez_2::Fase::Fase::setInstanciaJogo(Jogo* jogo)
		{
			this->instanciaJogo = jogo;
		}
	}
}