#pragma once
class DRBG
{
public:
	DRBG();
	~DRBG();

	void Instantiate(unsigned int entropy, unsigned int nonce, char* personString = nullptr, unsigned int stringLen = 0);
	void Reseed(unsigned int entropy, unsigned int input);

	unsigned int GenerateRandomInt(unsigned int input = 0);
	unsigned char GenerateRandomChar(unsigned int input = 0);

private:
	unsigned int Seed;
	unsigned int EntropyInput;
	unsigned int Counter;

	
};

