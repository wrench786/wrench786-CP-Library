#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;

map<int,vector<pair<int,int>>>g;
bool vis[N];
ll depth[N], depth_start[N], depth_end[N];
ll start,last,mx=0;

void dfs(int u, int par, int ww){
    vis[u] = true;
    depth[u] = depth[par]+ww;
    if(depth[u]>mx){
        mx = depth[u];
        start = u;
    }

    for(auto x:g[u]){
        int v = x.first;
        int w = x.second;

        if(!vis[v]){
            dfs(v,u,w);
        }
    }
}

void dfs2(int u, int par, int ww){
    vis[u] = true;
    depth_start[u] = depth_start[par]+ww;
    //cout<<depth_start[u]<<nn;
    if(depth_start[u]>mx){
        mx = depth_start[u];
        last = u;
    }
    for(auto x:g[u]){
        // cout<<"sd"<<nn;
        int v = x.first;
        int w = x.second;

        if(!vis[v]){
            dfs2(v,u,w);
        }
    }
}

void dfs3(int u, int par, int ww){
    vis[u] = true;
    depth_end[u] = depth_end[par]+ww;

    for(auto x:g[u]){
        int v = x.first;
        int w = x.second;

        if(!vis[v]){
            dfs3(v,u,w);
        }
    }
}

void solve(){
    int n;
    cin>>n;

    g.clear();
    memset(vis,0,sizeof vis);
    memset(depth,0,sizeof depth);
    memset(depth_start,0,sizeof depth_start);
    memset(depth_end,0,sizeof depth_end);

    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dfs(1,0,0);

    memset(vis,0,sizeof vis);
    mx=0;
    dfs2(start,0,0);
    
    memset(vis,0,sizeof vis);
    dfs3(last,0,0);

    for(int i=1;i<=n;i++){
        if(i>1) cout<<" ";
        cout<<max(depth_start[i],depth_end[i]);
    }
    cout<<nn;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}