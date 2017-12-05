#pragma once
#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>
#include <string>
using namespace std;

#define MASCULINO 'm'
#define FEMININO 'f'

struct Usuario {
	string nomeDeUsuario;
	string senha;
	string nomeCompleto;
	char genero;

	Usuario(string umNomeUsuario, string umaSenha, string confirmacaoSenha, string umNomeCompleto, const char umGenero) {
		
		/*if (umaSenha.length < 6){
			throw exception("A senha deve conter no mínimo 6 caracteres.");
		}*/
		
		if (umaSenha != confirmacaoSenha){
			throw exception("As senhas não coincidem.");
		}

		if (umGenero != MASCULINO && umGenero != FEMININO) {
			throw exception("Gênero inválido.");
		}
		
		this->nomeDeUsuario = umNomeUsuario;
		this->nomeCompleto = umNomeCompleto;
		this->senha = umaSenha;
		this->genero = umGenero;
	}
};

struct ElementoUsuario {
	Usuario *usuario;
	ElementoUsuario *proximoElemento;

	ElementoUsuario(Usuario *user) {
		this->usuario = user;
		this->proximoElemento = NULL;
	}
};

struct ListaUsuario {
	ElementoUsuario *primeiro;

	void inserirElemento(ElementoUsuario *elemento) {
		if (this->primeiro == NULL)
		{
			this->primeiro = elemento;
			return;
		}

		ElementoUsuario *temp = this->primeiro;
		do {

			if (temp->proximoElemento == NULL) {
				temp->proximoElemento = elemento;
				break;
			}

			temp = temp->proximoElemento;
		} while (temp != NULL);
	}

	int tamanho()
	{
		if (this->primeiro == NULL)
		{
			return 0;
		}

		ElementoUsuario *temp = this->primeiro;
		int contador = 0;
		do {
			contador++;

			temp = temp->proximoElemento;
		} while (temp != NULL);
		return contador;
	}

	void listarUsuarios()
	{
		if (this->primeiro != NULL)
		{
			ElementoUsuario *temp = this->primeiro;
			do {

				cout << "Nome de Usuário: " << temp->usuario->nomeDeUsuario << endl;
				cout << "Senha do Usuário: " << temp->usuario->senha << endl;
				cout << "Nome Completo: " << temp->usuario->nomeCompleto << endl;
				if (temp->usuario->genero == MASCULINO) {
					cout << "Gênero: Masculino" << endl;
				}
				else {
					cout << "Gênero: Feminino" << endl;
				}
				cout << endl;
				temp = temp->proximoElemento;
			} while (temp != NULL);
			cout << endl;
		}
	}

	ElementoUsuario* pegarElementoPorPosicao(int posicao)
	{
		if (this->primeiro == NULL)
		{
			return NULL;
		}

		ElementoUsuario *temp = this->primeiro;
		ElementoUsuario *elementoEscolhido = NULL;
		int contador = 0;

		do {
			contador++;
			if (contador == posicao)
			{
				elementoEscolhido = temp;
				break;
			}
			temp = temp->proximoElemento;
		} while (temp != NULL);
		return elementoEscolhido;
	}

	void deletarUsuario(int posicao)
	{
		if (this->primeiro == NULL)
		{
			return;
		}

		ElementoUsuario *temp = this->primeiro;
		int elementoAtual = 0;
		do {
			elementoAtual++;

			if (elementoAtual == posicao) {
				if (posicao == 1) {
					ElementoUsuario *novoElemento = this->primeiro->proximoElemento;

					//delete this->primeiro;
					//novoElemento->proximoElemento = this->primeiro->proximoElemento;
					this->primeiro = novoElemento;
				}
				else {
					ElementoUsuario *apontando = temp->proximoElemento;
					ElementoUsuario *anterior = this->pegarElementoPorPosicao(elementoAtual - 1);
					anterior->proximoElemento = apontando;
					delete &*temp;
				}
				break;
			}
			temp = temp->proximoElemento;
		} while (temp != NULL);
	}

	int pegarPosicaoPorNomeDeUsuario(string nomeUsuario)
	{
		if (this->primeiro == NULL)
		{
			return -1;
		}

		ElementoUsuario *temp = this->primeiro;
		int posicao = -1;
		int contador = 0;
		do {
			contador++;

			if (temp->usuario->nomeDeUsuario == nomeUsuario) {
				posicao = contador;
				break;
			}

			temp = temp->proximoElemento;
		} while (temp != NULL);

		return posicao;
	}

	Usuario* pegarUsuarioPorPosicao(int posicao)
	{

		if (posicao > this->tamanho() || posicao < 1)
		{
			throw exception("Posição inexistente.");
		}

		ElementoUsuario *temp = this->primeiro;
		Usuario *retorno = NULL;
		int posicaoAtual = 0;
		do {
			posicaoAtual++;
			if (posicaoAtual == posicao) {
				retorno = temp->usuario;
				break;
			}

			temp = temp->proximoElemento;
		} while (temp != NULL);

		return retorno;
	}

	ListaUsuario(ElementoUsuario *primeiroUsuario) {
		this->primeiro = primeiroUsuario;
	}

};

#endif // !USUARIOS_H
