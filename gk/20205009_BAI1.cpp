#include <bits/stdc++.h>

using namespace std;
int n, k, m;
int x[1000001];

int main()
{
    int count = 0;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= i + k - 1; j++)
        {
            sum += x[j];
        }
        if (sum == m)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}