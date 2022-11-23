#include "bits/stdc++.h"
using namespace std;

bool square[4][4][10]; // lưu trữ các điểm đã được điền trong hình vuông 3x3
bool row[10][10];      // lưu trữ các điểm đã được điền trong hàng
bool col[10][10];      // lưu trữ các điểm đã được điền trong cột
bool visited[10][10]; // lưu trữ các điểm đã thêm
int results;            // tổng số lời giải đã tìm được

void init()
{
    int a;
    int r; // row
    int c; // col
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> a;
            if (a != 0)
            {
                r = ceilf((float)i / 3);
                c = ceilf((float)j / 3);
                // điểm đó tồn tại trên hàng
                row[i][a] = true;
                // điểm đó tồn tại trên cột
                col[j][a] = true;
                // điểm đó tồn tại trên hình vuông 3x3
                square[r][c][a] = true;
                // điểm này đã được xuất hiện
                visited[i][j] = true;
            }
        }
    }
}
bool check(int k1, int k2, int a)
{

    int r = ceilf((float)k1 / 3);
    int c = ceilf((float)k2 / 3);
    // Nếu vi phạm 1 trong các dk thì sẽ trả về false. Dk trong đề bài
    if (square[r][c][a] || row[k1][a] || col[k2][a])
        return false;

    return true;
}
// k1 là hàng, k2 là cột
void Try(int k1, int k2)
{
    int r, c;
    // Nếu vị trí này đã được điền từ trc rồi thì thôi next qua điểm tiếp
    if (visited[k1][k2])
    {
        // k2 == 9 thì nhảy sang dòng tiếp theo
        if (k2 != 9)
            Try(k1, k2 + 1);
        else // không thì tăng cột
            Try(k1 + 1, 1);
    }
    else
    {
        for (int a = 1; a <= 9; a++)
        {

            if (check(k1, k2, a))
            {

                r = ceilf((float)k1 / 3);
                c = ceilf((float)k2 / 3);
                // cho điểm này tồn tại trong square
                square[r][c][a] = true;
                // cho điểm này tồn tại trong row
                row[k1][a] = true;
                // cho điểm này tồn tại trong col
                col[k2][a] = true;
                // nếu hàng = 9 và cột  = 9 thì thêm 1 lời giải
                if (k1 == 9 && k2 == 9)
                {
                    results++;
                }
                else // không thì try thôi
                {
                    if (k2 != 9)
                        Try(k1, k2 + 1);
                    else
                        Try(k1 + 1, 1);
                }
                // loại bỏ điểm đó ra khỏi danh sách tồn tại
                square[r][c][a] = false;
                row[k1][a] = false;
                col[k2][a] = false;
            }
        }
    }
}

int main()
{
    init();
    // chạy từ hàng 1 cột 1
    Try(1, 1);
    cout << results;
    return 0;
}