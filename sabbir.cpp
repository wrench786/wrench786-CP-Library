#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MX = 1e3 + 5;
vector<ll> adj[MX], path;
ll n, s, d;
bool mark[MX], yo;
void dfs(ll u) {
  if (mark[u] || yo) return;
  path.push_back(u);
  mark[u] = true;
  if (u == d)yo = true;
  for (auto it : adj[u]) {
    dfs(it);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s >> d;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      ll x; cin >> x;
      if (x) adj[i].push_back(j);
    }
  }
  dfs(s);
  if (yo) {
    cout << path.size() << endl;
    for (auto it : path)cout << it << " ";
    cout << endl;
  }
  else cout << -1 << endl;
  return 0;
}