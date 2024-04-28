#include <bits/stdc++.h>
#define MOD (1000000000 + 7)
#define ll long long
using namespace std;
const int N = 20;
ll dp[N][10][2][2];
void clean()
{
    memset(dp, -1, sizeof(dp));
}
ll solve(string &num, int n, int x, int lz, int tight)
{
    if (!n)
        return 1;

    if (x != -1 && dp[n][x][lz][tight] != -1)
        return dp[n][x][lz][tight];

    int bound = tight ? (num[num.length() - n] - '0') : 9;

    ll ans = 0;
    for (int digit = 0; digit <= bound; ++digit)
    {
        if (digit == x && !lz)
            continue;
        ans += solve(num, n - 1, digit, lz && !digit, tight && (digit == bound));
    }
    return dp[n][x][lz][tight] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a, b;
    cin >> a >> b;
    clean();
    string str_a = to_string(a - 1);
    ll res_a = solve(str_a, str_a.size(), -1, 1, 1);
    clean();
    string str_b = to_string(b);
    ll res_b = solve(str_b, str_b.size(), -1, 1, 1);
    cout << res_b - res_a;
}