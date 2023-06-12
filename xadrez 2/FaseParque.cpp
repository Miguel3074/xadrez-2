#include "FaseParque.h"

namespace Xadrez_2 {
	namespace Fases {
		FaseParque::FaseParque() :
			Fase(IDs::fase2)
		{
			
		}
		FaseParque::~FaseParque()
		{
		}
		void FaseParque::criarMapa()
		{
			faseAtual = 2;
			if (!faseFinal)
				pontuacaoAtual = 0;
			if (pColisao)
				delete(pColisao);
			pColisao = new Gerenciadores::GerenciadorColisao();

			if (!pColisao) {
				cout << "Erro ao criar gerenciador de colisao" << endl;
				exit(1);
			}

			listaEntidades.limparLista();
			if (!texturaFundo.loadFromFile("../TEXTURAS/fundo2.jpg"))
			{
				cout << "Erro na textura do fundo do mapaBilbio.\n";
			}
			texturaFundo.setSmooth(true);
			fundo.setTexture(texturaFundo);

			string linha;
			mapa2txt.open("FaseParqueMapa.txt");
			if (!mapa2txt.is_open()) {
				cout << "nao foi possivel abrir o arquivo" << endl;
				exit(1);
			}
			int j = 0;
			while (getline(mapa2txt, linha)) { //CRIA O MAPA PELO ARQUIVO TXT SENDO UM CARACTER POR ENTIDADE
				for (int i = 0; i < linha.size(); i++) {
					if (linha[i] != ' ') {
						criarEntidade(linha[i], Vector2i(i, j));
					}
				}
				j++;
			}
			mapa2txt.close();
		}
		void FaseParque::executar()
		{
			Fase::executar();
		}
	}
}



