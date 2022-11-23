#include "../stdc++.h"
using namespace std;

map<string, int> numberCalls, timeCall;

int checkPhone(string phone)
{
    if (phone.length() != 10)
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (!(phone[i] <= '9' && phone[i] >= '0'))
            return false;
    }
    return true;
}

int timeCalls(string ftime, string ltime)
{
    int startTime = ((ftime[0] - '0') * 10 + (ftime[1] - '0')) * 3600 +
                    ((ftime[3] - '0') * 10 + (ftime[4] - '0')) * 60 +
                    ((ftime[6] - '0') * 10 + (ftime[7] - '0'));

    int endTime = ((ltime[0] - '0') * 10 + (ltime[1] - '0')) * 3600 +
                  ((ltime[3] - '0') * 10 + (ltime[4] - '0')) * 60 +
                  ((ltime[6] - '0') * 10 + (ltime[7] - '0'));
    return endTime - startTime;
}

int main()
{
    string type;
    cin >> type;
    string phone1, phone2, date, ftime, ltime;
    int incorectTimes = 0;
    int totalCall = 0;
    string request, phone;
    do
    {
        cin >> phone1 >> phone2 >> date >> ftime >> ltime;
        if (!checkPhone(phone1) || !checkPhone(phone2))
            incorectTimes += 1;
        numberCalls[phone1] += 1;
        totalCall += 1;
        timeCall[phone1] += timeCalls(ftime, ltime);
        cin >> type;
    } while (type != "#");
    cout << endl;
    do
    {
        cin >> request;

        if (request == "?check_phone_number")
        {
            if (incorectTimes == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (request == "?number_calls_from")
        {
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if (request == "?number_total_calls")
            cout << totalCall << endl;

        else if (request == "?count_time_calls_from")
        {
            cin >> phone;
            cout << timeCall[phone] << endl;
        }

    } while (request != "#");

    return 0;
}
