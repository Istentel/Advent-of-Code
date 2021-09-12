#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getYesQuestions(const vector<bool> &v){
    int counter = 0;

    for(bool i : v){
        if(i)
            counter++;
    }

    return counter;
}

int main()
{
    ifstream in("input.txt");
    string line;
    int totalYes = 0;
    vector<bool> questions(26, false);

    while (getline(in, line))
    {
        if(line.empty()){
            totalYes += getYesQuestions(questions);
            fill(questions.begin(), questions.end(), false);
        }
        for(char c : line){
            int i = c - 'a';

            if(!questions[i])
                questions[i] = true;
        }
    }

    totalYes += getYesQuestions(questions);

    cout << "The sum is " << totalYes << "\n";

    in.close();
}