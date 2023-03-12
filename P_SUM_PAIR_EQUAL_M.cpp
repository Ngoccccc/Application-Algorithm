#include <bits/stdc++.h>

using namespace std;

int n, M;
int a[1000001];

int main()
{

    cin >> n >> M;
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    int res = 0;

    for (int i = 1; i < 1000001; i++)
    {
        if (a[i] == 1 && a[M - i] == 1 && i != M - i)
        {
            res++;
            a[i] = 0;
            a[M - i] = 0;
        }
    }

    cout << res << endl;

    return 0;
}
