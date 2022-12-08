#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void displayVV(vector<vector<int>> &v)
{
    for (auto &v1 : v)
    {
        for (auto &n : v1)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}
int main()
{
    ifstream infile("input.txt");
    string str;
    vector<vector<int>> vec1;
    vector<int> vec2;
    while (getline(infile, str))
    {
        for (auto &c : str)
        {
            vec2.push_back((int)(c - '0'));
        }
        vec1.push_back(vec2);
        vec2.clear();
    }
    int sum = 0;

    for (int r = 1; r < vec1.size() - 1; r++)
    {
        for (int c = 1; c < vec1.at(r).size() - 1; c++)
        {
            bool flag1 = true;

            for (int i = 0; i < c; i++)
            {
                if (vec1.at(r).at(c) <= vec1.at(r).at(i))
                {
                    flag1 = false;
                    break;
                }
            }
            bool flag2 = true;
            for (int i = c + 1; i < vec1.at(r).size(); i++)
            {
                if (vec1.at(r).at(c) <= vec1.at(r).at(i))
                {
                    flag2 = false;
                    break;
                }
            }
            bool flag3 = true;
            for (int j = 0; j < r; j++)
            {
                if (vec1.at(r).at(c) <= vec1.at(j).at(c))
                {
                    flag3 = false;
                    break;
                }
            }
            bool flag4 = true;
            for (int j = r + 1; j < vec1.size(); j++)
            {
                if (vec1.at(r).at(c) <= vec1.at(j).at(c))
                {
                    flag4 = false;
                    break;
                }
            }
            if (flag1 || flag2 || flag3 || flag4)
                sum++;
        }
    }
    cout << sum + 2 * vec1.size() + 2 * (vec1.at(0).size() - 2) << endl; // part1: 1823
    return 0;
}