#include "Fase.h"


namespace Xadrez_2 {
	namespace Fases {
		Fase::Fase(IDs ID_fase) :
			Ente(ID_fase), listaEntidades(), instanciaJogo(nullptr),
			pColisao(nullptr),
			pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
			pEvento(pEvento->getGerenciadorEvento()),
			gravidade(0.007f)
		{
			/*if (pColisao == nullptr) {
				cout << "Erro ao criar gerenciador de colisao" << endl;
				exit(1);
			}*/
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

			Entidades::Personagens::Inimigo* peao = new Entidades::Personagens::Peao(pos);
			if (peao == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Peao" << std::endl;
				exit(1);
			}
			pColisao->incluirInimigo(peao);
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(peao), gravidade);
		}

		void Fase::criaJogador(const Vector2f pos)
		{
			Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(pos);
			if (jogador == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
				exit(1);
			}
			Gerenciadores::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
			if (pEvento->getJogador1() == nullptr) {
				pEvento->setJogador1(jogador);
				pColisao->definirJogador1(jogador);
				listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(jogador), gravidade);
			}
			else if (pEvento->getJogador2() == nullptr) {
				pEvento->setJogador2(jogador);
				pColisao->definirJogador2(jogador);
				listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(jogador), gravidade);
			}
		}

		void Fase::criaTabuleiro(const Vector2f pos)
		{
			Entidades::Obstaculos::Tabuleiro* tabuleiro = new Entidades::Obstaculos::Tabuleiro(pos);
			if (tabuleiro == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um tabuleiro" << std::endl;
				exit(1);
			}
			pColisao->incluirObstaculo(tabuleiro);
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(tabuleiro), gravidade);
		}

		void Fase::criaTeia(const Vector2f pos)
		{
			Entidades::Obstaculos::TeiaAranha* teia = new Entidades::Obstaculos::TeiaAranha(pos);
			if (teia == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar um tabuleiro" << std::endl;
				exit(1);
			}
			pColisao->incluirObstaculo(teia);
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(teia), gravidade);
		}

		void Fase::criaTorre(const Vector2f pos)
		{

			Entidades::Personagens::Torre* torre = new Entidades::Personagens::Torre(pos);
			if (torre == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar uma Torre" << std::endl;
				exit(1);
			}
			pColisao->incluirInimigo(torre);
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(torre), gravidade);
			pColisao->incluirFlecha(torre->getFlecha());
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(torre->getFlecha()), gravidade);
		}

		void Fase::criaRainha(const Vector2f pos)
		{

			Entidades::Personagens::Rainha* rainha = new Entidades::Personagens::Rainha(pos);
			if (rainha == nullptr) {
				std::cout << "Construtor::ConstrutorFase::nao foi possivel criar uma Torre" << std::endl;
				exit(1);
			}
			pColisao->incluirInimigo(rainha);
			listaEntidades.addEntidade(static_cast<Entidades::Entidade*>(rainha), gravidade);

			rainha->setJogadores(pColisao->getJogador1(), pColisao->getJogador2());
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
			pos2.x = (rand() % 1600) + 300.f;
			pos2.y = rand() % 1000;
			Vector2f posf = (Vector2f)pos2;
			return posf;
		}

		int Fase::randQnty()
		{
			int i;
			i = (rand() % 3) + 3;
			return i;
		}

		void Fase::setInstanciaJogo(Jogo* jogo)
		{
			this->instanciaJogo = jogo;
		}

		void Fase::executar()
		{
			pGerenciadorGrafico->getGerenciadorGrafico()->desenharSprite(fundo);
			listaEntidades.executar(pGerenciadorGrafico->getJanela());
			pColisao->executar();
			pEvento->executar();
		}
	}
}