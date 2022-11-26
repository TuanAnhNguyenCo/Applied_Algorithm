// https : // openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/PARENTHESES
#include <bits/stdc++.h>
using namespace std;

stack<char> store; // lưu trữ các dấu ngoặc mở
string input;      // chuỗi đầu vào để kiểm tra

void init()
{
    cin >> input;
}
bool check(char a, char b)
{
    // Nếu thoả mãn là 1 cặp ngoạc thì trả về true thôi
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    return false;
}

void solution()
{
    bool errorFlag = false;
    char c;
    for (int i = 0; i < input.length(); i++)
    {
        // nếu là ngoặc mở thì đưa vào stack
        if (input[i] == '[' || input[i] == '{' || input[i] == '(')
            store.push(input[i]);
        else
        { // nếu là ngoặc đóng thì kiểm tra xem store còn ngoặc đóng k
            // nếu k còn gắn cờ và thoát
            if (store.empty())
            {
                errorFlag = true;
                break;
            }
            else
            {
                // lấy dữ liệu ra và check ngoặc thôi
                // không thoả mãn sẽ gán cờ và thoát
                c = store.top();
                store.pop();
                if (!check(c, input[i]))
                {
                    errorFlag = true;
                    break;
                }
            }
        }
    }
    // duyệt hết rồi mà trong store vẫn còn ngoặc mở thì chuỗi đó sẽ sai
    if (!store.empty())
        errorFlag = true;
    // in kết quả thôi hihi
    if (!errorFlag)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    init();
    solution();
    return 0;
}