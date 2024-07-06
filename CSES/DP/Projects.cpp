#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Project
{
    ll start, end, profit;
};

void solve()
{
    ll n;
    cin >> n;
    vector<Project> projects(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> projects[i].start >> projects[i].end >> projects[i].profit;
    }

    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b)
         { return a.end < b.end; });

    vector<ll> dp(n);
    dp[0] = projects[0].profit;

    vector<ll> ends(n);
    for (int i = 0; i < n; i++)
    {
        ends[i] = projects[i].end;
    }

    for (int i = 1; i < n; i++)
    {
        ll profit = projects[i].profit;

        // find last non overlapping project
        auto it = lower_bound(ends.begin(), ends.begin() + i, projects[i].start);
        if (it != ends.begin())
        {
            int j = prev(it) - ends.begin();
            profit += dp[j];
        }

        dp[i] = max(profit, dp[i - 1]);
    }

    cout << dp[n - 1] << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
}