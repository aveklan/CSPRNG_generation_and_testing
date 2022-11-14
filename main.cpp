#include "bbs.h"
#include "tests.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <windows.h>

using namespace std;

int seedCaluclation(int N);

int main()
{
    const int P = 18899;
    const int Q = 20023;
    const int N = P * Q;
    int iterations = 100000;

    int Blum_Blum_Shub[iterations];
    int stdRandom[iterations];

    int BlumNotPassedM = 0;
    int stdRandomNotPassedM = 0;
    int BlumNotPassedR = 0;
    int stdRandomNotPassedR = 0;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int seed = 0;

        seed = seedCaluclation(N);

        BBS numberGen(P, Q, seed);

        // Generating a random sequence of bit using Blum Blum Shub algorithm
        for (int i = 0; i < iterations; i++)
            Blum_Blum_Shub[i] = numberGen.getRandBit();

        // Generating a random sequence of bit using c++ rand() function
        for (int i = 0; i < iterations; i++)
            stdRandom[i] = rand() % 2;

        // Running tests on Blum Blum Shub generated sequence
        TESTS blumSequence(Blum_Blum_Shub, iterations);
        if (blumSequence.monobitTest() < 0.01)
            BlumNotPassedM++;

        if (blumSequence.runsTest() < 0.01)
            BlumNotPassedR++;

        // Running tests on c++ rand() generated sequence
        TESTS stdSequence(stdRandom, iterations);

        if (stdSequence.monobitTest() < 0.01)
            stdRandomNotPassedM++;

        if (stdSequence.runsTest() < 0.01)
            stdRandomNotPassedR++;
    }

    cout << "Blum Blum Shub algorithm tests failed: " << endl
         << "Monobit: " << BlumNotPassedM << endl
         << "RunsTest: " << BlumNotPassedR << endl;
    cout << "c++ rand() tests failed: " << endl
         << "Monobit: " << stdRandomNotPassedM << endl
         << "RunsTest: " << stdRandomNotPassedR << endl;
    return 0;
}

int seedCaluclation(int N)
{
    int seed = rand() % N;

    while (__gcd(seed, N) != 1)
    {
        seed = rand() % N;
    }

    return seed;
}
