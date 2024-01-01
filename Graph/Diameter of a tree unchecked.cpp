#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;

map<int,vector<int>>g;
int d[N];
int mx,s,ans;

void dfs(int u, int p){
    d[u] = d[p]+1;
    if(d[u]>mx){
        mx = d[u];
        s = u;
    }
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
}

void dfs2(int u, int p){
    d[u] = d[p]+1;
    ans = max(ans, d[u]-1);

    for(auto v:g[u]){
        if(v!=p){
            dfs2(v,u);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    //memset(d,0,sizeof d);
    dfs2(s,0);

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
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}