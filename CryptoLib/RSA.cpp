#include "pch.h"
#include "RSA.h"
#include "PrimeGenerator.h"

RSA::RSA()
{
}


RSA::~RSA()
{
}

void RSA::GenerateKeys()
{
	PrimeGenerator primes;
	primes.GeneratePrimes(500000);
	this->Q = primes.GetRandomPrime();
	this->P = primes.GetRandomPrime();

	this->N = this->P * this->Q;

	this->Lambda = (this->Q - 1) * (this->P - 1);
	for (unsigned long long int i = this->Lambda; i > 0; i--)
	{
		if (i % (this->Q - 1) == 0 && i % (this->P - 1) == 0)
			this->Lambda = i;
		if (i < this->Q - 1 || i < this->P - 1)
			break;
	}

	unsigned char count = 0;

	for (unsigned long long i = this->Lambda; i > 0; i--)
	{
		if (GCD(i, this->Lambda) == 1)
		{
			count++;
			if (count == 3)
			{
				this->E = i;
				break;
			}
		}
	}

	//calc D

	this->D = 1;

	while ((this->E * this->D) % this->Lambda != 1)
		this->D++;
}

unsigned int RSA::GCD(unsigned long long int a, unsigned long long int b)
{
	unsigned int gcd = 1;
	for (long long int i = 1; i < a > b ? b : a; i++)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}
	return gcd;
}
