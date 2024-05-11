#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; ++i)
    {
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }
    for (int i = 0; i < m; ++i)
    {
        int price;
        cin >> price;
        if (tickets.empty())
        {
            cout << -1 << "\n";
            continue;
        }
        auto it = tickets.upper_bound(price);
        if (it != tickets.begin())
            --it;
        if (*it <= price)
        {
            cout << *it << "\n";
            tickets.erase(it);
        }
        else
            cout << -1 << "\n";
    }
    return 0;
}