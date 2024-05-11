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
    multiset<int> p;
    for (int i = 0; i < n; ++i)
    {
        int pi;
        cin >> pi;
        p.insert(pi);
    }
    int ans = 0;
    while (!p.empty())
    {
        int p1 = *(--p.end());
        p.erase(--p.end());
        if (!p.empty())
        {
            auto it = p.lower_bound(x - p1);
            if (it == p.end())
                --it;
            if (*it > x - p1 && it != p.begin())
                --it;
            int p2 = *it;
            if (p1 + p2 <= x)
                p.erase(it);
        }
        ++ans;
    }
    cout << ans;
    return 0;
}