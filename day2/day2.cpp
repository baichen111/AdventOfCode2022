#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    // A: Rock, B: Paper, C:Scissor;
    // X: Rock, Y: Paper, Z: Scissor;
    // X: 1;    Y:2;      Z:3;

    ifstream infile("input.txt");
    string str;
    int score = 0, score1 = 0;

    while (getline(infile, str))
    {
        char op = str[0], my = str[2];

        if (op == 'A' && my == 'X')
            score += 3 + 1;
        else if (op == 'A' && my == 'Y')
            score += 6 + 2;
        else if (op == 'A' && my == 'Z')
            score += 0 + 3;
        else if (op == 'B' && my == 'X')
            score += 0 + 1;
        else if (op == 'B' && my == 'Y')
            score += 3 + 2;
        else if (op == 'B' && my == 'Z')
            score += 6 + 3;
        else if (op == 'C' && my == 'X')
            score += 6 + 1;
        else if (op == 'C' && my == 'Y')
            score += 0 + 2;
        else if (op == 'C' && my == 'Z')
            score += 3 + 3;

        // part 2: X:lose; Y:draw; Z:win
        if (op == 'A' && my == 'X')
            score1 += 0 + 3;
        else if (op == 'A' && my == 'Y')
            score1 += 3 + 1;
        else if (op == 'A' && my == 'Z')
            score1 += 6 + 2;
        else if (op == 'B' && my == 'X')
            score1 += 0 + 1;
        else if (op == 'B' && my == 'Y')
            score1 += 3 + 2;
        else if (op == 'B' && my == 'Z')
            score1 += 6 + 3;
        else if (op == 'C' && my == 'X')
            score1 += 0 + 2;
        else if (op == 'C' && my == 'Y')
            score1 += 3 + 3;
        else if (op == 'C' && my == 'Z')
            score1 += 6 + 1;
    }
    cout << score << endl;  // part1: 13005
    cout << score1 << endl; // part2:11373

    return 0;
}