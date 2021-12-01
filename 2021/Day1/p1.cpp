#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){

    ifstream in("input.txt");
    string line;
    vector<int> nums;
    int lastNr = 0;
    int counter = 0;

    while(getline(in, line)){
        stringstream ss(line);
        int nr;
        ss >> nr;

        if(lastNr > 0){
            if(nr > lastNr)
                counter++;
        }

        lastNr = nr;
    }

    cout << counter;
}