#include "pch.h"
#include "DRBG.h"
#include "BitOperations.h"
#include <ctime>
#include <cstdlib>

#define MAX_COUNT 30

DRBG::DRBG()
{
	srand(time(0));
	this->Counter = 0;
}


DRBG::~DRBG()
{
}

void DRBG::Instantiate(unsigned int entropy, unsigned int nonce, char * personString, unsigned int stringLen)
{
	unsigned int temp = (BitOperations::IntLeftShift(entropy, nonce)) ^ entropy;
	if (stringLen > 0)
	{
		unsigned int counter = 0;
		BitOperations::CharToInt converter;
		while (counter < stringLen)
		{
			for (unsigned char i = 0; i < 4; i++)
			{
				if (counter < stringLen)
				{
					converter.chars[i] = personString[counter];
					counter++;
				}
				else
					converter.chars[i] = 0;
			}

			temp = temp ^ converter.number;
		}
	}

	this->Seed = temp;
	
}

void DRBG::Reseed(unsigned int entropy, unsigned int input)
{
	this->Seed = (this->Seed ^ entropy) ^ input;
}

unsigned int DRBG::GenerateRandomInt(unsigned int input)
{
	this->Counter++;
	if (this->Counter > MAX_COUNT)
	{
		Reseed(rand(), rand());
		this->Counter = 0;
	}
	return (this->Seed ^ BitOperations::IntRightShift(this->Seed, 15)) ^ input;
}

unsigned char DRBG::GenerateRandomChar(unsigned int input)
{
	this->Counter++;
	if (this->Counter > MAX_COUNT)
	{
		Reseed(rand(), rand());
		this->Counter = 0;
	}
	BitOperations::CharToInt converter;
	converter.number = (this->Seed ^ BitOperations::IntRightShift(this->Seed, 15)) ^ input;
	return converter.chars[1];
}
