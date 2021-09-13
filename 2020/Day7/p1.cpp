#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct bag {
    string color1;
    string color2;
    vector<bag> bags;
    bool hasShinyGold;

    bag(string color1, string color2, bool shineyGold) {
        this->color1 = color1;
        this->color2 = color2;
        hasShinyGold = shineyGold;
    }
};

bool searchBags(const vector<bag>& bags, const vector<bag>& specialBags) {
    for (const bag& b : bags) {
        for (const bag& s : specialBags) {
            if (b.color1 == s.color1 && b.color2 == s.color2)
                return true;
        }
    }

    return false;
}

bool compareBags(const string c1, const string c2, const vector<bag> &specialBags) {
    for (const bag &b : specialBags) {
        if (b.color1 == c1 && b.color2 == c2)
            return true;
    }

    return false;
}

int main()
{
    ifstream in("input.txt");
    string line;
    int totalShinyGold = 0;
    vector<bag> bags;
    vector<bag> specialBags;

    while (getline(in, line))
    {
        istringstream ss(line);

        string c1, c2, ite;

        ss >> c1 >> c2;

        bag mainBag(c1, c2, false);

        ss >> ite >> ite >> ite;

        while (ss >> c1 >> c2) {
            if (ite == "no" && c1 == "other")
                break;
            if (compareBags(c1, c2, specialBags) || (c1 == "shiny" && c2 == "gold")) {
                mainBag.hasShinyGold = true;
                specialBags.push_back(mainBag);
            }

            bag secodaryBag(c1, c2, false);

            mainBag.bags.push_back(secodaryBag);

            ss >> ite >> ite;
        }

        bags.push_back(mainBag);

    }

    for (const bag& b : bags) {
        if (b.hasShinyGold || searchBags(b.bags, specialBags)) {
            totalShinyGold++;
            specialBags.push_back(b);
        }
    }


    cout << "Size is " << totalShinyGold << "\n";

    in.close();
}