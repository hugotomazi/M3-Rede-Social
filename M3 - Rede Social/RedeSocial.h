#pragma once
#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include <iostream>
#include <string>
#include "Menus.h"
#include "Usuarios.h"
using namespace std;

void exibirMenuValidacaoUsuario(ListaUsuario *&baseDeDados)
{
	string *respostas = new string[5];
	string *subEnunciados = new string[5];
	subEnunciados[0] = "Nome de Usuário:";
	subEnunciados[1] = "Senha:";
	subEnunciados[2] = "Confirmação de Senha:";
	subEnunciados[3] = "Nome Completo:";
	subEnunciados[4] = "Gênero (Informe M para Masculino e F para Feminino):";
	char genero;

	CampoDeTexto *menuTextual = new CampoDeTexto("Informe abaixo as informações requeridas para a criação de um novo usuário:", subEnunciados, 5);
	respostas = menuTextual->exibirCampoParaDigitacao();

	if (baseDeDados->tamanho() == 1)
	{

	}
}

void exibirMenuSecundario()
{
	string *opcoes = new string[3];
	opcoes[0] = "Entrar.";
	opcoes[1] = "Cadastrar Usuario.";
	opcoes[2] = "Fechar o Programa.";
	MenuSimples *menuSecundario = new MenuSimples("O que deseja fazer?", opcoes, 3);

	Usuario *usuarioFake = new Usuario("null", "null", "null", "null", MASCULINO);
	ElementoUsuario *elementoFake = new ElementoUsuario(usuarioFake);
	ListaUsuario *baseDeDadosUsuarios = new ListaUsuario(elementoFake);

	int opcaoUsuario;
	menuSecundario->exibirMenu();
	opcaoUsuario = menuSecundario->aguardarAcaoUsuario();

	if (opcaoUsuario == 1) {
		exibirMenuValidacaoUsuario(baseDeDadosUsuarios);
	}
	else if (opcaoUsuario == 2) {

	}
	else {
		cout << "Até a próxima!" << endl;
	}
}

void exibirMenuPrincipal()
{
	string *opcoesMenu = new string[2];
	opcoesMenu[0] = "Inicializar sistema com base nova.";
	opcoesMenu[1] = "Inicializar sistema com base pré-carregada.";

	MenuSimples *menu = new MenuSimples("Bem-Vindo a M3 Rede Social!\nO que deseja fazer?", opcoesMenu, 2);

	int opcaoUsuario;
	menu->exibirMenu();
	opcaoUsuario = menu->aguardarAcaoUsuario();

	//delete &*menu;

	if (opcaoUsuario == 1)
	{
		exibirMenuSecundario();
	}
	else {
		cout << "Esta Opção não está Disponível no momento." << endl;
	}
}


void inicializarRedeSocial()
{
	exibirMenuPrincipal();
}

#endif // !REDESOCIAL_H

