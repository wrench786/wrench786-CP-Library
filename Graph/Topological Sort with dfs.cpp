#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
#define mod2 998244353

const int inf = 1e9+7;
const int N = 1e5+7;

map<int,vector<int>>g;
int vis[N];
vector<int>dfs_end;

void dfs(int u){
    vis[u] = true;

    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    dfs_end.push_back(u);
}

void solve(){
    int n,m;
    while(cin>>n>>m && n+m){
        g.clear();
        memset(vis,0,sizeof vis);
        dfs_end.clear();

        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }

        reverse(dfs_end.begin(),dfs_end.end());

        for(auto x:dfs_end){
            cout<<x<<" ";
        }
        cout<<nn;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;

    //int cases=0;
    while(tc--){
        //cout<<"Scenario #"<<++cases<<":"<<nn;
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}