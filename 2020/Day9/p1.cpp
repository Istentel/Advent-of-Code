#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isValid(const vector<int> &preamble, int target){
    for(int i : preamble){
        for(int j : preamble){
            if(i + j == target && i != j)
                return true;
        }
    }

    return false;
}

int main()
{
    ifstream in("input.txt");
    string line;
    vector<int> preamble;
    int ind = 1;
    int invalid = 0;

    while (getline(in, line))
    {
        istringstream ss(line);

        int nr;

        ss >> nr;

        if(ind <= 25){
            preamble.push_back(nr);
            ind++;
        }
        else{
            if(isValid(preamble, nr))
                preamble.push_back(nr);
            else{
                invalid = nr;
                break;
            }
            ind++;
        }
    }

    cout << "The invalid number is " << invalid << "\n";

    in.close();
}