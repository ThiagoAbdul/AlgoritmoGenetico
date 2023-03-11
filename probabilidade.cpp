#include "probabilidade.h"
#include <random>

using namespace std;

random_device Probabilidade::rd;

int Probabilidade::rand_int_between(float start, float end){
	uniform_int_distribution<int> dist(start, end);
	return dist(rd);
}

float Probabilidade::rand_real_between(float start, float end){
	random_device rd;
	uniform_real_distribution<float> dist(start, end);
	return dist(rd);	
}

bool Probabilidade::rand_bool_with_probability(float probability){
	bernoulli_distribution dist(probability);
	return dist(rd);
}

bool Probabilidade::rand_bool(){
	return Probabilidade::rand_bool_with_probability(0.5);
}

