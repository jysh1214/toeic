#include <iostream>
#include <chrono>

#include "problem.h"

using namespace std;

int TOTAL_NUMBER_OF_PROBLEMS = 64;

int main()
{
    Problem problem(TOTAL_NUMBER_OF_PROBLEMS);
    string myanswer;
    int number = 0;
    while (number < TOTAL_NUMBER_OF_PROBLEMS)
    {
        // show problem
        problem.showProblem(number);
        // input answer
        cin >> myanswer;
        problem.showResult(myanswer);
        number ++;
    } // main loop
    return 0;
}