#include <iostream>
#include <vector>
#include <algorithm>
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
        replace(line.begin(), line.end(), '-', ' ');
        replace(line.begin(), line.end(), ':', ' ');

        istringstream ss(line);
        int poz1 = 0, poz2 = 0;
        char letter;
        string password;

        ss >> poz1 >> poz2 >> letter >> password;

        if((password[poz1 - 1] == letter && password[poz2 - 1] != letter) || (password[poz1 - 1] != letter && password[poz2 - 1] == letter) )
            validPws++;   
    }

    cout << "There are " << validPws << " valide passwords!\n";

    in.close();
}