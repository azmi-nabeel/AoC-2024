#include <bits/stdc++.h>

using namespace std;

vector<string> g;
int m, n, posX = -1, posY = -1;

unordered_map<char, pair<int, int>> dir;

void makeMove(char c)
{
    int di = dir[c].first;
    int dj = dir[c].second;
    int i = posX + di;
    int j = posY + dj;
    if (g[i][j] == '#')
        return;
    if (g[i][j] == '.')
    {
        g[i][j] = '@';
        g[posX][posY] = '.';
        posX = i;
        posY = j;
        return;
    }
    while (g[i][j] == 'O')
    {
        i += di;
        j += dj;
    }
    if (g[i][j] == '#')
        return;
    g[i][j] = 'O';
    g[posX + di][posY + dj] = '@';
    g[posX][posY] = '.';
    posX += di;
    posY += dj;
}

void solve()
{
    dir['^'] = {-1, 0};
    dir['>'] = {0, 1};
    dir['v'] = {1, 0};
    dir['<'] = {0, -1};

    string line;

    bool start = false;

    while (getline(cin, line))
    {
        if (line.size() < 4)
        {
            start = true;
            m = g.size(), n = g[0].size();
            cout << m << " " << n << endl;
            cout << posX << " " << posY << endl;
        }
        else
        {
            if (!start)
            {
                g.push_back(line);
                if (line.find('@') >= 0 && line.find('@') < line.size())
                {
                    posX = g.size() - 1;
                    posY = line.find('@');
                }
            }
            else
            {
                for (auto &c : line)
                {
                    makeMove(c);
                    // cout << c << endl;
                    // for (int i = 0; i < m; i++)
                    // {
                    //     for (int j = 0; j < n; j++)
                    //     {
                    //         cout << g[i][j];
                    //     }
                    //     cout << endl;
                    // }
                }
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 'O')
                ans += (100 * i) + j;
            cout << g[i][j];
        }
        cout << endl;
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
