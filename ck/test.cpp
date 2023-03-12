#include <bits/stdc++.h>

using namespace std;

int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    string test = "2020-01-04";
    string tgian = "14:08:55";
    int thang = (test[5] - '0') * 10 + (test[6] - '0');
    int ngay = (test[8] - '0') * 10 + (test[9] - '0');
    int timeTheoGiay = ((tgian[0] - '0') * 10 + (tgian[1] - '0')) * 3600 + ((tgian[3] - '0') * 10 + (tgian[4] - '0')) * 60 + ((tgian[6] - '0') * 10 + (tgian[7] - '0'));
    int time;
    for (int i = 0; i < thang; i++)
    {
        time += month[i] + ngay;
    }

    int timeTheoGiay2 = time * 24 * 3600 + ((tgian[0] - '0') * 10 + (tgian[1] - '0')) * 3600 + ((tgian[3] - '0') * 10 + (tgian[4] - '0')) * 60 + ((tgian[6] - '0') * 10 + (tgian[7] - '0'));
    cout << timeTheoGiay2 << endl;
}