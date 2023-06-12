#pragma once

#include "Fase.h"

namespace Xadrez_2 {
	class Jogo;
	class Menu : public Ente
	{
	private:

		class Perfil
		{
		private:
			string nome;
			unsigned int pontuacao;
		public:
			Perfil();
			~Perfil();

			void setNome(string nome);
			void setPontuacao(unsigned int pontuacao);

			string getNome();
			unsigned int getPontuacao();
		};
		//placeholders
		Font fonte;
		Text fase1, fase2, pontos, sair, selecao, jogadorPerfil;
		vector<Perfil*> perfis;
		Perfil* perfilAtual;
		bool menuPerfil;
		//deve ter um nome pra um padrão de projeto que assiste o estado desse objeto, mas eu esqueci
		int menuOpcao;
		Jogo* instanciaJogo;

		void organizarPerfis();
		void rankings();
		void menuPerfis();
		void criarPerfil();

	public:
		Menu();
		~Menu();

		void setInstanciaJogo(Jogo* jogo) { this->instanciaJogo = jogo; }

		void menuInicial();

		void executar();
	};
}