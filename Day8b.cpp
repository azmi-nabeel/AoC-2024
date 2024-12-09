#include <bits/stdc++.h>

using namespace std;

int m, n;

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void solve()
{
    vector<string> g;

    string line;

    unordered_map<char, vector<pair<int, int>>> ump;
    int i = 0;

    while (getline(cin, line))
    {
        g.push_back(line);
        for (int j = 0; j < line.size(); j++)
        {
            if (isalnum(line[j]))
            {
                ump[line[j]].push_back({i, j});
            }
        }
        i++;
    }

    m = g.size(), n = g[0].size();

    set<pair<int, int>> st;

    for (auto it = ump.begin(); it != ump.end(); it++)
    {
        auto v = it->second;
        int sz = v.size();
        if (sz < 2)
            continue;
        for (int i = 0; i < sz; i++)
        {
            st.insert({v[i].first, v[i].second});
            for (int j = i + 1; j < sz; j++)
            {
                pair<int, int> diff = {v[i].first - v[j].first, v[i].second - v[j].second};
                pair<int, int> Ianti = {v[i].first + diff.first, v[i].second + diff.second};
                while (1)
                {
                    if (isValid(Ianti.first, Ianti.second))
                    {
                        st.insert({Ianti.first, Ianti.second});
                        g[Ianti.first][Ianti.second] = '#';
                    }
                    else
                        break;
                    Ianti = {Ianti.first + diff.first, Ianti.second + diff.second};
                }
                diff = {-1 * diff.first, -1 * diff.second};
                pair<int, int> Janti = {v[j].first + diff.first, v[j].second + diff.second};
                while (1)
                {
                    if (isValid(Janti.first, Janti.second))
                    {
                        st.insert({Janti.first, Janti.second});
                        g[Janti.first][Janti.second] = '#';
                    }
                    else
                        break;
                    Janti = {Janti.first + diff.first, Janti.second + diff.second};
                }
            }
        }
    }

    for (auto &s : g)
    {
        cout << s << endl;
    }

    cout << st.size() << endl;
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
