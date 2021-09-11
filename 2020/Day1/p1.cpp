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
    vector<int> nums;

    while (getline(in, line))
    {
        stringstream ss(line);
        int nr;
        ss >> nr;
        nums.push_back(nr);
    }

    in.close();

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 2020 - nums[i])
                cout << nums[j] << " * " << nums[i] << " = " << nums[i] * nums[j] << "\n";
        }
    }

}