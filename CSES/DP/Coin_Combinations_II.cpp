#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    cin >> a;
    vi dp(x + 1);
    dp[0] = 1;
    FOR(i, 0, n)
    {
        FORE(sum, a[i], x)
        {
            dp[sum] = (dp[sum] + dp[sum - a[i]]) % MOD;
        }
    }
    cout << dp[x] << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
}