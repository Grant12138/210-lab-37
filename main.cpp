/***************************************************************************
* COMSC-210 | Lab 37 & 38 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <fstream>
#include <list>
#include <map>
using namespace std;

const int CAPACITY = 10000;

int get_hash_index(const string &, const int capacity = CAPACITY);

int main()
{
    try
    {
        ifstream fin("lab-37-data.txt");
        if (!fin.good())
            throw "I/O error";

        map<int, list<string>> hashTable {};

        string line;
        while (getline(fin, line))
        {
            int hash_index = get_hash_index(line);
            hashTable[hash_index].push_back(line);
        }
        fin.close();

        cout << "Displaying the first 100 hash table entries:\n";

        int displayCount = 0;
        for (auto it = hashTable.begin(); it != hashTable.end() && displayCount < 100; it++, displayCount++)
        {
            cout << "Hash Index " << it->first << ":\n";
            for (const auto &code : it->second)
                cout << "  " << code << "\n";
        }
    }
    catch (const char* e)
    {
        cout << e << '\n';
    }

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/


/*****************************************************************
 * FUNCTION: A typical modular arithmetic based hash function that encrypts a string
 *
 * @param s
 * @param capacity
 *
 * @return INT;
 */
int get_hash_index(const string& s, const int capacity)
{
    int sum = 0;
    for (char c : s)
        sum += (int) c;

    return sum % capacity;
}
