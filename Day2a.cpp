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

bool check1(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] > 3 || v[i] - v[i - 1] < 1)
            return 0;
    }
    return 1;
}

bool check2(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] - v[i] > 3 || v[i - 1] - v[i] < 1)
            return 0;
    }
    return 1;
}

void solve()
{
    vector<vector<int>> a;

    string line;

    while (getline(cin, line))
    {
        vector<string> tokens;
        tokens = splitStrings(line, ' ');
        vector<int> temp;
        for (auto &x : tokens)
            temp.push_back(stoi(x));
        a.push_back(temp);
    }

    int ans = 0;
    for (auto &v : a)
    {
        if (check1(v) || check2(v))
            ans++;
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
