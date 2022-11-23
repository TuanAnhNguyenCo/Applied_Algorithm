#include "bits/stdc++.h"
using namespace std;

map<int, int> number;
vector<int> arr;
int n, M;
int results = 0;

void init()
{
    cin >> n >> M;
    int a;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        arr.push_back(a);
        number[a] = 1;
    }
}

int main()
{
    init();
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        // Xét đến nó rồi thì trừ đi 1 nghĩa là k qtam đến nó nx
        // Dù cho M - *it có hay không thì vẫn -1 thôi
        // Nó sẽ giúp tránh trường hợp M = *it * 2, và tránh lặp lại khi tìm kq của M - *it
        number[*it]--;
        if (number[M - *it] == 1)
        {
            results += number[M - *it]--;
        }
    }
    cout << results;

    return 0;
}