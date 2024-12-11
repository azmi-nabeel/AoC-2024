#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, long long> dp;

vector<string> splitStrings(string str, char dl)
{
    string word = "";
    long long num = 0;
    str = str + dl;
    long long l = str.size();
    vector<string> substr_list;
    for (long long i = 0; i < l; i++)
    {
        if (str[i] != dl)
            word = word + str[i];
        else
        {
            if ((long long)word.size() != 0)
                substr_list.push_back(word);
            word = "";
        }
    }
    return substr_list;
}

long long numDigits(long long a)
{
    long long ret = 0;
    while (a > 0)
    {
        a /= 10;
        ret++;
    }
    return ret;
}

long long find(long long x, long long t)
{
    if (t == 0)
    {
        dp[{x, t}] = 1;
    }
    if (dp.count({x, t}))
        return dp[{x, t}];
    if (x == 0)
        return dp[{x, t}] = find(1, t - 1);

    long long l = numDigits(x);
    if (l % 2 == 0)
    {
        string num = to_string(x);
        return dp[{x, t}] = find(stoll(num.substr(0, l / 2)), t - 1) + find(stoll(num.substr(l / 2)), t - 1);
    }
    return dp[{x, t}] = find(x * 2024, t - 1);
}

void solve()
{
    vector<long long> a;
    string line;

    while (getline(cin, line))
    {
        vector<string> tokens;
        tokens = splitStrings(line, ' ');
        for (auto &x : tokens)
            a.push_back(stoll(x));
    }

    long long ans = 0;

    for (auto &x : a)
    {
        ans += find(x, 75);
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
