#include "bits/stdc++.h"
#define MAX 100
using namespace std;

// variable
int results[MAX]; // kết quả
int n;            // giá trị 1,...n
int visited[MAX]; // Mảng chứa xem cái điểm đó được thăm chưa

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        visited[i] = false;
}

bool check(int i)
{
    if (visited[i])
        return false;
    return true;
}
void solution()
{
    for (int i = 1; i <= n; i++)
        cout << results[i] << " ";
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            visited[i] = true;
            results[k] = i;
            if (k == n)
                solution();
            else
                Try(k + 1);

            visited[i] = false;
        }
    }
}

int main()
{
    init();
    Try(1);
    return 0;
}