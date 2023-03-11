#include "humano.h"
#include <iostream>
#include <random>

#define MAX_SIZE 100
#define META 250

using namespace std;


/*
	Humano perfeito:
		Nacionalidade: Brasileiro
		Altura: 1.79
		Peso: 65.5
		Idade: 22
		Nome: Thiago Abdul kkkkkkk
*/

int main(){
	Humano humanos[MAX_SIZE];
	Humano* primeiro_colocado = &humanos[0];
	Humano* segundo_colocado = &humanos[1];
	float pontuacao_primeiro = pontuar(*primeiro_colocado), 
		  pontuacao_segundo = pontuar(*segundo_colocado), 
		  pontuacao_atual = pontuacao_segundo;

	if(pontuacao_segundo > pontuacao_primeiro){
		pontuacao_segundo = pontuacao_primeiro;
		pontuacao_primeiro = pontuacao_atual;
		Humano swap = *segundo_colocado;
		segundo_colocado = primeiro_colocado;
		primeiro_colocado = &swap;
	}

	cout << "Evolução" << endl;
	while(pontuacao_primeiro < META){
		cout << "----------------" << endl << *primeiro_colocado << endl;
		for (int i = 2; i < MAX_SIZE; i++){
			pontuacao_atual = pontuar(humanos[i]);
			if(pontuacao_atual > pontuacao_primeiro){
				pontuacao_segundo = pontuacao_primeiro;
				pontuacao_primeiro = pontuacao_atual;
				segundo_colocado = primeiro_colocado;
				primeiro_colocado = &humanos[i];
			}
			else if(pontuacao_atual > pontuacao_segundo){
				pontuacao_segundo = pontuacao_atual;
				segundo_colocado = &humanos[i];
			}
		}

		humanos[0] = *primeiro_colocado;
		humanos[1] = *segundo_colocado;
		primeiro_colocado = &humanos[0];
		segundo_colocado = &humanos[1];

		if(pontuacao_primeiro > 240){
			for (int i = 2; i < MAX_SIZE; i++){
				humanos[i] = (*primeiro_colocado) + (*segundo_colocado);
				humanos[i].mutacao_leve();
			}
		}
		else{
			for (int i = 2; i < MAX_SIZE; i++){
				humanos[i] = (*primeiro_colocado) + (*segundo_colocado);
				humanos[i].mutacao();
			}
		}
	}
	

	cout << "----------------" << endl << *primeiro_colocado << endl;

	return 0;
}
