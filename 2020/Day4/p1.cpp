#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getSum(const vector<int> &v){
    int total = 0;

    for(int i : v){
        total += i;
    }

    return total;
}


int main()
{
    ifstream in("input.txt");
    string line;
    int validPassports = 0;
    vector<int> fildsFound(8, 0);
    vector<string> filds { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
   

    while (getline(in, line))
    {   
        if(line.empty()){
            fill(fildsFound.begin(), fildsFound.end(), 0);
            continue;
        }

        replace(line.begin(), line.end(), ':' , ' ');

        istringstream ss(line);

        string fild;

        while(ss >> fild){
            if(find(filds.begin(), filds.end(), fild) != filds.end()){
                
                if(fild == "byr") fildsFound[0] = 1;
                else if(fild == "iyr") fildsFound[1] = 1;
                else if(fild == "eyr") fildsFound[2] = 1;
                else if(fild == "hgt") fildsFound[3] = 1;
                else if(fild == "hcl") fildsFound[4] = 1;
                else if(fild == "ecl") fildsFound[5] = 1;
                else if(fild == "pid") fildsFound[6] = 1;
                else if(fild == "cid") fildsFound[7] = 1;
            }
        }

        if((getSum(fildsFound) == 7 && fildsFound[7] == 0) || getSum(fildsFound) == 8){
            validPassports++;
            fill(fildsFound.begin(), fildsFound.end(), 0);
        }
    }

    cout << "There are " << validPassports << " valid passports!\n";

    in.close();
}