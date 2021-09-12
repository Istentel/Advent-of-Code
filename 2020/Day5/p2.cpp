#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getHalf(int min, int max)
{
    int count = 0;

    while (min < max)
    {
        min++;
        count++;
    }

    return (min - count) + (count / 2);
}

int findYourSeat(const vector<int> &seats){
    int counter = seats[0];

    for(int i : seats){
        if(i != counter)
            return counter;
        counter++; 
    }

    return 0;
}

int main()
{
    ifstream in("input.txt");
    string line;
    int highestId = 0;
    vector<int> seats;

    while (getline(in, line))
    {
        int min = 0, max = 127;
        int row, colum;

        for (int i = 0; i < 7; i++)
        {
            if (line[i] == 'F')
                max = getHalf(min, max);
            else
                min = getHalf(min, max) + 1;
        }

        if (min == max)
            row = min;

        min = 0, max = 7;

        for (int i = 7; i < 10; i++)
        {
            if (line[i] == 'L')
                max = getHalf(min, max);
            else
                min = getHalf(min, max) + 1;
        }

        if (min == max)
            colum = min;

        seats.push_back(row*8+colum);
    }

    sort(seats.begin(), seats.end());

    cout << "Your seat is " << findYourSeat(seats) << "\n";

    in.close();
}