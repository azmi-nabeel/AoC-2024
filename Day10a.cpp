#include <bits/stdc++.h>

using namespace std;

int m, n;

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void dfs(int i, int j, vector<string> &g, set<pair<int, int>> &st)
{
    if (g[i][j] == '9')
    {
        st.insert({i, j});
        return;
    }
    if (isValid(i - 1, j) && g[i - 1][j] - 1 == g[i][j])
        dfs(i - 1, j, g, st);
    if (isValid(i + 1, j) && g[i + 1][j] - 1 == g[i][j])
        dfs(i + 1, j, g, st);
    if (isValid(i, j + 1) && g[i][j + 1] - 1 == g[i][j])
        dfs(i, j + 1, g, st);
    if (isValid(i, j - 1) && g[i][j - 1] - 1 == g[i][j])
        dfs(i, j - 1, g, st);
}

void solve()
{
    vector<string> g;

    string line;

    while (getline(cin, line))
    {
        g.push_back(line);
    }

    m = g.size(), n = g[0].size();

    int ans = 0;

    vector<int> grad = {-1, 0, 1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '0')
            {
                set<pair<int, int>> st;
                dfs(i, j, g, st);
                ans += st.size();
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
