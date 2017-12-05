#pragma once
#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include <string>
using namespace std;

struct MenuSimples {
	string enunciado;
	string *opcoes;
	int quantidadeOpcoes;

	MenuSimples(string umEnunciado, string *vetorOpcoes, int umaQuantidadeOpcoes)
	{
		this->enunciado = umEnunciado;
		this->opcoes = vetorOpcoes;
		this->quantidadeOpcoes = umaQuantidadeOpcoes;
	}

	string exibirOpcao(int posicaoOpcao)
	{
		return this->opcoes[posicaoOpcao-1];
	}

	int aguardarAcaoUsuario()
	{
		int opcao;
		cin >> opcao;

		while (opcao < 1 || opcao > this->quantidadeOpcoes)
		{
			cout << "Opção inválida. Tente novamente:" << endl;
			cin >> opcao;
		}

		return opcao;
	}

	void exibirMenu()
	{
		cout << this->enunciado << endl << endl ;
		for (int i=0;i<quantidadeOpcoes; ++i)
		{
			cout << (i+1) << " - " << opcoes[i] << endl;
		}
	}
};

struct CampoDeTexto {
	string enunciado;
	string *subEnunciados;
	int quantidadeSubEnunciados;

	string* exibirCampoParaDigitacao() {
		cout << this->enunciado << endl;
		string *respostas = new string[this->quantidadeSubEnunciados];

		for (int i = 0; i < this->quantidadeSubEnunciados; ++i)
		{
			cout << (i + 1) << " - " << this->subEnunciados[i] << endl;
			cin >> respostas[i];
			cout << endl;
		}

		return respostas;
	}

	CampoDeTexto(string enunciado, string *subEnunciados, int quantidadeSubEnunciados){
		this->enunciado = enunciado;
		this->subEnunciados = subEnunciados;
		this->quantidadeSubEnunciados = quantidadeSubEnunciados;
	}
};

#endif // !MENUS_H

