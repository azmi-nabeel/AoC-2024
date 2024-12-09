#include <bits/stdc++.h>

using namespace std;

const string word = "XMAS";
const int sz = 4;

int m, n;

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

    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            bool f = 0;
            if (g[i][j] == 'A')
            {
                f = (g[i - 1][j - 1] == 'M' && g[i + 1][j + 1] == 'S') || ((g[i - 1][j - 1] == 'S' && g[i + 1][j + 1] == 'M'));
                f &= (g[i - 1][j + 1] == 'M' && g[i + 1][j - 1] == 'S') || ((g[i - 1][j + 1] == 'S' && g[i + 1][j - 1] == 'M'));
            }
            ans += f;
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
