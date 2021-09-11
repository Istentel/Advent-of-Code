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
        ss >> nr >> nr;
        nums.push_back(nr);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            for (int k = 0; k < nums.size(); k++)
            {
                if(nums[i] + nums[j] + nums[k] == 2020){
                    cout << nums[i] << " * " << nums[j] << " * " << nums[k] << " = " << nums[i]*nums[j]*nums[k] << "\n";
                }
            }
        }
    }

    in.close();
}