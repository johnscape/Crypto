#include "pch.h"
#include "PrimeGenerator.h"
#include <ctime>
#include <cstdlib>
#include "DRBG.h"

PrimeGenerator::PrimeGenerator()
{
	srand(time(0));
}


PrimeGenerator::~PrimeGenerator()
{
}

void PrimeGenerator::GeneratePrimes(unsigned int max_value)
{
	this->Primes.clear();
	this->Primes.push_back(2);
	for (size_t i = 3; i < max_value; i++)
	{
		bool isPrime = true;
		for (size_t j = 0; j < this->Primes.size(); j++)
		{
			if (i % Primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			this->Primes.push_back(i);
	}
}

unsigned int PrimeGenerator::GetRandomPrime(unsigned int min_value, unsigned int max_value)
{
	if (this->Primes.size() < 2)
		return 2;
	DRBG randGen;
	unsigned int selectedValue = 0;
	/*while ((min_value > 0 && selectedValue > min_value))
	{

	}*/
	randGen.Instantiate(rand(), this->Primes.size());
	unsigned int value = randGen.GenerateRandomInt();
	while (value > this->Primes.size())
		value -= this->Primes.size();
	return this->Primes[value];
}
