#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// --- Bloom Filter Hash Functions ---
int bloomHash1(const string &s, int size)
{
    int hash = 0;
    for (char c : s)
    {
        hash += static_cast<int>(c);
        hash %= size;
    }
    return hash;
}

int bloomHash2(const string &s, int size)
{
    int hash = 1;
    for (size_t i = 0; i < s.size(); ++i)
    {
        hash += (i * static_cast<int>(s[i]));
        hash %= size;
    }
    return hash;
}

int bloomHash3(const string &s, int size)
{
    int hash = 2;
    for (char c : s)
    {
        hash = (hash * 31 + static_cast<int>(c)) % size;
    }
    return hash;
}

void insertBloom(int bloomFilter[], const string &name, int size)
{
    int a = bloomHash1(name, size);
    int b = bloomHash2(name, size);
    int c = bloomHash3(name, size);

    if (bloomFilter[a] == 1 && bloomFilter[b] == 1 && bloomFilter[c] == 1)
    {
        cout << "\nThe Name is Probably Present !!";
    }
    else
    {
        bloomFilter[a] = 1;
        bloomFilter[b] = 1;
        bloomFilter[c] = 1;
        cout << name << " is inserted !!";
    }

    cout << "\nBloom Filter Bit Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << bloomFilter[i] << " ";
    }
    cout << endl;
}

// --- Cuckoo Filter Hash Functions ---
int cuckooHash1(int num, int size)
{
    return num % size;
}

int cuckooHash2(int num, int size)
{
    return (num / size) % size;
}

void printCuckooHashTables(int table1[], int table2[], int size)
{
    cout << "\nHashtable 1: ";
    for (int i = 0; i < size; ++i)
    {
        cout << table1[i] << " | ";
    }

    cout << "\nHashtable 2: ";
    for (int i = 0; i < size; ++i)
    {
        cout << table2[i] << " | ";
    }
    cout << endl;
}

void insertCuckoo(int table1[], int table2[], int num, int size, int depth = 0)
{
    if (depth > 5)
    {
        cout << "\nInsertion failed. Cuckoo cycle detected!\n";
        return;
    }

    int a = cuckooHash1(num, size);
    if (table1[a] == -1)
    {
        table1[a] = num;
    }
    else
    {
        int temp = table1[a];
        table1[a] = num;
        int b = cuckooHash2(temp, size);
        if (table2[b] == -1)
        {
            table2[b] = temp;
        }
        else
        {
            insertCuckoo(table1, table2, temp, size, depth + 1);
        }
    }

    printCuckooHashTables(table1, table2, size);
}

// --- Main Function ---
int main()
{
    int choice;
    do
    {
        cout << "\nWhich Filter Do You Want To Choose\n(1) Bloom Filter\n(2) Cuckoo Filter\n(0) Exit\nEnter Your Choice-- > ";
        cin >> choice;

        if (choice == 1)
        {
            int bloomFilter[10] = {0};
            string name;
            int continueInsert;
            do
            {
                cout << "\nEnter the name you want to insert: ";
                cin >> name;
                insertBloom(bloomFilter, name, 10);
                cout << "\nDo you want to insert another name (1/0): ";
                cin >> continueInsert;
            } while (continueInsert != 0);
        }
        else if (choice == 2)
        {
            int cuckooFilter1[10];
            int cuckooFilter2[10];
            fill(begin(cuckooFilter1), end(cuckooFilter1), -1);
            fill(begin(cuckooFilter2), end(cuckooFilter2), -1);

            int num;
            int continueInsert;
            do
            {
                cout << "\nEnter a number to be inserted: ";
                cin >> num;
                insertCuckoo(cuckooFilter1, cuckooFilter2, num, 10);
                cout << "\nDo you want to insert more numbers (1/0): ";
                cin >> continueInsert;
            } while (continueInsert != 0);
        }
        else if (choice == 0)
        {
            cout << "Exiting Program...";
            break;
        }
        else
        {
            cout << "Invalid Input!!!";
        }
    } while (choice != 0);

    return 0;
}
