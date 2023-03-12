#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000000];
int b[1000000];
int cnt;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i <= 1; ++i)
    {
        b[k] = i;
        if (k == n)
        {
            solution();
            cnt++;
        }
        else
        {
            Try(k + 1);
        }
        b[k] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    Try(1);
    cout << cnt;
    return 0;
}