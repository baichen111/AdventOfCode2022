#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

class Rope
{
public:
    double x;
    double y;
    double prevHx;
    double prevHy;
    vector<double> v;
    set<vector<double>> track;
    Rope() : x{0.0}, y{0.0} {};

    double Distance(const Rope &T)
    {
        return sqrt(pow(this->x - T.x, 2) + pow(this->y - T.y, 2));
    }
    void move(const char &dir, int steps, Rope &T)
    {
        for (int i = 0; i < steps; i++)
        {
            if (dir == 'U')
                this->y += 1;
            else if (dir == 'D')
                this->y -= 1;
            else if (dir == 'R')
                this->x += 1;
            else if (dir == 'L')
                this->x -= 1;

            if (this->Distance(T) == 2)
            {
                if (dir == 'U')
                    T.y += 1;
                else if (dir == 'D')
                    T.y -= 1;
                else if (dir == 'R')
                    T.x += 1;
                else if (dir == 'L')
                    T.x -= 1;
            }
            else if (this->Distance(T) == sqrt(2))
            {
                prevHx = this->x;
                prevHy = this->y;
            }
            else if (this->Distance(T) == sqrt(5))
            {
                T.x = prevHx;
                T.y = prevHy;
            }

            track.insert({T.x, T.y});
        }
    }
};

int main()
{
    ifstream infile("input.txt");
    string str;
    int steps;
    Rope H, T;
    while (infile >> str >> steps)
    {
        char dir = str[0];
        H.move(dir, steps, T);
    }
    /*=============================*/
    cout << H.track.size() << endl; // part1: 6503

    return 0;
}