#include "bits/stdc++.h"
#define MAX 50000
using namespace std;

int visited[MAX] = {false}; // true khi số này có trong db rồi
string seq[MAX];            // số chữ số 0 cần padding vào đầu vd seq[1] = '0'
int number_max;             // số lớn nhất có trong db
int n, L, m;                // tham số đầu vào

void init()
{
    cin >> n >> L >> m;
    int a;
    for (int i = 1; i <= n; i++)
    {
        // thêm các số đã tồn tại vào và tìm số max
        cin >> a;
        visited[a] = true;
        number_max = max(number_max, a);
    }
    for (int i = 1; i <= L; i++)
    {
        // số chữ số 0 cần padding vào đầu vd seq[1] = '0'
        seq[i] = seq[i - 1] + "0";
    }
}

int main()
{
    int dem = 0, i = 1;
    string a;
    init();
    // nếu thêm đủ m số vào rồi thì thôi
    while (dem != m)
    {
        // hiển thị ra thôi
        a = to_string(i);
        cout << seq[L - a.length()] + a << endl;
        // nếu nó chưa thăm thì tăng đếm
        if (!visited[i])
            dem++;
        // đi đến số tiếp theo
        i++;
    }
    // in nốt các số đã có trong db
    while (i <= number_max)
    {
        if (visited[i])
        {
            a = to_string(i);
            cout << seq[L - a.length()] + a << endl;
        }

        i++;
    }

    return 0;
}