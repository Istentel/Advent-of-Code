#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getTrees(const vector<string> &map, int X, int Y){
    int trees = 0;
    int x = 0, y = 0;
    int stopPoint = 31 - Y;

    while (x < map.size() - 1)
    {
        x += X;
        if (y >= stopPoint)
            y = (y + Y) - 31;
        else
            y += Y;

        if (map[x][y] == '#')
            trees++;
    }

    return trees;
}

int main()
{
    ifstream in("input.txt");
    string line;
    uint64_t trees = 1;
    vector<string> map;
    vector<vector<int>> steps { {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

    while (getline(in, line))
    {
        map.push_back(line);
    }

    for(const vector<int> &v : steps){
        trees *= getTrees(map, v[1], v[0]);
    }

    cout << "Trees encountered: " << trees << "\n";

    in.close();
}