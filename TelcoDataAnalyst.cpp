#include <bits/stdc++.h>
using namespace std;

typedef struct _time
{
    int hh;
    int mm;
    int ss;
} time_call;

int check_phone_number(string numberPhone)
{
    if (numberPhone.length() != 10)
        return 0;
    for (int i = 0; i < numberPhone.length(); i++)
    {
        if (numberPhone[i] < '0' || numberPhone[i] > '9')
            return 0;
    }
    return 1;
}

int timeCaculate(time_call startTime, time_call endTime)
{
    int time = endTime.hh * 3600 + endTime.mm * 60 + endTime.ss - (startTime.hh * 3600 + startTime.mm * 60 + startTime.ss);
    return time;
}

map<string, int> totalCalls, timeCalls;
int main()
{
    int incorrectNumber = 0;
    int totalCallData = 0;
    string call;

    while (1)
    {
        string request;
        string fromN, toN, date;
        time_call startTime, endTime;
        cin >> request;

        if (request == "#")
        {
            break;
        }
        if (request == "call")
        {
            cin >> fromN >> toN >> date;
            scanf("%d:%d:%d %d:%d:%d", &startTime.hh, &startTime.mm, &startTime.ss, &endTime.hh, &endTime.mm, &endTime.ss);
        }
        if (!check_phone_number(fromN))
            incorrectNumber++;
        if (!check_phone_number(toN))
            incorrectNumber++;
        totalCalls[fromN]++;
        timeCalls[fromN] += timeCaculate(startTime, endTime);
        totalCallData++;
    }
    do
    {
        cin >> call;
        string S;
        if (call == "#")
            break;
        if (call == "?check_phone_number")
        {
            if (incorrectNumber == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (call == "?number_calls_from")
        {
            cin >> S;
            cout << totalCalls[S] << endl;
        }
        else if (call == "?number_total_calls")
        {
            cout << totalCallData << endl;
        }
        else if (call == "?count_time_calls_from")
        {
            cin >> S;
            cout << timeCalls[S] << endl;
        }
        else
        {
            break;
        }
    } while (call != "#");
}