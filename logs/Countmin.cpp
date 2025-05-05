#include <iostream>
using namespace std;
class CountMinSketch
{
public:
    int table1[10];
    int table2[10];
    int table3[10];
    int table4[10];
    CountMinSketch()
    {
        for (int i = 0; i < 10; i++)
        {
            table1[i] = 0;
            table2[i] = 0;
            table3[i] = 0;
            table4[i] = 0;
        }
    }
    int hashFunc1(int value)
    {
        return (value * 2 + 2) % 10;
    }
    int hashFunc2(int value)
    {
        return (value * 3 + 3) % 10;
    }
    int hashFunc3(int value)
    {
        return (value * 4 + 4) % 10;
    }
    int hashFunc4(int value)
    {
        return (value * 5 + 5) % 10;
    }
    int convertStringToNumber(string str)
    {
        int result = 0;
        int len = str.length();
        for (int i = 0; i < len; ++i)
        {
            cout << endl
                 << str[i] << " " << (int)str[i];
            result += (int)str[i];
        }
        return result;
    }
    void insertValue(string str)
    {
        int num = convertStringToNumber(str);
        cout << endl
             << "The number is : " << num;
        printTables();
        int h1 = hashFunc1(num);
        int h2 = hashFunc2(num);
        int h3 = hashFunc3(num);
        int h4 = hashFunc4(num);
        cout << endl
             << "The hash values are: h1 => " << h1 << " h2 => " << h2 << " h3 => "
             << h3 << " h4 => " << h4;
        table1[h1]++;
        table2[h2]++;
        table3[h3]++;
        table4[h4]++;
        printTables();
    }
    void getCount(string str)
    {
        int num = convertStringToNumber(str);
        int h1 = hashFunc1(num);
        int h2 = hashFunc2(num);
        int h3 = hashFunc3(num);
        int h4 = hashFunc4(num);
        cout << endl
             << "The data is: " << str;
        cout << endl
             << "The hash values are: h1 => " << h1 << " h2 => " << h2 << " h3 => "
             << h3 << " h4 => " << h4;
        printTables();
        int counts[4];
        counts[0] = table1[h1];
        counts[1] = table2[h2];
        counts[2] = table3[h3];
        counts[3] = table4[h4];
        int minCount = counts[0];
        for (int i = 1; i < 4; i++)
        {
            if (counts[i] < minCount)
                minCount = counts[i];
        }
        cout << endl
             << "The data has already been received " << minCount << " times";
    }
    void printTables()
    {
        cout << endl
             << "Hash Table 1" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << " " << table1[i];
        }
        cout << endl;
        cout << endl
             << "Hash Table 2" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << " " << table2[i];
        }
        cout << endl;
        cout << endl
             << "Hash Table 3" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << " " << table3[i];
        }
        cout << endl;
        cout << endl
             << "Hash Table 4" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << " " << table4[i];
        }
        cout << endl;
    }
};
int main()
{
    int continueInput = 1;
    string inputData;
    CountMinSketch cms;
    do
    {
        cout << endl
             << "Enter the data: ";
        cin >> inputData;
        cms.insertValue(inputData);
        cout << endl
             << "Do you want to enter other data (0/1): ";
        cin >> continueInput;
    } while (continueInput != 0);
    do
    {
        cout << endl
             << "Enter the data for search: ";
        cin >> inputData;
        cms.getCount(inputData);
        cout << endl
             << "Do you want to search other data (0/1): ";
        cin >> continueInput;
    } while (continueInput != 0);
    return 0;
}

/*
Enter the data: abc
a 97
b 98
c 99
The number is : 294
Hash Table 1
0 0 0 0 0 0 0 0 0 0
Hash Table 2
0 0 0 0 0 0 0 0 0 0
Hash Table 3
0 0 0 0 0 0 0 0 0 0
Hash Table 4
0 0 0 0 0 0 0 0 0 0
The hash values are: h1 => 0 h2 => 5 h3 => 0 h4 => 5
Hash Table 1
1 0 0 0 0 0 0 0 0 0
Hash Table 2
0 0 0 0 0 1 0 0 0 0
Hash Table 3
1 0 0 0 0 0 0 0 0 0
Hash Table 4
0 0 0 0 0 1 0 0 0 0
Do you want to enter other data (0/1)1
Enter the data: def
d 100
e 101
f 102
The number is : 303
Hash Table 1
1 0 0 0 0 0 0 0 0 0
Hash Table 2
0 0 0 0 0 1 0 0 0 0
Hash Table 3
1 0 0 0 0 0 0 0 0 0
Hash Table 4
0 0 0 0 0 1 0 0 0 0
The hash values are: h1 => 8 h2 => 2 h3 => 6 h4 => 0
Hash Table 1
1 0 0 0 0 0 0 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 0
Hash Table 3
1 0 0 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 1 0 0 0 0
Do you want to enter other data (0/1)1
Enter the data: ghi
g 103
h 104
i 105
The number is : 312
Hash Table 1
1 0 0 0 0 0 0 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 0
Hash Table 3
1 0 0 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 1 0 0 0 0
The hash values are: h1 => 6 h2 => 9 h3 => 2 h4 => 5
Hash Table 1
1 0 0 0 0 0 1 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 1
Hash Table 3
1 0 1 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 2 0 0 0 0
Do you want to enter other data (0/1)0
Enter the data for search: abc
a 97
b 98
c 99
The data is: abc
The hash values are: h1 => 0 h2 => 5 h3 => 0 h4 => 5
Hash Table 1
1 0 0 0 0 0 1 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 1
Hash Table 3
1 0 1 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 2 0 0 0 0
The data has already been received 1 times
Do you want to search other data (0/1)1
Enter the data for search: def
d 100
e 101
f 102
The data is: def
The hash values are: h1 => 8 h2 => 2 h3 => 6 h4 => 0
Hash Table 1
1 0 0 0 0 0 1 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 1
Hash Table 3
1 0 1 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 2 0 0 0 0
The data has already been received 1 times
Do you want to search other data (0/1)1
Enter the data for search: ghi
g 103
h 104
i 105
The data is: ghi
The hash values are: h1 => 6 h2 => 9 h3 => 2 h4 => 5
Hash Table 1
1 0 0 0 0 0 1 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 1
Hash Table 3
1 0 1 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 2 0 0 0 0
The data has already been received 1 times
Do you want to search other data (0/1)1
Enter the data for search: xyz
x 120
y 121
z 122
The data is: xyz
The hash values are: h1 => 8 h2 => 2 h3 => 6 h4 => 0
Hash Table 1
1 0 0 0 0 0 1 0 1 0
Hash Table 2
0 0 1 0 0 1 0 0 0 1
Hash Table 3
1 0 1 0 0 0 1 0 0 0
Hash Table 4
1 0 0 0 0 2 0 0 0 0
The data has already been received 1 times
Do you want to search other data (0/1)0
*/