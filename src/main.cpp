#include <iostream>
#include <chrono>
#include <sys/stat.h>
#include <dirent.h>

#include "problem.h"

using namespace std;

int count_file(const char * path);

int main()
{
    int training_size = 100;
    int number_of_problems;
    try
    {
        number_of_problems = count_file("./problem/");
    }
    catch(const string e)
    {
        cerr << "exception caught: " << e << '\n';
    }
    
    Problem problem(number_of_problems, training_size);
    string myanswer;
    int number = 0;
    while (number < training_size)
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

int count_file(const char * path)
{
    int counter = 0;
    struct stat st;
    if (lstat(path, &st) == 0)
    {
        if (S_ISDIR(st.st_mode))
        {
            DIR * dir = opendir(path);
            if (dir == nullptr)
                throw string("open folder error");

            struct dirent *entry = nullptr;
            while ((entry = readdir(dir)) != nullptr)
            {
                if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..")
                    counter ++;
            }
        }
        else
        {
            throw string("open folder error");
        }
    }
    else
    {
        throw string("open folder error");
    }
    return counter;
}
