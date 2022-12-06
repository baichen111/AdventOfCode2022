#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <array>

using namespace std;

void display(stack<char> s)
{
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

template <size_t N>
void InitStack(array<char,N> arr, stack<char> &s)
{
    for (int i = 0; i < N; i++)
    {
        s.push(arr[i]);
    }
}

//move elements from one stack to another
void moveStack(int times,int src,int dest,vector<stack<char>> &v){
    for(int i = 0;i<times;i++){
        v.at(dest-1).push(v.at(src-1).top());
        v.at(src-1).pop();
    }
}

int main()
{
    array<char,8> arr1 = {'D', 'T', 'W', 'F', 'J', 'S', 'H', 'N'};
    array<char,8> arr2 = {'H', 'R', 'P', 'Q', 'T', 'N', 'B', 'G'};
    array<char,3> arr3 = {'L', 'Q', 'V'};
    array<char,6> arr4 = {'N', 'B', 'S', 'W', 'R', 'Q'};
    array<char,7>  arr5 = {'N', 'D', 'F', 'T', 'V', 'M', 'B'};
    array<char,7> arr6 = {'M', 'D', 'B', 'V', 'H', 'T', 'R'};
    array<char,4>  arr7 = {'D', 'B', 'Q', 'J'};
    array<char,8> arr8 = {'D', 'N', 'J', 'V', 'R', 'Z', 'H', 'Q'};
    array<char,5>   arr9 = {'B', 'N', 'H', 'M', 'S'};

    stack<char> s1, s2, s3, s4, s5, s6, s7, s8, s9;
    vector<stack<char>> vs;
    InitStack(arr1, s1);
    InitStack(arr1, s1);
    vs.push_back(s1);

    InitStack(arr2, s2);
    vs.push_back(s2);

    InitStack(arr3, s3);
    vs.push_back(s3);

    InitStack(arr4, s4);
    vs.push_back(s4);

    InitStack(arr5, s5);
    vs.push_back(s5);

    InitStack(arr6, s6);
    vs.push_back(s6);

    InitStack(arr7, s7);
    vs.push_back(s7);

    InitStack(arr8, s8);
    vs.push_back(s8);

    InitStack(arr9, s9);
    vs.push_back(s9);

    ifstream infile("input.txt");
    string str;
    int a, b, c;
    vector<vector<int>> vc;
    while (infile >> a >> b >> c)
    {
        vc.push_back({a, b, c});
    }

    for (auto &v : vc)
    {
        moveStack(v.at(0), v.at(1), v.at(2), vs);
    }
    cout<<"=========after============"<<endl;
    for(int i=0;i<vs.size();i++){
        display(vs.at(i));
    } //part1: GRTSWNJHH
    return 0;
}
