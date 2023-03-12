#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int x, y;
int n;
int a[N];
int s[N];
int cnt = 0;
int max_Sum = INT_MIN;
void printSubset(int cur)
{
    if (cur == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (a[i] && (i == 0 || a[i - 1] == 0))
                sum += s[i];
        if (sum > max_Sum)
        {
            max_Sum = sum;
        }
        return;
    }
    a[cur] = 1;
    printSubset(cur + 1);
    a[cur] = 0;
    printSubset(cur + 1);
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    printSubset(0);
    cout << max_Sum;
    return 0;
}