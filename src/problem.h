#ifndef PROBLEM_H
#define PROBLEM_H

#include <ctime> 
#include <stdlib.h> 
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string FILE_PATH = "./problem/";

class Problem
{
public:
    Problem(int total_number_of_problems): total_sum(total_number_of_problems) {}
    virtual ~Problem() {}

    void showProblem()
    {
        string file_path = this->randomFilePath();
        this->parser(file_path);

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
        if (this->checkAnswer(user_asnwer))
        {
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "Wrong!" << "The answer is " << this->answer << endl;
        }
    }

private:
    string randomFilePath()
    {
        srand(time(nullptr));
        string random_file = to_string(rand()%(this->total_sum) + 1);
        random_file += ".txt";
        return "./problem/" + random_file;
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

    int total_sum;
    string text;
    string answer;
};

#endif