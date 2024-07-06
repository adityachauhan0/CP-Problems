#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, INF = 1e9;
const ll INFLL = 1e18;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORE(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (ll i = (a); i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define sz(x) (ll) x.size()
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

template <ll D, typename T>
struct vt : public vector<vt<D - 1, T>>
{
    template <typename... Args>
    vt(ll n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}
};
template <typename T>
struct vt<1, T> : public vector<T>
{
    vt(ll n = 0, const T &val = T()) : vector<T>(n, val) {}
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
vi a;
ll n;
vector<vi> dp;
ll maxScore(ll i, ll j)
{
    // basecase
    if (i > n - 1 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = a[i];
    if (j - i == 1)
        return dp[i][j] = max(a[i], a[j]);

    ll pick_front = a[i] + min(maxScore(i + 2, j), maxScore(i + 1, j - 1));
    ll pick_back = a[j] + min(maxScore(i, j - 2), maxScore(i + 1, j - 1));
    return dp[i][j] = max(pick_front, pick_back);
}
void solve()
{
    cin >> n;
    a.resize(n);
    cin >> a;
    dp.assign(n, vi(n, -1));
    cout << maxScore(0, n - 1) << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    solve();
}