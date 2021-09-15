#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Bag{
    string name;
    int carry;

    Bag(string name, int carry){
        this->name = name;
        this->carry = carry;
    }
};

int countBags(unordered_map<string, vector<Bag>>& bags, string node) {
    int count = 1;

    for(int i=0;i<bags[node].size();i++){
        int qty = bags[node][i].carry;
        count += qty * countBags(bags, bags[node][i].name);
    }

    return count;
}

int main()
{
    ifstream in("input.txt");
    string line;
    unordered_map<string, vector<Bag>> bagsGraph;
    vector<string> visited;

    while (getline(in, line))
    {
        istringstream ss(line);

        string c1, c2, ite;
        int nr;

        ss >> c1 >> c2;

        string mainBag = c1 + "-" + c2;

        ss >> ite >> ite;

        while (ss >> nr >> c1 >> c2) {
            if (c1 == "other" && c2 == "bags")
                break;

            string bagName = c1 + "-" + c2;

            bagsGraph[mainBag].push_back(Bag(bagName, nr));

            ss >> ite;
        }

    }

    cout << "Bags " << countBags(bagsGraph, "shiny-gold") - 1 << "\n";

    in.close();
}