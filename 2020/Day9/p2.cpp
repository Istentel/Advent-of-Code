#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int findContiguous(const vector<int> &contiguous, const int target){
    int sum = 0;
    int high = 0, low = 0;
    int min = 0, max = 0;

    while(sum < target){
        sum += contiguous[high];
        high++;
    }

    if(sum != target){
    
        while(sum != target){

            if(sum > target){
                sum -= contiguous[low];
                low++;
            }

            if(sum < target){
                sum += contiguous[high];
                high++;
            }
        }

    }

    //find min max
    min = contiguous[low];
    for(int i = low;i<=high;i++){
        if(contiguous[i] < min)
            min = contiguous[i];
        
        if(contiguous[i] > max)
            max = contiguous[i];
    }

    return min + max;
    
}

int main()
{
    ifstream in("input.txt");
    string line;
    vector<int> contiguous;
    int target = 1124361034;

    while (getline(in, line))
    {
        istringstream ss(line);

        int nr;

        ss >> nr;

        if(nr < target)
            contiguous.push_back(nr);
        else
            break;
    }

    cout << "The sum is " << findContiguous(contiguous, target) << "\n";

    in.close();
}