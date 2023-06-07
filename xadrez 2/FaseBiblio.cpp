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
			listaEntidades.limparLista();
			string linha;
			mapa1txt.open("FaseBiblioMapa.txt");
			if (!mapa1txt.is_open()) {
				cout << "nao foi possivel abrir o arquivo" << endl;
				exit(1);
			}
			int j = 0;
			while (getline(mapa1txt, linha)) { //CRIA O MAPA PELO ARQUIVO TXT SENDO UM CARACTER POR ENTIDADE
				for (int i = 0; i < linha.size(); i++) {
					if (linha[i] != ' ') {
						criarEntidade(linha[i], Vector2i(i, j));
					}
				}
				j++;
			}
			mapa1txt.close();
		}
	}
}