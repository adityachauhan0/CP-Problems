#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> piles;
    for (ll x : a)
    {
        auto it = lower_bound(piles.begin(), piles.end(), x);
        if (it == piles.end())
            piles.push_back(x);
        else
            *it = x;
    }

    cout << piles.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}