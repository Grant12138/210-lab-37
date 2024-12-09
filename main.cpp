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

        // Interactive Menu
        while (true)
        {
            cout << "--- Hash Table Interactive Menu ---\n";
            cout << "1. Print the first 100 entries\n";
            cout << "2. Search for a key\n";
            cout << "3. Add a key\n";
            cout << "4. Remove a key\n";
            cout << "5. Modify a key\n";
            cout << "6. Exit\n"
            cout << "Enter your choice (1 - 6): ";

            int choice;
            cin >> choice;
            cin.ignore(1000, '\n');

            // Display the first 100 entries
            if (choice == 1)
            {
                cout << "Displaying the first 100 hash table entries:\n";

                int displayCount = 0;
                for (auto it = hashTable.begin(); it != hashTable.end() && displayCount < 100; it++, displayCount++)
                {
                    cout << "Hash Index " << it->first << ":\n";
                    for (const auto& code : it->second)
                        cout << "  " << code << '\n';
                }
            }

            if (choice == 2)
            {
                cout << "Enter the hash index to search for: ";
                int searchKey;
                cin >> searchKey;
                cin.ignore(1000, '\n');

                auto it = hashTable.find(searchKey);
                if (it != hashTable.end())
                {
                    cout << "Hash Index " << it->first << " contains the following codes:\n";
                    for (const auto& code : it->second)
                        cout << "  " << code << '\n';
                }
            }

            // if (choice == 3)

            if (choice == 4)
            {
                cout << "Enter the hash index to remove: ";
                int removeKey;
                cin >> removeKey;
                cin.ignore(1000, '\n');

                auto it = hashTable.find(removeKey);
                if (it != hashTable.end())
                {
                    hashTable.erase(it);
                    cout << "Hash Index " << removeKey << " has been removed.\n";
                }
                else
                    cout << "Hash Index " << removeKey << " not found.\n";
            }

            if (choice == 5)
            {

            }
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