#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("input.txt");
    string line;
    int validPws = 0;

    while (getline(in, line))
    {  
        line.replace(line.begin(), line.end(), '-', ' ');
        line.replace(line.begin(), line.end(), ':', ' ');

        stringstream ss(line);
        int min = 0, max = 0, letterSeen = 0;
        char letter;
        string password;

        ss >> min >> max >> letter >> password;

        for(char c : password){
            if(c == letter)
                letterSeen++;
        }

        if(letterSeen >= min && letterSeen <= max)
            validPws++;   
    }

    cout << "There are " << validPws << " valide passwords!\n";

    in.close();
}