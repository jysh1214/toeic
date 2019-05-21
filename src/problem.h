#ifndef PROBLEM_H
#define PROBLEM_H

#include <ctime> 
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "color_mod.h"

using namespace std;

string FILE_PATH = "./problem/";

class Problem
{
public:
    Problem(int number_of_problems, int training_size): 
    total_sum(number_of_problems), batch_size(training_size)
    {
        for (int i = 0; i < total_sum; i++)
        {
            this->problems.push_back(i + 1);
        }

        this->shuffle(this->problems.begin(), this->problems.end());
    }
    virtual ~Problem() {}

    void showProblem(int number)
    {
        string file_path = to_string(this->problems[number]);
        file_path += ".txt";
        this->parser("./problem/" + file_path);

        cout << "(" << number+1 << "/" << total_sum << ")";

        cout << this->text << endl;
        cout << "Input Answer: " ;
    }

    bool checkAnswer(string user_asnwer)
    {
        if (user_asnwer == answer) {return true;}
        else {return false;}
    }

    void showResult(string user_asnwer)
    {
        Color::Modifier green(Color::FG_GREEN);
        Color::Modifier red(Color::FG_RED);
        Color::Modifier def(Color::FG_DEFAULT);
        
        if (this->checkAnswer(user_asnwer))
        {
            cout << green << "Correct!" << def << endl;
        }
        else
        {
            cout << red << "Wrong!" << def;
            cout << "The answer is (" << this->answer << ")" << endl;
        }
    }

private:
    template< class T >
    void shuffle(T first, T last)
    {
        srand(time(nullptr));
        typename iterator_traits<T>::difference_type i, n;
        n = last - first;
        for (i = n-1; i > 0; --i)
        {
            swap(first[i], first[rand()%(i+1)]);
        }
    }

    void parser(string file_path)
    {
        ifstream myfile;

        try
        {
            myfile.open(file_path);
        }
        catch(const exception& e)
        {
            cerr << "exception caught: " << e.what() << '\n';
        }

        stringstream strStream;          //read the file as pure string
        strStream << myfile.rdbuf();     //read the file
        string myFile = strStream.str(); //str holds the content of the file

        this->answer = myFile[0];
        this->text = myFile.substr(1, myFile.size());
    }

    vector<int> problems;

    int total_sum; int batch_size;
    string text;
    string answer;
};

#endif