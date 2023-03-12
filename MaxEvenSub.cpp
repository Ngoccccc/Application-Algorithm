#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 10000001
int a[N];
int maxSum = INT_MIN;
long long SC[N], SL[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > maxSum && sum % 2 == 0)
            {
                maxSum = sum;
            }
        }
    }
    cout << maxSum << endl;
    return 0;
}