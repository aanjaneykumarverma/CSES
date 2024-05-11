#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    map<long long, long long> cnt;
    cnt[0] = 1;
    long long ans = 0;
    long long curSum = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        curSum += a;
        ans += cnt[curSum - x];
        ++cnt[curSum];
    }
    cout << ans;
    return 0;
}
