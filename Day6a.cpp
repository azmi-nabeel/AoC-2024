#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void dfs(vector<string> &g, int i, int j, int &id, int &ans, vector<vector<bool>> &vis)
{
    if (!vis[i][j])
    {
        vis[i][j] = 1;
        ans++;
    }
    if (isValid(i + di[id], j + dj[id]))
    {
        int ni = i + di[id];
        int nj = j + dj[id];
        if (g[ni][nj] == '#')
        {
            id = (id + 1) % 4;
            dfs(g, i, j, id, ans, vis);
        }
        else
            dfs(g, ni, nj, id, ans, vis);
    }
}

void solve()
{
    vector<string> g;

    string line;

    int diri = -1, dirj = -1;

    while (getline(cin, line))
    {
        g.push_back(line);
        auto f = line.find('^');
        if (f != string::npos)
        {
            dirj = line.find('^');
            diri = g.size() - 1;
        }
    }

    m = g.size(), n = g[0].size();

    int ans = 0, id = 0;

    vector<vector<bool>> vis(m, vector<bool>(n));

    dfs(g, diri, dirj, id, ans, vis);

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
