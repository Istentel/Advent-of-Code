#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getSum(const vector<int> &v)
{
    int total = 0;

    for (int i : v)
    {
        total += i;
    }

    return total;
}

bool isHex(char c)
{
    if (c >= 48 && c <= 57 || c >= 97 && c <= 102)
        return true;
    return false;
}

int main()
{
    ifstream in("input.txt");
    string line;
    int validPassports = 0;
    vector<int> fildsFound(8, 0);
    vector<string> filds{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};

    while (getline(in, line))
    {
        if (line.empty())
        {
            fill(fildsFound.begin(), fildsFound.end(), 0);
            continue;
        }

        replace(line.begin(), line.end(), ':', ' ');

        istringstream ss(line);

        string fild;

        while (ss >> fild)
        {
            if (find(filds.begin(), filds.end(), fild) != filds.end())
            {
                string value;

                ss >> value;

                if (fild == "byr")
                {
                    int byr = stoi(value);

                    if (byr >= 1920 && byr <= 2002)
                        fildsFound[0] = 1;
                }
                else if (fild == "iyr")
                {
                    int iyr = stoi(value);

                    if (iyr >= 2010 && iyr <= 2020)
                        fildsFound[1] = 1;
                }
                else if (fild == "eyr")
                {
                    int eyr = stoi(value);

                    if (eyr >= 2020 && eyr <= 2030)
                        fildsFound[2] = 1;
                }
                else if (fild == "hgt")
                {

                    if (value[value.size() - 2] == 'c' && value[value.size() - 1] == 'm')
                    {
                        value.resize(3);

                        int hgt = stoi(value);

                        if (hgt >= 150 && hgt <= 193)
                            fildsFound[3] = 1;
                    }
                    else if (value[value.size() - 2] == 'i' && value[value.size() - 1] == 'n')
                    {
                        value.resize(2);

                        int hgt = stoi(value);

                        if (hgt >= 59 && hgt <= 76)
                            fildsFound[3] = 1;
                    }
                }
                else if (fild == "hcl")
                {

                    if (value[0] == '#' && isHex(value[1]) && isHex(value[2]) && isHex(value[3]) && isHex(value[4]) && isHex(value[5]) && isHex(value[6]))
                    {
                        fildsFound[4] = 1;
                    }
                }
                else if (fild == "ecl")
                {

                    if (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth")
                        fildsFound[5] = 1;
                }
                else if (fild == "pid")
                {
                    int digits = 0;

                    for(char c : value){
                        if(isHex(c))
                            digits++;
                    }
                    
                    if(digits == 9)
                        fildsFound[6] = 1;
                }
                else if (fild == "cid")
                    fildsFound[7] = 1;
            }
        }

        if ((getSum(fildsFound) == 7 && fildsFound[7] == 0) || getSum(fildsFound) == 8)
        {
            validPassports++;
            fill(fildsFound.begin(), fildsFound.end(), 0);
        }
    }

    cout << "There are " << validPassports << " valid passports!\n";

    in.close();
}