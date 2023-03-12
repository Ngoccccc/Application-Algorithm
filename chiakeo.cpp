#include <iostream>

using namespace std;

int x[11];
int m, n;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += x[i];
    }
    return sum == m;
}
void Try(int k)
{
    for (int i = 1; i <= m - n + 1; i++)
    {
        x[k] = i;
        if (k == n)
        {
            if (check())
            {
                solution();
            }
        }
        else
        {
            Try(k + 1);
        }
        x[k] = 0;
    }
}

int main()
{
    m = 5;
    n = 3;
    Try(1);
    return 0;
}