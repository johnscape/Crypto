#pragma once
#include "DRBG.h"

class DiffieHellman
{
public:
	DiffieHellman();
	~DiffieHellman();

	void GenerateKey();
	void CreateHostedKey(DiffieHellman* other);
	size_t GetKey();

private:
	size_t ChoosenNumber;
	size_t Key;
	size_t HostedKey;
	DRBG* RandomGenerator;
};

