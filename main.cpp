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
void print_id(string const& lab_desc);

int main()
{
    print_id("Lab 37 & 38: Hash Table I && II");

    try
    {
        // Read the file
        ifstream fin("lab-37-data.txt");
        if (!fin.good())
            throw "I/O error";

        // Initialize the hash table
        map<int, list<string>> hashTable {};

        // Populate the hash table
        string line;
        while (getline(fin, line))
        {
            int hash_index = get_hash_index(line);
            hashTable[hash_index].push_back(line);
        }
        fin.close();

        // Display the first 100 entries
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


void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}