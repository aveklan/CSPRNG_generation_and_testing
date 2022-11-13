#include <cmath>
#include <iostream>

class BBS
{
private:
	unsigned long long p, q, n, x0, decryptionExp;

public:
	BBS();
	~BBS();
	BBS(unsigned long long p, unsigned long long q, unsigned long long seed);

	void setP(unsigned long long p);
	void setQ(unsigned long long q);
	void setSeed(unsigned long long seed);
	unsigned long long getRandBit();
	unsigned long long getRandNum();

	void setParams(unsigned long long p, unsigned long long q, unsigned long long seed);
};
