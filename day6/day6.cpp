#include <iostream>
#include <fstream>
#include <set>

using namespace std;

// check if the string has duplicates
bool checkDuplicates(string s)
{
    set<char> charSet;
    for (auto c : s)
    {
        charSet.insert(c);
    }
    if (s.size() == charSet.size())
    {
        return true; // has no duplicates if true
    }
    return false;
}
int main()
{
    ifstream infile("input.txt");
    string str;
    getline(infile, str);
    int sum = 0;
    for (int i = 0; i < str.size() - 4; i++)
    {
        string s1 = str.substr(i, 4);
        if (checkDuplicates(s1))
            break; // if no duplicates
        sum++;
    }
    cout << sum + 4 << endl; // part1: 1912
/*=============== part 2 ====================*/
    sum = 0;
    for (int i = 0; i < str.size() - 14; i++)
    {
        string s1 = str.substr(i, 14);
        if (checkDuplicates(s1))
            break; // if no duplicates
        sum++;
    }
    cout << sum + 14 << endl; // part2:  2122
    return 0;
}