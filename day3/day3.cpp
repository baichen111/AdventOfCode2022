#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
void display(const vector<T> &v)
{
    for (T c : v)
    {
        cout << c << endl;
    }
}

int main()
{
    ifstream infile("input.txt");
    string str;
    vector<char> vec;
    vector<char> albet;
    vector<string> strvec;
    for (char c = 'a'; c <= 'z'; c++)
    {
        albet.push_back(c);
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        albet.push_back(c);
    }

    while (getline(infile, str))
    {
        strvec.push_back(str);
        int mid = str.size() / 2;
        string str1 = str.substr(0, mid);
        string str2 = str.substr(mid, str.size());
        for (char c : str1)
        {
            if (str2.find(c) != string::npos)
            {
                vec.push_back(c);
                break;
            }
        }
    }

    int sum = 0;
    for (char c : vec)
    {
        sum += std::find(albet.begin(), albet.end(), c) - albet.begin() + 1;
    }
    cout << "part1 sum: " << sum << endl; // part1: 7990
/* ================ part 2 =======================================*/

    int sum1 = 0;
    for (int i = 0; i < strvec.size(); i += 3)
    {
        for (char c : strvec.at(i))
        {
            if (strvec.at(i + 1).find(c) != string::npos && strvec.at(i + 2).find(c) != string::npos)
            {
                sum1 += std::find(albet.begin(), albet.end(), c) - albet.begin() + 1;
                break;
            }
        }
    }
    cout << "part2 sum: " << sum1 << endl;  // part2: 2602
    return 0;
}