#include <iostream>
#include <chrono>
#include <limits>

#include "problem.h"

using namespace std;

int TOTAL_NUMBER_OF_PROBLEMS = 19;

int main()
{
    Problem problem(TOTAL_NUMBER_OF_PROBLEMS);
    string myanswer;
    while (1)
    {
        // show problem
        problem.showProblem();
        // input answer
        cin >> myanswer;
        problem.showResult(myanswer);
    } // main loop
    return 0;
}