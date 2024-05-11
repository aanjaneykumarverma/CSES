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
    vector<int> compressed;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i].first >> t[i].second;
        compressed.push_back(t[i].first);
        compressed.push_back(t[i].second);
    }
    sort(compressed.begin(), compressed.end());
    int m = compressed.size();
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int a = lower_bound(compressed.begin(), compressed.end(), t[i].first) - compressed.begin();
        int b = lower_bound(compressed.begin(), compressed.end(), t[i].second) - compressed.begin();
        ++cnt[a];
        --cnt[b + 1];
    }
    for (int i = 1; i <= m; ++i)
        cnt[i] += cnt[i - 1];
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}