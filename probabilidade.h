#ifndef PROBABILIDADE_H
#define PROBABILIDADE_H

#include <random>

using namespace std;

class Probabilidade{

	private:
		static random_device rd;

	public:
		static int rand_int_between(float start, float end);
		static float rand_real_between(float start, float end);
		static bool rand_bool_with_probability(float probability);
		static bool rand_bool();
};

#endif