#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string line;

    while (getline(cin, line))
        ;
    int sz = line.size(), id = 0;
    vector<int> dsk;
    for (int i = 0; i < sz; i++)
    {
        int n = line[i] - '0';
        if (i & 1)
        {
            for (int j = 0; j < n; j++)
                dsk.push_back(-1);
        }
        else
        {
            for (int j = 0; j < n; j++)
                dsk.push_back(id);
            id++;
        }
    }
    sz = dsk.size();
    set<pair<int, int>> spaces;
    long long ans = 0, sum = 0;
    for (int i = 0; i < sz; i++)
    {
        // cout << dsk[i] << " ";
        if (dsk[i] != -1)
        {
            if (sum < 0)
                spaces.insert({i + sum, abs(sum)});
            sum = 0;
        }
        else
            sum += dsk[i];
    }
    cout << endl;
    if (sum < 0)
        spaces.insert({sz + sum, abs(sum)});

    int numId = -2, cnt = 0;

    for (int i = sz - 1; i >= 0; i--)
    {
        if (dsk[i] == numId)
        {
            cnt++;
        }
        else
        {
            if (numId >= 0)
            {
                pair<int, int> p = {-1, -1};
                for (auto it = spaces.begin(); it != spaces.end(); it++)
                {
                    if (it->second >= cnt)
                    {
                        p = (*it);
                        spaces.erase(spaces.find(*it));
                        if (p.second > cnt)
                            spaces.insert({p.first + cnt, p.second - cnt});
                        break;
                    }
                }
                if (p.first != -1 && p.first < i)
                {
                    for (int j = 0; j < cnt; j++)
                    {
                        dsk[p.first + j] = dsk[i + j + 1];
                        dsk[i + j + 1] = -1;
                    }
                }
            }
            if (dsk[i] != -1)
            {
                numId = dsk[i];
                cnt = 1;
            }
            else
            {
                numId = -2;
                cnt = 0;
            }
        }
    }

    // for (auto &x : dsk)
    //     cout << x << " ";
    // cout << endl;
    for (int i = 0; i < sz; i++)
        if (dsk[i] != -1)
            ans += 1LL * i * dsk[i];
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
