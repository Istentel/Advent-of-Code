#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> getData(){
    ifstream in("input.txt");
    string line;
    vector<int> adaptersJtg;

    while (getline(in, line))
    {
        istringstream ss(line);

        int joltage;

        ss >> joltage;

        adaptersJtg.push_back(joltage);
    }

    in.close();

    return adaptersJtg;
}


int main()
{
    vector<int> adaptersJtg = getData();
    
    int onej = 0, threej = 1;
    int current  = 0;

    sort(adaptersJtg.begin(), adaptersJtg.end());    

    for(int i : adaptersJtg){

        if(i - current == 1){
            current = i;
            onej++;
        }else if(i - current == 3){
            current = i;
            threej++;
        }else
            current = i;
            
    }

    cout << "The number is " <<  onej * threej << "\n";
    
}