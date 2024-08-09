#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const ll MX = 1e5 + 5, N = 15, Ran = 2e5 + 5;
ll n, m, d, k, A[N][MX], dp[N][MX], T[4 * Ran];
vector<ll> res;

void update(ll node, ll a, ll b, ll x, ll y) {
    if (a == b && a == x) {
        T[node] = y;
        return;
    }
    if (x > b || a > x) return;
    ll mid = (a + b) / 2, left = (node << 1), right = left + 1;
    update(left, a, mid, x, y);
    update(right, mid + 1, b, x, y);
    T[node] = max(T[left], T[right]);
}

ll query(ll node, ll a, ll b, ll x, ll y) {
    if (x > b || a > y) return 0LL;
    if (a >= x && y >= b) return T[node];
    ll mid = (a + b) / 2, left = (node << 1), right = left + 1;
    return max(query(left, a, mid, x, y), query(right, mid + 1, b, x, y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> d;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        memset(T, 0, sizeof(T));
        ll cur = 0;
        for (ll j = 1; j <= m; j++) {
            ll left = max(1LL, A[i][j] - k), right = A[i][j] + k;
            dp[i][j] = query(1, 1, Ran, left, right) + A[i][j];
            update(1, 1, Ran, A[i][j], dp[i][j]);
            cur = max(cur, dp[i][j]);
        }
        res.push_back(cur);
    }
    ll sub = (1LL << n);
    bool ok = false;
    for (ll i = 1; i < sub; i++) {
        ll sm = 0;
        for (ll j = 0; j < n; j++) {
            if ((i >> j) & 1LL) {
                sm += res[j];
            }
        }
        if (sm == d) {
            ok = true;
            cout << "YES" << endl;
            for (ll j = 0; j < n; j++) {
                if ((i >> j) & 1LL) {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
            break;
        }
    }
    if (!ok)cout << "NO" << endl;
    return 0;
}
