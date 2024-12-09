#include <bits/stdc++.h>

using namespace std;

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

void solve()
{
    vector<long long> a;

    unordered_map<long long, long long> b;

    string line;

    while (getline(cin, line))
    {
        vector<string> tokens;
        tokens = splitStrings(line, ' ');
        a.push_back(stoll(tokens[0]));
        b[stoll(tokens[1])]++;
    }

    long long ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (b.count(a[i]))
        {
            ans += (a[i] * b[a[i]]);
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
