#include <bits/stdc++.h>

using namespace std;

vector<string> g;
int m, n;
vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

bool isValid(int i, int j, char c)
{
    return (i >= 0 && j >= 0 && i < m && j < n && g[i][j] == c);
}

void dfs(int i, int j, char c, int &area, int &diam, vector<vector<bool>> &vis)
{
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    area++;
    for (int id = 0; id < 4; id++)
    {
        if (isValid(i + di[id], j + dj[id], c))
        {
            dfs(i + di[id], j + dj[id], c, area, diam, vis);
        }
        else
            diam++;
    }
}

void solve()
{
    string line;

    while (getline(cin, line))
    {
        g.push_back(line);
    }

    m = g.size(), n = g[0].size();

    int ans = 0;

    vector<vector<bool>> vis(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                int area = 0, diam = 0;
                dfs(i, j, g[i][j], area, diam, vis);
                ans += (area * diam);
            }
        }
    }

    cout << ans << endl;
}

int main()
{

#ifndef ONLINE_JUDGE

    freopen("inp.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    solve();

    return 0;
}
