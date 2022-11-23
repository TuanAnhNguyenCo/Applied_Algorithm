#include "bits/stdc++.h"
#define MAX 50
using namespace std;

int results[MAX]; // mảng chứa kết quả
int n;

void init()
{
    cin >> n;
}
void solution()
{
    for (int i = 1; i <= n; i++)
        cout << results[i];
    cout << endl;
}
bool check()
{
    return true;
}
void Try(int k)
{
    for (int i = 0; i <= 1; i++) // giá trị nhận chỉ có thể là 0 or 1
    {
        if (check()) // kiểm tra điều kiện
        {
            results[k] = i;
            if (k == n) // đủ số phần tử cần rồi thì đưa ra lời giải
                solution();
            else // chưa đủ thì gọi tiếp
                Try(k + 1);
        }
    }
}

int main()
{
    init();
    Try(1);
    return 0;
}