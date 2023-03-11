#include "humano.h"
#include "probabilidade.h"
#include <iostream>
#include <iomanip>
#include <cmath>

#define TOTAL_NACIONALIDADES 5

using namespace std;

Humano::Humano(){
	Nacionalidade n = (Nacionalidade) Probabilidade::rand_int_between(0, 4);
	float a = Probabilidade::rand_real_between(1.40, 2.10);
	float p = Probabilidade::rand_real_between(40, 120);
	int i = Probabilidade::rand_int_between(10, 80);
	*this = Humano{n, a, p, i};
}

Humano Humano::operator+(Humano& humano){
	Nacionalidade n = (Probabilidade::rand_bool())? this->nacionalidade : humano.nacionalidade;
	float a = (Probabilidade::rand_bool())? this->altura : humano.altura;
	float p = (Probabilidade::rand_bool())? this->peso : humano.peso;
	int i = (Probabilidade::rand_bool())? this->idade : humano.idade;
	return Humano{n, a, p, i};
}

string Humano::getNacionalidade(){
	switch(nacionalidade){
		case AFRICANO: return "Africano";
		case AMERICANO: return "Americano";
		case ASIATICO: return "Asiatico";
		case BRASILEIRO: return "Brasileiro";
		default: return "Europeu";
	}
}

void Humano::mutacaoNacionalidade(){
	Nacionalidade n = this->nacionalidade;
	int num = Probabilidade::rand_int_between(0, 12);
	if (num < TOTAL_NACIONALIDADES){
		this->nacionalidade = (Nacionalidade) num; 
	} 
}

void Humano::mutacaoAltura(float variacao){
	altura += Probabilidade::rand_real_between(-variacao, variacao);
}

void Humano::mutacaoPeso(float variacao){
	peso += Probabilidade::rand_real_between(-variacao, variacao);
}

void Humano::mutacaoIdade(float variacao){
	idade += Probabilidade::rand_int_between(-variacao, variacao);
}

void Humano::sortear_mutacao(void (Humano::*func_mutacao)(float), float variacao){
  	int vai_mutar = Probabilidade::rand_bool_with_probability(0.4);
  	if(vai_mutar){
  		(this->*func_mutacao)(variacao);
  	}
}

void Humano::sortear_mutacao(void (Humano::*func_mutacao)()){
  	
  	int vai_mutar = Probabilidade::rand_bool_with_probability(0.25);
  	if(vai_mutar){
  		(this->*func_mutacao)();
  	}
}

void Humano::mutacao(){
	sortear_mutacao(&Humano::mutacaoNacionalidade);
	sortear_mutacao(&Humano::mutacaoAltura, 0.08);
	sortear_mutacao(&Humano::mutacaoPeso, 4);
	sortear_mutacao(&Humano::mutacaoIdade, 4);
}

void Humano::mutacao_leve(){
		sortear_mutacao(&Humano::mutacaoNacionalidade);
		sortear_mutacao(&Humano::mutacaoAltura, 0.04);
		sortear_mutacao(&Humano::mutacaoPeso, 2);
		sortear_mutacao(&Humano::mutacaoIdade, 2);
}

ostream& operator<<(ostream& out, Humano& humano) {
	return out << humano.getNacionalidade() << endl << setprecision(3) << humano.altura << endl << humano.peso << endl << humano.idade; 
}

const Humano HUMANO_PERFEITO{BRASILEIRO, 1.79, 65.5, 22};

float pontuar(Humano& humano){
	unsigned short diferenca_nacionalidade = (humano.nacionalidade == HUMANO_PERFEITO.nacionalidade)? 0 : 20; 
	float diferenca_altura = round(abs((humano.altura - HUMANO_PERFEITO.altura) * 100));
	float diferenca_peso = round(abs(humano.peso - HUMANO_PERFEITO.peso) * 10) / 10;
	float diferenca_idade = abs(humano.idade - HUMANO_PERFEITO.idade);
	float total_diferenca = diferenca_nacionalidade + diferenca_altura + diferenca_peso + diferenca_idade;
	return 	250 - total_diferenca;
}

