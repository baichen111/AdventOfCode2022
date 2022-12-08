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
    int mx = 0;
    for (int r = 1; r < vec1.size() - 1; r++)
    {
        for (int c = 1; c < vec1.at(r).size() - 1; c++)
        {
            int sum1 = 0;
            for (int i = c - 1; i >= 0; i--)
            {
                if (vec1.at(r).at(c) > vec1.at(r).at(i))
                {
                    sum1++;
                }
                if (vec1.at(r).at(c) <= vec1.at(r).at(i))
                {
                    sum1++;
                    break;
                }
            }

            int sum2 = 0;
            for (int i = c + 1; i < vec1.at(r).size(); i++)
            {
                if (vec1.at(r).at(c) > vec1.at(r).at(i))
                {
                    sum2++;
                }
                if (vec1.at(r).at(c) <= vec1.at(r).at(i))
                {
                    sum2++;
                    break;
                }
            }
            int sum3 = 0;
            for (int j = r - 1; j >= 0; j--)
            {
                if (vec1.at(r).at(c) > vec1.at(j).at(c))
                {
                    sum3++;
                }
                if (vec1.at(r).at(c) <= vec1.at(j).at(c))
                {
                    sum3++;
                    break;
                }
            }
            int sum4 = 0;
            for (int j = r + 1; j < vec1.size(); j++)
            {
                if (vec1.at(r).at(c) > vec1.at(j).at(c))
                {
                    sum4++;
                }
                if (vec1.at(r).at(c) <= vec1.at(j).at(c))
                {
                    sum4++;
                    break;
                }
            }
            int sum = sum1 * sum2 * sum3 * sum4;
            if (sum > mx)
                mx = sum;
        }
    }
    cout << mx << endl; // part2:  211680
    return 0;
}