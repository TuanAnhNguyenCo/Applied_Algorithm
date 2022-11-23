#include "bits/stdc++.h"
using namespace std;

string number1, number2, results = "";
int surplus = 0;

void paddingNumber()
{

    for (int i = 0; i < (int)number1.length() - (int)number2.length(); i++)
    {
        number2.insert(0, "0");
    }

    for (int i = 0; i < (int)number2.length() - (int)number1.length(); i++)
    {
        number1.insert(0, "0");
    }
}

void addTwoNumber()
{
    int sumOfTwoNumber;
    for (int i = (int)number1.length() - 1; i >= 0; i--)
    {
        // tính tổng có kèm số dư
        sumOfTwoNumber = (number1[i] - '0') + (number2[i] - '0') + surplus;
        // tính dư
        surplus = sumOfTwoNumber / 10;
        // thêm kết quả vào
        results.insert(0, to_string(sumOfTwoNumber % 10));
    }
    // còn dư thì thêm nó vào đầu thôi
    if (surplus)
        results.insert(0, to_string(surplus));
}

int main()
{
    cin >> number1 >> number2;

    paddingNumber();
    addTwoNumber();
    cout << results;
    return 0;
}