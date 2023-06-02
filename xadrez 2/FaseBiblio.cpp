#include "FaseBiblio.h"
namespace Xadrez_2 {
	namespace Fase {
		FaseBiblio::FaseBiblio() :
			Fase(IDs::IDs::fase1)
		{
		}
		FaseBiblio::~FaseBiblio()
		{
		}
		void FaseBiblio::criarMapa()
		{
			ifstream arquivo;
			string linha;
			arquivo.open("FaseBiblioMapa.txt");
			if (!arquivo.is_open()) {
				cout << "nao foi possivel abrir o arquivo" << endl;
				exit(1);
			}
			int j = 0;
			while (getline(arquivo, linha)) {//CRIA O MAPA PELO ARQUIVO TXT SENDO UM CARACTER POR ENTIDADE
				for (int i = 0; i < linha.size(); i++) {
					if (linha[i] != ' ') {
						criarEntidade(linha[i], Vector2i(i, j));
					}
				}
				j++;
			}
			arquivo.close();
		}
	}
}