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

void dfs(int i, int j, char c, int &area, vector<map<int, vector<int>>> &sides, vector<vector<bool>> &vis)
{
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    area++;
    for (int id = 0; id < 4; id++)
    {
        if (isValid(i + di[id], j + dj[id], c))
        {
            dfs(i + di[id], j + dj[id], c, area, sides, vis);
        }
        else if (id % 2 == 1)
        {
            sides[id][j].push_back(i);
        }
        else
            sides[id][i].push_back(j);
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
                int area = 0;
                vector<map<int, vector<int>>> sides(4);
                dfs(i, j, g[i][j], area, sides, vis);
                for (auto &mp : sides)
                {
                    int cnt = 0;
                    for (auto it = mp.begin(); it != mp.end(); it++)
                    {
                        int prev = -2;
                        sort(it->second.begin(), it->second.end());
                        // cout << it->first << " : ";
                        for (auto &ab : it->second)
                        {
                            // cout << ab << " ";
                            if (ab != prev + 1)
                            {
                                cnt++;
                                // cout << cnt << " " << it->first << " " << ab << endl;
                            }
                            prev = ab;
                        }
                        // cout << endl;
                    }
                    // cout << endl;
                    ans += (area * cnt);
                }
                // cout << ans << " " << g[i][j] << " " << area << endl;
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
