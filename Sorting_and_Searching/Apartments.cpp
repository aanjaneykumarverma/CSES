#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    multiset<int> apartments;
    for (int i = 0; i < n; ++i)
        cin >> applicants[i];
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        apartments.insert(x);
    }
    sort(applicants.begin(), applicants.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (apartments.empty())
            break;
        auto it = apartments.lower_bound(applicants[i] - k);
        if (it == apartments.end())
            --it;
        if (abs(*it - applicants[i]) <= k)
        {
            ++ans;
            apartments.erase(it);
        }
    }
    cout << ans;
}