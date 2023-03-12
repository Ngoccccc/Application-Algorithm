#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];
unordered_map<int, int> m;

int main()
{
    ifstream cin("input.txt");
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (m.count(a[i] - 1) > 0)
            {
                m[a[i]] = m[a[i] - 1] + 1;
            }
            else
            {
                m[a[i]] = 1;
            }
            ans = max(ans, m[a[i]]);
        }
        cout << ans << endl;
    }

    return 0;
}