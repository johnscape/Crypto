#include "pch.h"
#include "DiffieHellman.h"
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <limits>
#include "BitOperations.h"

#define GFA 242789
#define GF 630169

#define FAST_MODE true



DiffieHellman::DiffieHellman()
{
	srand(time(0));
	this->Key = 0;
	this->RandomGenerator = new DRBG();
	this->RandomGenerator->Instantiate(rand(), rand(), (char*)"diffie", 6);
	if (FAST_MODE)
	{
		BitOperations::CharToInt converter;
		converter.chars[0] = this->RandomGenerator->GenerateRandomChar();
		converter.chars[1] = this->RandomGenerator->GenerateRandomChar();
		converter.chars[2] = 0;
		converter.chars[3] = 0;
		this->ChoosenNumber = converter.number;
	}
	else
		this->ChoosenNumber = this->RandomGenerator->GenerateRandomInt();
}


DiffieHellman::~DiffieHellman()
{
	delete this->RandomGenerator;
}

void DiffieHellman::GenerateKey()
{
	unsigned long long int temp = GFA;
	for (unsigned int i = 1; i < this->ChoosenNumber; i++)
	{
		temp *= GFA;
		while (temp > GF)
			temp -= GF;
	}

	this->Key = temp; //because the GF's value can be stored inside a size_t, the temp's value can be stored too

}

void DiffieHellman::CreateHostedKey(DiffieHellman * other)
{
	unsigned long long int temp = other->GetKey();
	size_t originalKey = other->GetKey();
	for (unsigned int i = 1; i < this->ChoosenNumber; i++)
	{
		temp *= originalKey;
		while (temp > GF)
			temp -= GF;
	}

	this->HostedKey = temp;
}

size_t DiffieHellman::GetKey()
{
	return this->Key;
}
