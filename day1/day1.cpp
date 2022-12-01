#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void display(const vector<int> &v)
{
    for (auto &i : v)
    {
        cout << i << endl;
    }
}
int main()
{
    ifstream in_file("input.txt");
    string str;
    int Max = 0, Sum = 0;
    vector<int> vec;
    while (getline(in_file, str))
    {
        if (str.find_first_not_of(' ') == std::string::npos) // if input is a empty string
        {
            if (Sum != 0)
                vec.push_back(Sum); // part 2: add sum
            if (Sum > Max)
            {
                Max = Sum;
            }
            Sum = 0;
            continue;
        }
        Sum += stoi(str);
    }
    cout << "Max is : " << Max << endl; // part 1 :72070
    sort(vec.begin(), vec.end());       // ascending order

    cout << "Top 3 sum: " << *(vec.end() - 1) + *(vec.end() - 2) + *(vec.end() - 3) << endl; // part 2: 211805

    return 0;
}