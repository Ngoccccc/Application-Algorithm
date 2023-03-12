#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 2;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            res++;
            dfs(i);
        }
    }

    cout << res << endl;

    return 0;
}
