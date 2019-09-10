#pragma once
#include <vector>
class PrimeGenerator
{
public:
	PrimeGenerator();
	~PrimeGenerator();

	void GeneratePrimes(unsigned int max_value);
	unsigned int GetRandomPrime(unsigned int min_value = 0, unsigned int max_value = 0);

private:
	std::vector<unsigned int> Primes;
};

