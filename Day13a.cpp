#include <bits/stdc++.h>

using namespace std;

int calc(int Ax, int Ay, int Bx, int By, int Tx, int Ty)
{
    int ans = INT_MAX;
    for (int i = 0; i <= 100; i++)
    {
        int dx = Tx - (i * Ax);
        int dy = Ty - (i * Ay);
        if (dx < 0 || dy < 0)
            break;
        if ((dx % Bx == 0) && (dy % By == 0) && (dx / Bx) == (dy / By))
        {
            ans = min(ans, (i * 3) + (dy / By));
        }
        // if (i == 80)
        // {
        //     cout << dx << " " << dy << " " << ans << endl;
        // }
    }
    return ans == INT_MAX ? 0 : ans;
}

void solve()
{
    string line;

    int Ax = 0, Ay = 0;
    int Bx = 0, By = 0;

    int Tx = 0, Ty = 0;

    int i = 0, ans = 0;

    while (getline(cin, line))
    {
        if (i == 0)
        {
            int curr = 0;
            for (auto &c : line)
            {
                if (isdigit(c))
                {
                    curr = (curr * 10) + (c - '0');
                }
                else
                {
                    if (curr > 0)
                        Ax = curr;
                    curr = 0;
                }
            }
            Ay = curr;
        }
        else if (i == 1)
        {
            int curr = 0;
            for (auto &c : line)
            {
                if (isdigit(c))
                {
                    curr = (curr * 10) + (c - '0');
                }
                else
                {
                    if (curr > 0)
                        Bx = curr;
                    curr = 0;
                }
            }
            By = curr;
        }
        else if (i == 2)
        {
            int curr = 0;
            for (auto &c : line)
            {
                if (isdigit(c))
                {
                    curr = (curr * 10) + (c - '0');
                }
                else
                {
                    if (curr > 0)
                        Tx = curr;
                    curr = 0;
                }
            }
            Ty = curr;
        }
        else
        {
            ans += calc(Ax, Ay, Bx, By, Tx, Ty);
        }
        i = (i + 1) % 4;
    }
    ans += calc(Ax, Ay, Bx, By, Tx, Ty);
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
