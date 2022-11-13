#include "tests.h"
#include "math.h"
#include <iostream>

int counter(int *seq, int n);
int countOnes(int *seq, int n);
double countVobs(int *seq, int n);

TESTS::TESTS()
{
    this->seq = NULL;
}

TESTS::TESTS(int *seq, int size)
{
    this->seq = seq;
    this->n = size;
}

double TESTS::monobitTest()
{
    int Sn = counter(seq, n);
    long double Sobs = abs(Sn) / sqrt(n);
    long double Pvalue = erfc(Sobs / sqrt(2));
    return Pvalue;
}

double TESTS::runsTest()
{
    double Sn = countOnes(seq, n);
    double pi = Sn / n;

    if ((pi - 0.5) >= monobitTest())
        return 0.0;

    double Vobs = countVobs(seq, n);
    double Pvalue = erfc(fabs((Vobs - 2 * n * pi * (1 - pi))) / (2 * sqrt(2 * n) * pi * (1 - pi)));
    return Pvalue;
}

TESTS::~TESTS() {}

int counter(int *seq, int n)
{
    int Sn = 0;
    for (int i = 0; i < n; i++)
        if (seq[i] == 0)
            Sn--;
        else
            Sn++;

    return Sn;
}

int countOnes(int *seq, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (seq[i] == 1)
            count++;

    return count;
}

double countVobs(int *seq, int n)
{
    double count = 0;
    for (int i = 0; i < n - 1; i++)
        if (seq[i] != seq[i + 1])
            count++;

    if (seq[n - 1] != seq[n])
        count++;
    return count;
}