#include "bits/stdc++.h"
using namespace std;

int characters[8]; // 1 -> 7  <=> I, C, T, H, U, S, K
int N;
int cnt;
bool visited[10];

// ICT - K62 + HUST = N
void solution()
{
    cnt += (N == (characters[1] * 100 + characters[2] * 10 + characters[3] - (characters[7] * 100 + 62) + characters[4] * 1000 + characters[5] * 100 + characters[6] * 10 + characters[3]));
}
void Try(int k)
{
    for (int i = 1; i <= 9; i++)
    {
        if (!visited[i])
        {
            characters[k] = i;
            visited[i] = true;
            if (k == 7)
                solution();
            else
                Try(k + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> N;
    Try(1);
    cout << cnt;
    return 0;
}