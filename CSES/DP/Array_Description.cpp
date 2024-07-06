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
    ll n, m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    // dp[i][j] ways to reach arr[i] 's value equal j
    vector<vi> dp(n, vi(m + 1, 0));
    if (a[0] != 0)
        dp[0][a[0]] = 1;
    else
        FORE(i, 1, m)
    dp[0][i] = 1;

    FOR(i, 1, n)
    {
        if (a[i] == 0)
        {
            FORE(j, 1, m)
            {
                if (j - 1 >= 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j + 1 <= m)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        else
        {
            ll j = a[i];
            if (j - 1 >= 1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j + 1 <= m)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    ll totWays = 0;
    FORE(i, 1, m)
    {
        totWays = (totWays + dp[n - 1][i]) % MOD;
    }
    cout << totWays << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    solve();
}