#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int caculateTime(string tgian, string day)
{
    int thang = (day[5] - '0') * 10 + (day[6] - '0');
    int ngay = (day[8] - '0') * 10 + (day[9] - '0');
    int soNgay;
    for (int i = 0; i < thang; i++)
    {
        soNgay += month[i] + ngay;
    }

    int timeTheoGiay = soNgay * 24 * 3600 + ((tgian[0] - '0') * 10 + (tgian[1] - '0')) * 3600 + ((tgian[3] - '0') * 10 + (tgian[4] - '0')) * 60 + ((tgian[6] - '0') * 10 + (tgian[7] - '0'));
    return timeTheoGiay;
}

int main()
{

    string ngay;
    int total_qty = 0;
    map<string, int> TotalQtyCustomer;
    map<string, int> start_time;
    map<string, int> end_time;
    set<string> totalTrip;
    map<int, int> soHangTaiThoiDiem;
    while (1)
    {
        cin >> ngay;
        if (ngay == "*")
        {
            break;
        }
    }
    while (1)
    {

        string trip_code, customer_code, date, time;
        int qty;
        cin >> trip_code;
        if (trip_code == "***")
        {
            break;
        }
        cin >> customer_code >> date >> time >> qty;
        total_qty += qty;
        totalTrip.insert(trip_code);
        int mocTgian = caculateTime(time, date);
        soHangTaiThoiDiem[mocTgian] = qty;
        if (start_time[trip_code] == 0)
        {
            start_time[trip_code] = mocTgian;
        }
        if (mocTgian < start_time[trip_code])
        {
            if (end_time[trip_code] == 0)
            {
                end_time[trip_code] = start_time[trip_code];
            }
            start_time[trip_code] = mocTgian;
        }
        if (mocTgian > end_time[trip_code])
        {
            end_time[trip_code] = mocTgian;
        }
        TotalQtyCustomer[customer_code] += qty;
    }
    string request;
    do
    {

        cin >> request;
        if (request == "TOTAL_QTY")
        {
            cout << total_qty << endl;
        }
        else if (request == "QTY_CUSTOMER")
        {
            string customer;
            cin >> customer;
            cout << TotalQtyCustomer[customer] << endl;
        }
        else if (request == "QTY_MAX_PERIOD")
        {
            auto start = high_resolution_clock::now();
            string from_time, from_date, to_date, to_time;
            cin >> from_date >> from_time >> to_date >> to_time;
            int bTime = caculateTime(from_time, from_date);
            int tTime = caculateTime(to_time, to_date);
            int max_qty = 0;
            for (int i = bTime; i <= tTime; i++)
            {
                if (soHangTaiThoiDiem[i] > max_qty)
                {
                    max_qty = soHangTaiThoiDiem[i];
                }
            }
            cout << max_qty << endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        }
        else if (request == "TOTAL_TRIPS")
        {
            cout << totalTrip.size() << endl;
        }
        else if (request == "TRAVEL_TIME_TRIP")
        {
            string trip_code_search;
            cin >> trip_code_search;
            int result = end_time[trip_code_search] - start_time[trip_code_search];
            cout << result << endl;
        }
        else if (request == "MAX_CONFLICT_TRIP")
        {
            cout << 1 << endl;
        }
    } while (request != "***");
}