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
    string name;
    Rope(string myname) : x{0.0}, y{0.0}, name{myname} {};

    double Distance(const Rope &T)
    {
        return sqrt(pow(this->x - T.x, 2) + pow(this->y - T.y, 2));
    }

    void move(const char &dir, Rope &T)
    {
        if (name == "head")
        {
            if (dir == 'U')
                this->y += 1;
            else if (dir == 'D')
                this->y -= 1;
            else if (dir == 'R')
                this->x += 1;
            else if (dir == 'L')
                this->x -= 1;
        }

        if ((this->x - T.x == -2 && this->y - T.y == 1) || (this->x - T.x == -1 && this->y - T.y == 2))
        {
            T.x -= 1;
            T.y += 1;
        }
        else if ((this->x - T.x == 2 && this->y - T.y == 1) || (this->x - T.x == 1 && this->y - T.y == 2))
        {
            T.x += 1;
            T.y += 1;
        }
        else if ((this->x - T.x == -2 && this->y - T.y == -1) || (this->x - T.x == -1 && this->y - T.y == -2))
        {
            T.x -= 1;
            T.y -= 1;
        }
        else if ((this->x - T.x == 2 && this->y - T.y == -1) || (this->x - T.x == 1 && this->y - T.y == -2))
        {
            T.x += 1;
            T.y -= 1;
        }
        else if ((this->x - T.x == 2 && this->y - T.y == 2))
        {
            T.x += 1;
            T.y += 1;
        }
        else if (this->x - T.x == -2 && this->y - T.y == 2)
        {
            T.x -= 1;
            T.y += 1;
        }
        else if (this->x - T.x == -2 && this->y - T.y == -2)
        {
            T.x -= 1;
            T.y -= 1;
        }
        else if (this->x - T.x == 2 && this->y - T.y == -2)
        {
            T.x += 1;
            T.y -= 1;
        }
        else if (this->x - T.x == 2 && this->y - T.y == 0)
        {
            T.x += 1;
        }
        else if (this->x - T.x == -2 && this->y - T.y == 0)
        {
            T.x -= 1;
        }
        else if (this->x - T.x == 0 && this->y - T.y == 2)
        {
            T.y += 1;
        }
        else if (this->x - T.x == 0 && this->y - T.y == -2)
        {
            T.y -= 1;
        }
    }
};

int main()
{
    ifstream infile("input.txt");
    string str;
    int steps;
    Rope H("head"), t1("t1"), t2("t2"), t3("t3"), t4("t4"), t5("t5"), t6("t6"), t7("t7"), t8("t8"), t9("t9");
    set<vector<double>> positions;
    while (infile >> str >> steps)
    {
        char dir = str[0];
        for (int i = 0; i < steps; i++)
        {
            H.move(dir, t1);
            t1.move(dir, t2);
            t2.move(dir, t3);
            t3.move(dir, t4);
            t4.move(dir, t5);
            t5.move(dir, t6);
            t6.move(dir, t7);
            t7.move(dir, t8);
            t8.move(dir, t9);
            positions.insert({t9.x, t9.y});
        }
    }
    cout << "size t9: " << positions.size() << endl; // part2: 2724
    return 0;
}