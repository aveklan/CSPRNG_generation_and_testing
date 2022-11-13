#include <cmath>
#include <iostream>

class TESTS
{
private:
    int *seq;
    int n;

public:
    TESTS();
    ~TESTS();
    TESTS(int *seq, int size);
    double monobitTest();
    double runsTest();
};
