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
    int i = 0, l = sz - 1;
    long long ans = 0;
    for (; i < l; i++)
    {
        if (dsk[i] == -1)
        {
            while (l > i && dsk[l] == -1)
                l--;
            if (i >= l)
                break;
            swap(dsk[i], dsk[l]);
        }
        if (dsk[i] != -1)
            ans += 1LL * i * dsk[i];
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
