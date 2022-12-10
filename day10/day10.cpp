#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    string str;
    int num;
    vector<int> v;
    while (getline(infile, str))
    {
        if (str == "noop")
        {
            v.push_back(0);
        }
        else
        {
            size_t t = str.find(" ");
            if (t != string::npos)
            {
                num = stoi(str.substr(t + 1));
                v.push_back(0);
                v.push_back(num);
            }
        }
    }

    int sum1 = 1, sum2 = 1, sum3 = 1, sum4 = 1, sum5 = 1, sum6 = 1;
    for (int i = 0; i < v.size(); i++)
    {

        if (i <= 18)
        {
            sum1 += v.at(i);
        }
        if (i <= 58)
        {
            sum2 += v.at(i);
        }
        if (i <= 98)
        {
            sum3 += v.at(i);
        }
        if (i <= 138)
        {
            sum4 += v.at(i);
        }
        if (i <= 178)
        {
            sum5 += v.at(i);
        }
        if (i <= 218)
        {
            sum6 += v.at(i);
        }
    }

    int total = 20 * sum1 + 60 * sum2 + 100 * sum3 + 140 * sum4 + 180 * sum5 + 220 * sum6;
    cout << "total: " << total << endl; // part1: 13820
    return 0;
}