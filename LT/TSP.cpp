#include "bits/stdc++.h"
#define MAX 100
using namespace std;

int n;                       // số điểm đên
int f = 0;                   // quãng đường
int f_min = 10000000;        // quãng đường nhỏ nhất
bool visited[MAX] = {false}; // kiểm tra xem điểm a đi qua chưa
int c[MAX][MAX];             // distance of a and b
int distance_min = 10000000; // khoảng cách nhỏ nhất dùng cho nhánh và cận

// đọc dữ liệu
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            if (i != j)
                distance_min = min(distance_min, c[i][j]);
        }
    }
}
// Kiểm tra nếu v được thăm rồi thì trả về false và ngc lại
bool check(int v)
{
    if (visited[v])
        return false;
    return true;
}

// tính f_min
void solution()
{
    f_min = min(f_min, f);
}
// bắt đầu từ điểm k và toạ độ trước đó là v
void Try(int k, int v)
{
    for (int i = 1; i <= n; i++)
    {
        // kiểm tra
        if (check(i))
        {
            // gán đã thăm và cộng thêm tuyến đường
            visited[i] = true;
            f += c[v][i];
            // đưa ra kết quả khi đi hết tất cả
            if (k == n)
            {
                // cộng thêm quãng đường về 1
                f += c[i][1];
                solution();
                // trừ quãng đường về 1
                f -= c[i][1];
            } // Kiểm tra xem quãng đường tối thiểu nếu mà nhỏ hơn thì gọi tiếp và ngc lại
            else if (f + (n - k + 1) * distance_min < f_min)
                Try(k + 1, i);
            // quay lui
            visited[i] = false;
            f -= c[v][i];
        }
    }
}

int main()
{
    init();
    // bắt đầu từ điểm 1 nên gán nó = true
    visited[1] = true;
    // bắt đầu try từ điểm 2
    Try(2, 1);
    cout << f_min;
    return 0;
}