#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

bool hasNode(vector<string>& visited, string node) {
    for (string n : visited) {
        if (n == node)
            return true;
    }

    return false;
}

int countBags(unordered_map<string, vector<string>>& bags, vector<string> &visited, string node) {
    if (hasNode(visited, node))
        return 0;

    visited.push_back(node);

    int count = 1;
    
    for (string neighbor : bags[node]) {
        count += countBags(bags, visited, neighbor);
    }

    return count;
}

int main()
{
    ifstream in("input.txt");
    string line;
    unordered_map<string, vector<string>> bagsGraph;
    vector<string> visited;

    while (getline(in, line))
    {
        istringstream ss(line);

        string c1, c2, ite;

        ss >> c1 >> c2;

        vector<string> secondayBags;
        string mainBag = c1 + "-" + c2;

        ss >> ite >> ite >> ite;

        while (ss >> c1 >> c2) {
            if (ite == "no" && c1 == "other")
                break;

            string secondaryBag = c1 + "-" + c2;

            bagsGraph[secondaryBag].push_back(mainBag);

            ss >> ite >> ite;
        }

    }

    cout << "Bags " << countBags(bagsGraph, visited, "shiny-gold") - 1 << "\n";

    in.close();
}