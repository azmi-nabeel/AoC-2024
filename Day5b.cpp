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
    set<pair<int, int>> st;

    string line;

    while (getline(cin, line))
    {
        if (line.size() <= 2)
            break;
        vector<string> tokens;
        tokens = splitStrings(line, '|');
        vector<int> temp;
        for (auto &x : tokens)
            temp.push_back(stoi(x));
        st.insert({temp[0], temp[1]});
    }

    int ans = 0;

    while (getline(cin, line))
    {
        vector<string> tokens;
        tokens = splitStrings(line, ',');
        vector<int> temp;
        for (auto &x : tokens)
            temp.push_back(stoi(x));
        int sz = temp.size();
        bool f = 1;
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (st.count({temp[j], temp[i]}))
                {
                    swap(temp[i], temp[j]);
                    f = 0;
                }
            }
        }
        if (!f)
            ans += temp[(sz / 2)];
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
