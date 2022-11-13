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

    int BlumNotPassed = 0;
    int stdRandomNotPassed = 0;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int seed = 0;

        seed = seedCaluclation(N);
        // cout << "Calculated seed: " << seed << endl; // gcd(6,20) for C++17

        BBS numberGen(P, Q, seed);

        // cout << "Generating a random sequence of bit using Blum Blum Shub algorithm ..." << endl;
        for (int i = 0; i < iterations; i++)
            Blum_Blum_Shub[i] = numberGen.getRandBit();

        // cout << "Generating a random sequence of bit using c++ rand() function ..." << endl;
        for (int i = 0; i < iterations; i++)
            stdRandom[i] = rand() % 2;

        // int prova[100] = {1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0};

        // cout << "Running tests on Blum Blum Shub generated sequence ..." << endl;
        TESTS blumSequence(Blum_Blum_Shub, iterations);
        if (blumSequence.monobitTest() < 0.01)
            BlumNotPassed++;

        if (blumSequence.runsTest() < 0.01)
            BlumNotPassed++;

        // cout << "Running tests on c++ rand() generated sequence ..." << endl;
        TESTS stdSequence(stdRandom, iterations);

        if (stdSequence.monobitTest() < 0.01)
            stdRandomNotPassed++;

        if (stdSequence.runsTest() < 0.01)
            stdRandomNotPassed++;
    }

    cout << "Blum Blum Shub algorithm tests failed: " << BlumNotPassed << endl;
    cout << "c++ rand() tests failed: " << stdRandomNotPassed << endl;
    // int prova[100] = {1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0};
    //  int prova[10] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
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
