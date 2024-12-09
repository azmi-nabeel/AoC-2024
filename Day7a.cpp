#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long int

vector<string> splitStrings(string str, char dl)
{
    string word = "";

    int num = 0;

    str = str + dl;

    int l = str.size();

    vector<string> substr_list;
    for (int i = 0; i < l; i++)
    {
        if (str[i] != dl)
            word = word + str[i];

        else
        {
            if ((int)word.size() != 0)
                substr_list.push_back(word);
            word = "";
        }
    }
    return substr_list;
}

void check(int tst, vector<int> &val, int id, int currVal, int z, bool &f)
{
    if (f)
        return;
    // cout<<id<<" "<<currVal<<" "<<f;
    // cout<<endl;
    if (id == z - 1)
    {
        f = ((currVal * val[id] == tst) || (currVal + val[id] == tst));
        return;
    }
    if (currVal > tst)
        return;
    check(tst, val, id + 1, currVal * val[id], z, f);
    check(tst, val, id + 1, currVal + val[id], z, f);
}

void solve()
{
    vector<vector<int>> a;
    vector<int> tst;

    string line;

    while (getline(cin, line))
    {
        vector<string> tokens;
        tokens = splitStrings(line, ':');
        tst.push_back(stoull(tokens[0]));
        tokens = splitStrings(tokens[1], ' ');
        vector<int> temp;
        for (auto &x : tokens)
            temp.push_back(stoull(x));
        a.push_back(temp);
    }

    int ans = 0, sz = tst.size();

    for (int i = 0; i < sz; i++)
    {
        bool f = 0;
        int z = a[i].size();
        check(tst[i], a[i], 1, a[i][0], z, f);
        if (f)
            ans += tst[i];
    }

    cout << ans << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE

    freopen("inp.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    solve();

    return 0;
}
