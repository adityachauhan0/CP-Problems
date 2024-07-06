#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7, INF = 1e9;
const ll INFLL = 1e18;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define sz(x) (int)x.size()
#define vi vector<ll>
#define vp vector<pair<ll, ll>>
#define make_unique(v) \
    sort(all(v));      \
    v.erase(unique(all(v)), v.end())

template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <int D, typename T>
struct vt : public vector<vt<D - 1, T>>
{
    template <typename... Args>
    vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}
};
template <typename T>
struct vt<1, T> : public vector<T>
{
    vt(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
void solve()
{
    int n;
    cin >> n;

    // Check if the sum of numbers from 1 to n is even
    ll total_sum = (ll)n * (n + 1) / 2;
    if (total_sum % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }

    ll target_sum = total_sum / 2;

    // dp[i][j] represents the number of ways to form sum j using numbers from 1 to i
    vector<vector<ll>> dp(n + 1, vector<ll>(target_sum + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target_sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    // The final answer is dp[n][target_sum] / 2 because each valid partition is counted twice
    cout << dp[n][target_sum] * ((MOD + 1) / 2) % MOD << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    solve();
}