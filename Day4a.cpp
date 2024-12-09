#include <bits/stdc++.h>

using namespace std;

const string word = "XMAS";
const int sz = 4;

int m, n;

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void dfs(int i, int j, vector<string> &g, int dx, int dy, int id, int &ans)
{
    if (id >= sz)
        return;
    if (id == sz - 1)
    {
        if (g[i][j] == word[id])
        {
            ans++;
            return;
        }
    }
    if (g[i][j] == word[id])
    {
        if (isValid(i + dx, j + dy))
            dfs(i + dx, j + dy, g, dx, dy, id + 1, ans);
    }
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
            if (g[i][j] == 'X')
            {
                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; b++)
                    {
                        if (grad[a] == 0 && grad[b] == 0)
                            continue;
                        dfs(i, j, g, grad[a], grad[b], 0, ans);
                    }
                }
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
