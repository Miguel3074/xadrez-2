#include "FaseParque.h"
namespace Xadrez_2 {
	namespace Fase {
		FaseParque::FaseParque() :
			Fase(IDs::IDs::fase2)
		{
		}
		FaseParque::~FaseParque()
		{
		}
		void FaseParque::criarMapa()
		{
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
	}
}