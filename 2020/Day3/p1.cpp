#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    string line;
    int trees = 0;
    vector<string> map;

    while (getline(in, line))
    {
        map.push_back(line);
    }

    int x = 0, y = 0;

    while (x < map.size() - 1)
    {
        x += 1;
        if (y >= 28)
            y = (y + 3) - 31;
        else
            y += 3;

        if (map[x][y] == '#')
            trees++;
    }

    cout << "Trees encountered: " << trees << "\n";

    in.close();
}