#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>
#include <string>

enum Nacionalidade{
	AFRICANO,
	AMERICANO,
	ASIATICO,
	BRASILEIRO,
	EUROPEU
};


class Humano{
	private:
		Nacionalidade nacionalidade;
		float altura, peso;
		int idade;

		void mutacaoNacionalidade();
		void mutacaoAltura(float);
		void mutacaoPeso(float);
		void mutacaoIdade(float);
		void sortear_mutacao(void (Humano::*)(float), float);
		void sortear_mutacao(void (Humano::*)());

	public:
		Humano();
		Humano(Nacionalidade n, float a, float p, int i) : nacionalidade{n}, altura{a}, peso{p}, idade{i} { }
		~Humano() { }
		std::string getNacionalidade();
		float getAltura(){ return altura; }
		float getPeso(){ return peso; }
		int getIdade(){ return idade; }
		Humano operator+(Humano&);
		void mutacao();
		void mutacao_leve();
		friend std::ostream& operator<<(std::ostream&, Humano&);
		friend float pontuar(Humano&); 
};

#endif