#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getYes(const vector<int> &v, int members){
    int count = 0;

    for(int i : v){
        if(i == members)
            count++;
    }

    return count;
}

int main()
{
    ifstream in("input.txt");
    string line;
    int totalYes = 0;
    int members = 0;
    vector<int> questions(26, 0);

    while (getline(in, line))
    {
        if(line.empty()){
            totalYes += getYes(questions, members);

            fill(questions.begin(), questions.end(), 0);
            members = 0;
            continue;
        }

        for(char c : line){
            int i = c - 'a';

            questions[i] += 1;
        }

        members++;
    }

    totalYes += getYes(questions, members);


    cout << "The sum is " << totalYes << "\n";

    in.close();
}