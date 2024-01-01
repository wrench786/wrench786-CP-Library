#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e5+7;
vector<int>g[N];
int par[N],s,e;
bool cycle, vis[N];
vector<int>path;

void dfs(int u, int p){
    //if(cycle) return;

    vis[u] = 1;
    par[u] = p;

    for(auto v:g[u]){
        //if(cycle) return;
        
        if(!vis[v]){
            dfs(v,u);
        }
        else if(v!=p && !cycle){
            cycle = true;
            int x = u;
            while(x!=v){
                path.push_back(x);
                x = par[x];
            }
            path.push_back(v);
            path.push_back(u);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cycle = false;

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);   
    }
    if(cycle){
        cout<<path.size()<<nn;
        for(auto x:path){
            cout<<x<<" ";
        }
        cout<<nn;
        return;
    }
    else cout<<"IMPOSSIBLE"<<nn;
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