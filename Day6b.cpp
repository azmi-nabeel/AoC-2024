#include <bits/stdc++.h>
using namespace std;

int m, n, start_direction = 0;

vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

vector<vector<int>> dir(130, vector<int>(130, -1));

bool isValid(vector<string> &g, int i, int j, int direction)
{
    int ni = i + di[direction];
    int nj = j + dj[direction];
    if (ni < 0 || ni >= g.size() || nj < 0 || nj >= g[0].size())
        return true;
    if (g[ni][nj] == '#')
        return false;
    return true;
}

bool simulate(vector<string> &g, int i, int j, int direction)
{
    int cnt = 1;
    while (i >= 0 && i < g.size() && j >= 0 && j < g[0].size() and cnt < 10000000)
    {
        if (isValid(g, i, j, direction))
        {
            if (g[i][j] == 'X' and dir[i][j] == direction)
            {
                return true;
            }
            g[i][j] = 'X';
            dir[i][j] = direction;
            i += di[direction];
            j += dj[direction];
        }
        else
        {
            direction = (direction + 1) % 4;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

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

    vector<string> copy = g;

    start_direction = 0;
    simulate(g, diri, dirj, 0);

    int ans = 0;

    for (int i = 0; i < 130; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (g[i][j] == 'X')
            {
                vector<string> temp = copy;
                temp[i][j] = '#';
                if (simulate(temp, diri, dirj, start_direction))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}