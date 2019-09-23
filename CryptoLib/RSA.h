#pragma once
class RSA
{
public:
	RSA();
	~RSA();

	void GenerateKeys();

private:
	unsigned int P;
	unsigned int Q;
	unsigned long long int N;
	unsigned long long int Lambda;
	unsigned int E;
	unsigned int D;

	unsigned int GCD(unsigned long long int a, unsigned long long int b);
};

