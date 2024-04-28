#include <bits/stdc++.h>
#define INF 1000001
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n;
    bitset<INF> sums;
    sums[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        sums |= (sums << c);
    }
    cout << sums.count() - 1 << "\n";
    for (int i = 1; i < INF; ++i)
        if (sums[i])
            cout << i << ' ';
}