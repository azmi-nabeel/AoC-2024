#include <bits/stdc++.h>

const long long shift = 10000000000000;

using namespace std;

long long calc(long long Ax, long long Ay, long long Bx, long long By, long long Tx, long long Ty)
{
    long long det = (Ax * By) - (Ay * Bx);
    long long det1 = (Bx * Ty) - (By * Tx);
    long long det2 = (Ax * Ty) - (Ay * Tx);
    det1 = -det1;
    if (det1 % det == 0 && det2 % det == 0)
    {
        return (3 * (det1 / det)) + (det2 / det);
    }
    else
        return 0;
}

void solve()
{
    string line;

    long long Ax = 0, Ay = 0;
    long long Bx = 0, By = 0;

    long long Tx = 0, Ty = 0;

    long long i = 0, ans = 0;

    while (getline(cin, line))
    {
        if (i == 0)
        {
            long long curr = 0;
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
            long long curr = 0;
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
            long long curr = 0;
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
            Tx += shift;
            Ty += shift;
            ans += calc(Ax, Ay, Bx, By, Tx, Ty);
        }
        i = (i + 1) % 4;
    }
    Tx += shift;
    Ty += shift;
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
