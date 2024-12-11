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

    for (int i = 0; i < 25; i++)
    {
        vector<long long> temp;
        for (auto &x : a)
        {
            long long l = numDigits(x);
            if (x == 0)
                temp.push_back(1);
            else if (l % 2 == 0)
            {
                string num = to_string(x);
                temp.push_back(stoll(num.substr(0, l / 2)));
                temp.push_back(stoll(num.substr(l / 2)));
            }
            else
                temp.push_back(x * 2024);
        }

        a = temp;
        // for (auto &x : temp)
        //     cout << x << " ";
        // cout << endl;
    }
    cout << a.size() << endl;
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
