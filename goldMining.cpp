#include <bits/stdc++.h>

using namespace std;
int n, L1, L2;
int maxProfit = 0;
int x[100001];
int choice[100001];

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        choice[k] = i;
        if (i == 1)
        {
            for (int j = k - 1; j = 1; j--)
            {
                if (choice[j] = 1 && !((k - j) >= L1))
                {
                    choice[k] = 0;
                    break;
                }
                if (choice[j] = 0 && !((k - j) <= L2))
                {
                    choice[k] = 1;
                    break;
                }
            }
        }
        if (k == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << choice[j] << " ";
            }
            cout << endl;
        }
        else
        {
            Try(k + 1);
        }
        choice[k] = 0;
    }
}

int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    Try(1);
}