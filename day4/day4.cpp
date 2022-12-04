#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

array<string, 2> SplitBy(const string &str, const char &c)
{
    array<string, 2> arr;
    int i = str.find(c);
    string a = str.substr(0, i);
    string b = str.substr(i + 1, str.size());
    arr[0] = a;
    arr[1] = b;
    return arr;
}

int main()
{
    ifstream infile("input.txt");
    string input;
    int sum1 = 0, sum2 = 0;
    while (getline(infile, input))
    {
        string a = SplitBy(input, ',').at(0);
        array<string, 2> r1 = SplitBy(a, '-');
        int lr1 = stoi(r1.at(0)), hr1 = stoi(r1.at(1));

        string b = SplitBy(input, ',').at(1);
        array<string, 2> r2 = SplitBy(b, '-');
        int lr2 = stoi(r2.at(0)), hr2 = stoi(r2.at(1));

        if ((lr1 >= lr2 && hr1 <= hr2) || (lr1 <= lr2 && hr1 >= hr2))
            sum1++;

        if ((lr1 >= lr2 && lr1 <= hr2) || (hr1 >= lr2 && hr1 <= hr2) || (lr2 >= lr1 && lr2 <= hr1) || (hr2 >= lr1 && hr2 <= hr1))
            sum2++;
    }
    cout << sum1 << endl; // part1 : 602
    cout << sum2 << endl; // part2 : 891
    return 0;
}