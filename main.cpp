#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(const string &s);

int main()
{
    ifstream fin("lab-37-data.txt");
    if (!fin.good())
        throw "I/O error";
    catch (const char* e)
    {
        cout << e << '\n';
    }

    string line;


    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int sum_ascii(const string &s)
{
    int sum = 0;
    for (char c : s)
        sum += (int) c;

    return sum;
}
