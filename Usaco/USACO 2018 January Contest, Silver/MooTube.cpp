#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 5000+7,inf = 1e9+7;
bool vis[N];
vector<pair<int,int>> g[N];
int d[N];

void dfs(int u){
    vis[u] = 1;

    for(auto x:g[u]){
        int v = x.first;
        int w = x.second;

        if(!vis[v]){
            d[v] = min(d[u],w);
            dfs(v);
        }
    }
}


void solve(){
    int n,q;
    cin>>n>>q;

    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        d[i] = inf;
    }

    while(q--){
        int k,node;
        cin>>k>>node;

        dfs(node);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+= (d[i]>=k);
            
            vis[i]=0;
            d[i] = inf;
        }
        cout<<ans-1<<nn;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}