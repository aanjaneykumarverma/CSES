#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i].second >> t[i].first;
    sort(t.begin(), t.end());
    int ans = 0;
    int endi = -1;
    for (int i = 0; i < n; ++i)
    {
        if (endi <= t[i].second)
        {
            endi = t[i].first;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}